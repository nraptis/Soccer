//
//  Builder_Seeder.cpp
//  MeanMachine
//
//  Created by nicholas on 5/23/26.
//

#include "Builder_Seeder.hpp"
#include "GKDF.hpp"
#include "GTwistExpander.hpp"
#include "GFarm.hpp"

#include "ResidualBucket.hpp"

#include "GSeedRunSeed.hpp"
#include "GSeedRunKeyBox.hpp"

#include "GRunMatrixDiffusion.hpp"
#include "Random.hpp"

#include "stdafx.hpp"

#include <array>
#include <sstream>
#include <utility>

namespace {

const char *PhaseSubWordName(const TwistDomain pDomain) {
    switch (pDomain) {
        case TwistDomain::kKeyRotateA: return "KeyRotateA";
        case TwistDomain::kKeyRotateB: return "KeyRotateB";
        case TwistDomain::kKeySpawnA: return "KeySpawnA";
        case TwistDomain::kKeySpawnB: return "KeySpawnB";
        case TwistDomain::kSeed: return "Seed";
        case TwistDomain::kTwist: return "Twist";
        default:
            return "Invalid";
    }
}

const char *DomainDescription(const TwistDomain pDomain) {
    switch (pDomain) {
        case TwistDomain::kKeyRotateA: return "key a rotate";
        case TwistDomain::kKeyRotateB: return "key b rotate";
        case TwistDomain::kKeySpawnA: return "key a spawn";
        case TwistDomain::kKeySpawnB: return "key b spawn";
        case TwistDomain::kSeed: return "seed";
        case TwistDomain::kTwist: return "twist";
        default: return "invalid";
    }
}

std::string UInt64Literal(const std::uint64_t pValue) {
    std::ostringstream aStream;
    aStream << "0x" << std::uppercase << std::hex << pValue << "ULL";
    return aStream.str();
}

std::string KeyLaneMacroPlaceholder(
    const std::size_t pLogicalKeyIndex,
    const char pLaneLetter) {
    const char aKeyBoxName =
        (pLogicalKeyIndex < 8U) ? 'A' : 'B';
    const char aKeyRowName =
        static_cast<char>('A' + (pLogicalKeyIndex % 8U));
    return std::string("KEY_LANE_KEY_") + aKeyBoxName + "_" +
        aKeyRowName + "_AetherLane" + pLaneLetter;
}

void AddKDFStateDeclarations(TwistProgramBranch &pBranch) {
    static constexpr std::array<const char *, 13> kStateNames = {
        "aIngress",
        "aCarry",
        "aWandererA",
        "aWandererB",
        "aWandererC",
        "aWandererD",
        "aWandererE",
        "aWandererF",
        "aWandererG",
        "aWandererH",
        "aWandererI",
        "aWandererJ",
        "aWandererK",
    };

    for (const char *aStateName : kStateNames) {
        pBranch.AddLine(
            std::string("std::uint64_t ") + aStateName + " = " +
            UInt64Literal(Random::Get64High()) + ";"
        );
    }
}

void AddSecretDerivationHeader(TwistProgramBranch &pBranch) {
    pBranch.AddLine("////////////////////////////////////////////////////////");
    pBranch.AddLine("//");
    pBranch.AddLine("// Secret material derivation, across 6 domains.");
    pBranch.AddLine("//");
}

void AddDomainHeader(TwistProgramBranch &pBranch,
                     const std::size_t pDomainIndex,
                     const std::size_t pDomainCount,
                     const TwistDomain pDomain) {
    pBranch.AddLine(
        "// Domain " + std::to_string(pDomainIndex + 1U) + " of " +
        std::to_string(pDomainCount) + ", " + DomainDescription(pDomain) + ":"
    );
    pBranch.AddLine("//");
}

void AddFarmStatements(TwistProgramBranch &pBranch,
                       const std::vector<GStatement> &pStatements,
                       const bool pAddTrailingBlankLine = true) {
    for (std::size_t aStatementIndex = 0U;
         aStatementIndex < pStatements.size();
        ++aStatementIndex) {
        if (aStatementIndex > 0U) {
            pBranch.AddLine("");
        }
        pBranch.AddLine(pStatements[aStatementIndex].mRawLine);
    }
    if (pAddTrailingBlankLine) {
        pBranch.AddLine("");
    }
}

void AddSeedMatrixDomainWordLines(TwistProgramBranch &pBranch) {
    const std::string aConstants =
        "pWorkSpace->mDomainBundle.mSeedConstants";

    pBranch.AddLine("std::uint64_t aDomainWordMatrixSelectA = " + aConstants + ".mMatrixSelectA;");
    pBranch.AddLine("std::uint64_t aDomainWordMatrixSelectB = " + aConstants + ".mMatrixSelectB;");
    pBranch.AddLine("");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixUnrollA = " + aConstants + ".mMatrixUnrollA;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixUnrollB = " + aConstants + ".mMatrixUnrollB;");
    pBranch.AddLine("");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixArgA = " + aConstants + ".mMatrixArgA;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixArgB = " + aConstants + ".mMatrixArgB;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixArgC = " + aConstants + ".mMatrixArgC;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixArgD = " + aConstants + ".mMatrixArgD;");
}

bool BuildSeedStage(TwistProgramBranch &pBranch,
                    const GSeedRunStageConfig &pConfig,
                    const bool pUseNonces,
                    const bool pEmitNoncePrologue,
                    const char *pStageName,
                    std::string *pErrorMessage) {
    GSeedRunSeed aRunner(pConfig,
                         pUseNonces,
                         pEmitNoncePrologue);
    if (!aRunner.Plan(pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = std::string("error on ") + pStageName + ".Plan for seed\n" + *pErrorMessage;
        }
        return false;
    }

    if (!aRunner.Build(pBranch, pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = std::string("Builder_Seeder::Build failed to bake ") + pStageName + ":\n" + *pErrorMessage;
        }
        return false;
    }

    return true;
}

} // namespace

bool Builder_Seeder::Build(GTwistExpander *pExpander,
                           ResidualBucket &pResidualBucket,
                           std::string *pErrorMessage) {

    if (pExpander == nullptr) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = "Builder_Seeder::Build received null expander";
        }
        return false;
    }

    std::vector<GSymbol> aIceLanes;
    aIceLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kIceLaneA));
    aIceLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kIceLaneB));
    aIceLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kIceLaneC));
    aIceLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kIceLaneD));

    std::vector<GSymbol> aVaporLanes;
    aVaporLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kVaporLaneA));
    aVaporLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kVaporLaneB));
    aVaporLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kVaporLaneC));
    aVaporLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kVaporLaneD));

    std::vector<GSymbol> aCelestialLanes;
    aCelestialLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kCelestialLaneA));
    aCelestialLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kCelestialLaneB));
    aCelestialLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kCelestialLaneC));
    aCelestialLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kCelestialLaneD));

    std::vector<TwistDomain> aDomains;
    aDomains.push_back(TwistDomain::kKeyRotateA);
    aDomains.push_back(TwistDomain::kKeyRotateB);
    aDomains.push_back(TwistDomain::kKeySpawnA);
    aDomains.push_back(TwistDomain::kKeySpawnB);
    aDomains.push_back(TwistDomain::kTwist);
    aDomains.push_back(TwistDomain::kSeed);

    AddKDFStateDeclarations(pExpander->mSeed);
    pExpander->mSeed.AddLine("");

    AddSecretDerivationHeader(pExpander->mSeed);

    for (std::size_t aDomainIndex = 0U; aDomainIndex < aDomains.size(); ++aDomainIndex) {
        const std::string aDomainPartialName = PhaseSubWordName(aDomains[aDomainIndex]);

        AddDomainHeader(pExpander->mSeed,
                        aDomainIndex,
                        aDomains.size(),
                        aDomains[aDomainIndex]);

        std::vector<GStatement> aStatementsKDFA;
        GKDF_A aKDF_A;
        if (!aKDF_A.Bake(aDomains[aDomainIndex],
                         GKDFMaterialBundle::kInbuilt,
                         &aStatementsKDFA,
                         pErrorMessage)) {
            if (pErrorMessage != nullptr) {
                *pErrorMessage = "Builder_Seeder::Build failed to bake inbuilt KDF:\n" + *pErrorMessage;
            }
            return false;
        }
        for (const GStatement &aStatement : aStatementsKDFA) {
            if (!aStatement.IsRawLine()) {
                continue;
            }
            pExpander->mSeed.AddLine(aStatement.mRawLine);
        }
        pExpander->mSeed.AddLine("");

        std::vector<GStatement> aStatementsFarmA;
        GFarm aFarm;
        if (!aFarm.BakeEphemeralA(aIceLanes[0],
                                  aIceLanes[1],
                                  aIceLanes[2],
                                  aIceLanes[3],
                                  aDomainPartialName,
                                  &aStatementsFarmA,
                                  pErrorMessage)) {
            if (pErrorMessage != nullptr) {
                *pErrorMessage = "Builder_Seeder::Build failed to bake farm after KDFA:\n" + *pErrorMessage;
            }
            return false;
        }

        AddFarmStatements(pExpander->mSeed, aStatementsFarmA);

        std::vector<GStatement> aStatementsKDFB;
        GKDF_B aKDF_B;
        if (!aKDF_B.Bake(aDomains[aDomainIndex],
                         GKDFMaterialBundle::kEphemeralA,
                         &aStatementsKDFB,
                         pErrorMessage)) {
            if (pErrorMessage != nullptr) {
                *pErrorMessage = "Builder_Seeder::Build failed to bake inbuilt KDF_B:\n" + *pErrorMessage;
            }
            return false;
        }
        for (const GStatement &aStatement : aStatementsKDFB) {
            pExpander->mSeed.AddLine(aStatement.mRawLine);
        }
        pExpander->mSeed.AddLine("");

        //
        // KDF_B vapor lanes -> ephemeral-B domain material.
        //
        std::vector<GStatement> aStatementsFarmAfterKDFB;
        if (!aFarm.BakeEphemeralB(aVaporLanes[0],
                                  aVaporLanes[1],
                                  aVaporLanes[2],
                                  aVaporLanes[3],
                                  aDomainPartialName,
                                  &aStatementsFarmAfterKDFB,
                                  pErrorMessage)) {
            if (pErrorMessage != nullptr) {
                *pErrorMessage =
                    "Builder_Seeder::Build failed to derive ephemeral-B "
                    "material after KDF_B:\n" + *pErrorMessage;
            }
            return false;
        }
        AddFarmStatements(pExpander->mSeed, aStatementsFarmAfterKDFB);

        std::vector<GStatement> aStatementsKDFC;
        GKDF_C aKDF_C;
        if (!aKDF_C.Bake(aDomains[aDomainIndex],
                         GKDFMaterialBundle::kEphemeralB,
                         &aStatementsKDFC,
                         pErrorMessage)) {
            if (pErrorMessage != nullptr) {
                *pErrorMessage = "Builder_Seeder::Build failed to bake KDF_C:\n" + *pErrorMessage;
            }
            return false;
        }
        for (const GStatement &aStatement : aStatementsKDFC) {
            pExpander->mSeed.AddLine(aStatement.mRawLine);
        }
        pExpander->mSeed.AddLine("");

        //
        // KDF_C celestial lanes -> final workspace domain material.
        //
        std::vector<GStatement> aStatementsFarmAfterKDFC;
        if (!aFarm.BakeWorkspace(aCelestialLanes[0],
                                 aCelestialLanes[1],
                                 aCelestialLanes[2],
                                 aCelestialLanes[3],
                                 aDomainPartialName,
                                 &aStatementsFarmAfterKDFC,
                                 pErrorMessage)) {
            if (pErrorMessage != nullptr) {
                *pErrorMessage =
                    "Builder_Seeder::Build failed to derive final workspace "
                    "material after KDF_C:\n" + *pErrorMessage;
            }
            return false;
        }
        AddFarmStatements(pExpander->mSeed,
                          aStatementsFarmAfterKDFC,
                          false);
        pExpander->mSeed.AddLine("//");
    }

    pExpander->mSeed.AddLine("////////////////////////////////////////////////////////");
    pExpander->mSeed.AddLine("");
    pExpander->mSeed.AddLine("");
    pExpander->mSeed.AddLine("////////////////////////////////////////////////////////");
    pExpander->mSeed.AddLine("//");
    pExpander->mSeed.AddLine("// Main seed loops");
    pExpander->mSeed.AddLine("//");

    return Build_PostKDF(pExpander,
                         pResidualBucket,
                         pErrorMessage);

}

bool Builder_Seeder::Build_PostKDF(GTwistExpander *pExpander,
                                   ResidualBucket &pResidualBucket,
                                   std::string *pErrorMessage) {
    if (pExpander == nullptr) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = "Builder_Seeder::Build_PostKDF received null expander";
        }
        return false;
    }

    //
    // Seed lane plan
    //
    // A: Source + Nonce -> Water A-B + Spirit A-D
    // B: Spirit A-D -> Water C-D + Earth A-D
    //    diffuse Earth -> Ice; entropy Water
    //
    // C: Ice A-D -> Crystal A-B + Lightning A-D
    // D: Lightning A-D -> Crystal C-D + Wind A-D
    //    diffuse Wind -> Vapor; entropy Crystal
    //
    // E: Vapor A-D -> Plasma A-B + Aether A-D
    // F: Aether A-D -> Plasma C-D + Shadow A-D
    //    diffuse Shadow -> Celestial; entropy Plasma
    //
    // G: Celestial A-D -> Lightning A-D
    //
    // Twist-shaped ending:
    // H: Lightning A-D -> Water A-D
    //    diffuse Water -> Spirit; entropy Lightning
    // I: Spirit A-D -> Earth A-D
    //    diffuse Earth -> Ice; entropy Spirit
    // J: Ice A-D -> Crystal A-D
    //    reverse Ice -> Fire
    //

    const GSeedRunSeedConfig::SeedStageConfigs aBuiltStageConfigs =
        GSeedRunSeedConfig::MakeSeedConfig(true,
                                           pResidualBucket,
                                           pExpander->mControlCandidateIndex);
    std::vector<GSeedRunStageConfig> aStageConfigs(
        aBuiltStageConfigs.begin(),
        aBuiltStageConfigs.end());
    pExpander->mSeedStageConfigs = aStageConfigs;
    pExpander->mSeedMatrixDomains.assign(5U, TwistDomain::kSeed);

    std::vector<GSymbol> aEarthLanes;
    aEarthLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kEarthLaneA));
    aEarthLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kEarthLaneB));
    aEarthLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kEarthLaneC));
    aEarthLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kEarthLaneD));

    std::vector<GSymbol> aWaterLanes;
    aWaterLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kWaterLaneA));
    aWaterLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kWaterLaneB));
    aWaterLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kWaterLaneC));
    aWaterLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kWaterLaneD));

    std::vector<GSymbol> aWindLanes;
    aWindLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kWindLaneA));
    aWindLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kWindLaneB));
    aWindLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kWindLaneC));
    aWindLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kWindLaneD));

    std::vector<GSymbol> aIceLanes;
    aIceLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kIceLaneA));
    aIceLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kIceLaneB));
    aIceLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kIceLaneC));
    aIceLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kIceLaneD));

    std::vector<GSymbol> aLightningLanes;
    aLightningLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kLightningLaneA));
    aLightningLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kLightningLaneB));
    aLightningLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kLightningLaneC));
    aLightningLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kLightningLaneD));

    std::vector<GSymbol> aPlasmaLanes;
    aPlasmaLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kPlasmaLaneA));
    aPlasmaLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kPlasmaLaneB));
    aPlasmaLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kPlasmaLaneC));
    aPlasmaLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kPlasmaLaneD));

    std::vector<GSymbol> aShadowLanes;
    aShadowLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kShadowLaneA));
    aShadowLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kShadowLaneB));
    aShadowLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kShadowLaneC));
    aShadowLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kShadowLaneD));

    std::vector<GSymbol> aCelestialLanes;
    aCelestialLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kCelestialLaneA));
    aCelestialLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kCelestialLaneB));
    aCelestialLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kCelestialLaneC));
    aCelestialLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kCelestialLaneD));

    std::vector<GSymbol> aSpiritLanes;
    aSpiritLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kSpiritLaneA));
    aSpiritLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kSpiritLaneB));
    aSpiritLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kSpiritLaneC));
    aSpiritLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kSpiritLaneD));

    std::vector<GSymbol> aCrystalLanes;
    aCrystalLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kCrystalLaneA));
    aCrystalLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kCrystalLaneB));
    aCrystalLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kCrystalLaneC));
    aCrystalLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kCrystalLaneD));

    std::vector<GSymbol> aAetherLanes;
    aAetherLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kAetherLaneA));
    aAetherLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kAetherLaneB));
    aAetherLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kAetherLaneC));
    aAetherLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kAetherLaneD));

    std::vector<GSymbol> aVaporLanes;
    aVaporLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kVaporLaneA));
    aVaporLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kVaporLaneB));
    aVaporLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kVaporLaneC));
    aVaporLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kVaporLaneD));

    for (std::size_t i = 0U; i < 2U; ++i) {
        const std::string aStageName =
            "GSeedRunSeed_" + std::string(1, static_cast<char>('A' + i));
        if (!BuildSeedStage(pExpander->mSeed,
                            aStageConfigs[i],
                            true,
                            false,
                            aStageName.c_str(),
                            pErrorMessage)) {
            return false;
        }
    }

    AddSeedMatrixDomainWordLines(pExpander->mSeed);

    GRunMatrixDiffusionConfig aDiffusionA;
    aDiffusionA.mInputA = aEarthLanes[0];
    aDiffusionA.mInputB = aEarthLanes[1];
    aDiffusionA.mInputC = aEarthLanes[2];
    aDiffusionA.mInputD = aEarthLanes[3];
    aDiffusionA.mOutputA = aIceLanes[0];
    aDiffusionA.mOutputB = aIceLanes[1];
    aDiffusionA.mOutputC = aIceLanes[2];
    aDiffusionA.mOutputD = aIceLanes[3];
    aDiffusionA.mEntropyA = aWaterLanes[0];
    aDiffusionA.mEntropyB = aWaterLanes[1];
    aDiffusionA.mEntropyC = aWaterLanes[2];
    aDiffusionA.mEntropyD = aWaterLanes[3];

    GBatch aBatchDiffusionA;
    if (!GRunMatrixDiffusion::Bake(aDiffusionA,
                                   &aBatchDiffusionA,
                                   pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = std::string("error on first matrix diffusion for seed: ") + *pErrorMessage;
        }
        return false;
    }
    pExpander->mSeed.AddBatch(aBatchDiffusionA);

    for (std::size_t i = 2U; i < 4U; ++i) {
        const std::string aStageName =
            "GSeedRunSeed_" + std::string(1, static_cast<char>('A' + i));
        if (!BuildSeedStage(pExpander->mSeed,
                            aStageConfigs[i],
                            true,
                            false,
                            aStageName.c_str(),
                            pErrorMessage)) {
            return false;
        }
    }

    GRunMatrixDiffusionConfig aDiffusionB;
    aDiffusionB.mInputA = aWindLanes[0];
    aDiffusionB.mInputB = aWindLanes[1];
    aDiffusionB.mInputC = aWindLanes[2];
    aDiffusionB.mInputD = aWindLanes[3];
    aDiffusionB.mOutputA = aVaporLanes[0];
    aDiffusionB.mOutputB = aVaporLanes[1];
    aDiffusionB.mOutputC = aVaporLanes[2];
    aDiffusionB.mOutputD = aVaporLanes[3];
    aDiffusionB.mEntropyA = aCrystalLanes[0];
    aDiffusionB.mEntropyB = aCrystalLanes[1];
    aDiffusionB.mEntropyC = aCrystalLanes[2];
    aDiffusionB.mEntropyD = aCrystalLanes[3];

    GBatch aBatchDiffusionB;
    if (!GRunMatrixDiffusion::Bake(aDiffusionB,
                                   &aBatchDiffusionB,
                                   pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = std::string("error on second matrix diffusion for seed: ") + *pErrorMessage;
        }
        return false;
    }
    pExpander->mSeed.AddBatch(aBatchDiffusionB);

    for (std::size_t i = 4U; i < 6U; ++i) {
        const std::string aStageName =
            "GSeedRunSeed_" + std::string(1, static_cast<char>('A' + i));
        if (!BuildSeedStage(pExpander->mSeed,
                            aStageConfigs[i],
                            true,
                            false,
                            aStageName.c_str(),
                            pErrorMessage)) {
            return false;
        }
    }

    GRunMatrixDiffusionConfig aDiffusionC;
    aDiffusionC.mInputA = aShadowLanes[0];
    aDiffusionC.mInputB = aShadowLanes[1];
    aDiffusionC.mInputC = aShadowLanes[2];
    aDiffusionC.mInputD = aShadowLanes[3];
    aDiffusionC.mOutputA = aCelestialLanes[0];
    aDiffusionC.mOutputB = aCelestialLanes[1];
    aDiffusionC.mOutputC = aCelestialLanes[2];
    aDiffusionC.mOutputD = aCelestialLanes[3];
    aDiffusionC.mEntropyA = aPlasmaLanes[0];
    aDiffusionC.mEntropyB = aPlasmaLanes[1];
    aDiffusionC.mEntropyC = aPlasmaLanes[2];
    aDiffusionC.mEntropyD = aPlasmaLanes[3];

    GBatch aBatchDiffusionC;
    if (!GRunMatrixDiffusion::Bake(aDiffusionC,
                                   &aBatchDiffusionC,
                                   pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = "error on third matrix diffusion for seed: " +
                *pErrorMessage;
        }
        return false;
    }
    pExpander->mSeed.AddBatch(aBatchDiffusionC);

    for (std::size_t i = 6U; i < 8U; ++i) {
        const std::string aStageName =
            "GSeedRunSeed_" + std::string(1, static_cast<char>('A' + i));
        if (!BuildSeedStage(pExpander->mSeed,
                            aStageConfigs[i],
                            true,
                            false,
                            aStageName.c_str(),
                            pErrorMessage)) {
            return false;
        }
    }

    GRunMatrixDiffusionConfig aDiffusionD;
    aDiffusionD.mInputA = aWaterLanes[0];
    aDiffusionD.mInputB = aWaterLanes[1];
    aDiffusionD.mInputC = aWaterLanes[2];
    aDiffusionD.mInputD = aWaterLanes[3];
    aDiffusionD.mOutputA = aSpiritLanes[0];
    aDiffusionD.mOutputB = aSpiritLanes[1];
    aDiffusionD.mOutputC = aSpiritLanes[2];
    aDiffusionD.mOutputD = aSpiritLanes[3];
    aDiffusionD.mEntropyA = aLightningLanes[0];
    aDiffusionD.mEntropyB = aLightningLanes[1];
    aDiffusionD.mEntropyC = aLightningLanes[2];
    aDiffusionD.mEntropyD = aLightningLanes[3];

    GBatch aBatchDiffusionD;
    if (!GRunMatrixDiffusion::Bake(aDiffusionD,
                                   &aBatchDiffusionD,
                                   pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = "error on fourth matrix diffusion for seed: " +
                *pErrorMessage;
        }
        return false;
    }
    pExpander->mSeed.AddBatch(aBatchDiffusionD);

    if (!BuildSeedStage(pExpander->mSeed,
                        aStageConfigs[8],
                        true,
                        false,
                        "GSeedRunSeed_I",
                        pErrorMessage)) {
        return false;
    }

    GRunMatrixDiffusionConfig aDiffusionE;
    aDiffusionE.mInputA = aEarthLanes[0];
    aDiffusionE.mInputB = aEarthLanes[1];
    aDiffusionE.mInputC = aEarthLanes[2];
    aDiffusionE.mInputD = aEarthLanes[3];
    aDiffusionE.mOutputA = aIceLanes[0];
    aDiffusionE.mOutputB = aIceLanes[1];
    aDiffusionE.mOutputC = aIceLanes[2];
    aDiffusionE.mOutputD = aIceLanes[3];
    aDiffusionE.mEntropyA = aSpiritLanes[0];
    aDiffusionE.mEntropyB = aSpiritLanes[1];
    aDiffusionE.mEntropyC = aSpiritLanes[2];
    aDiffusionE.mEntropyD = aSpiritLanes[3];

    GBatch aBatchDiffusionE;
    if (!GRunMatrixDiffusion::Bake(aDiffusionE,
                                   &aBatchDiffusionE,
                                   pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = "error on fifth matrix diffusion for seed: " +
                *pErrorMessage;
        }
        return false;
    }
    pExpander->mSeed.AddBatch(aBatchDiffusionE);

    if (!BuildSeedStage(pExpander->mSeed,
                        aStageConfigs[9],
                        true,
                        false,
                        "GSeedRunSeed_J",
                        pErrorMessage)) {
        return false;
    }

    pExpander->mSeed.AddLine("");
    pExpander->mSeed.AddLine(
        "for (std::size_t aIndex = 0U; aIndex < S_BLOCK; aIndex += 1U) {");
    pExpander->mSeed.AddLine(
        "    pWorkSpace->mFireLaneA[aIndex] = pWorkSpace->mIceLaneA[S_BLOCK1 - aIndex];");
    pExpander->mSeed.AddLine(
        "    pWorkSpace->mFireLaneB[aIndex] = pWorkSpace->mIceLaneB[S_BLOCK1 - aIndex];");
    pExpander->mSeed.AddLine(
        "    pWorkSpace->mFireLaneC[aIndex] = pWorkSpace->mIceLaneC[S_BLOCK1 - aIndex];");
    pExpander->mSeed.AddLine(
        "    pWorkSpace->mFireLaneD[aIndex] = pWorkSpace->mIceLaneD[S_BLOCK1 - aIndex];");
    pExpander->mSeed.AddLine("}");
    pExpander->mSeed.AddLine("");

    if (gCandidateIndex < 0) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage =
                "Builder_Seeder received a negative candidate index";
        }
        return false;
    }

    GSeedRunKeyBoxConfig::KeyBoxStageConfigs aKeyBoxConfigs;
    if (!GSeedRunKeyBoxConfig::MakeKeyBoxConfigs(
            static_cast<std::size_t>(gCandidateIndex),
            pResidualBucket,
            &aKeyBoxConfigs,
            pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage =
                "Builder_Seeder failed to make key-box configs:\n" +
                *pErrorMessage;
        }
        return false;
    }
    pExpander->mSeedKeyBoxStageConfigs.assign(
        aKeyBoxConfigs.begin(),
        aKeyBoxConfigs.end()
    );

    pExpander->mSeed.AddLine("//");
    pExpander->mSeed.AddLine("////////////////////////////////////////////////////////");
    pExpander->mSeed.AddLine("");
    pExpander->mSeed.AddLine("////////////////////////////////////////////////////////");
    pExpander->mSeed.AddLine("//");
    pExpander->mSeed.AddLine("// Key entropy loops");
    pExpander->mSeed.AddLine("//");
    for (std::size_t i = 0U; i < 16U; ++i) {
        GSeedRunKEY aKeyBox(aKeyBoxConfigs[i]);
        if (!aKeyBox.Plan(pErrorMessage) ||
            !aKeyBox.Build(pExpander->mSeed, pErrorMessage)) {
            if (pErrorMessage != nullptr) {
                *pErrorMessage =
                    "Builder_Seeder failed on " +
                    aKeyBoxConfigs[i].mStageName + ":\n" +
                    *pErrorMessage;
            }
            return false;
        }
    }
    pExpander->mSeed.AddLine("");
    pExpander->mSeed.AddLine("// Key diffusion-source loops");
    pExpander->mSeed.AddLine("");
    for (std::size_t i = 16U; i < 32U; ++i) {
        GSeedRunKEY aKeyBox(aKeyBoxConfigs[i]);
        if (!aKeyBox.Plan(pErrorMessage) ||
            !aKeyBox.Build(pExpander->mSeed, pErrorMessage)) {
            if (pErrorMessage != nullptr) {
                *pErrorMessage =
                    "Builder_Seeder failed on " +
                    aKeyBoxConfigs[i].mStageName + ":\n" +
                    *pErrorMessage;
            }
            return false;
        }
    }
    pExpander->mSeed.AddLine("");
    pExpander->mSeed.AddLine("// Key mini-diffusion");
    pExpander->mSeed.AddLine("");
    pExpander->mSeed.AddLine("KeyDiffuse(pWorkSpace);");
    pExpander->mSeed.AddLine("");
    pExpander->mSeed.AddLine("// Final key-lane loops");
    pExpander->mSeed.AddLine("");
    for (std::size_t i = 32U; i < aKeyBoxConfigs.size(); ++i) {
        GSeedRunKEY aKeyBox(aKeyBoxConfigs[i]);
        if (!aKeyBox.Plan(pErrorMessage) ||
            !aKeyBox.Build(pExpander->mSeed, pErrorMessage)) {
            if (pErrorMessage != nullptr) {
                *pErrorMessage =
                    "Builder_Seeder failed on " +
                    aKeyBoxConfigs[i].mStageName + ":\n" +
                    *pErrorMessage;
            }
            return false;
        }

        const std::size_t aLogicalKeyIndex = i - 32U;
        const char aKeyBoxName =
            (aLogicalKeyIndex < 8U) ? 'A' : 'B';
        const std::size_t aKeyRowIndex = aLogicalKeyIndex % 8U;
        pExpander->mSeed.AddLine(
            "TwistSquash::SquashKeyA(" +
            KeyLaneMacroPlaceholder(aLogicalKeyIndex, 'A') + ", " +
            KeyLaneMacroPlaceholder(aLogicalKeyIndex, 'B') + ", " +
            KeyLaneMacroPlaceholder(aLogicalKeyIndex, 'C') + ", " +
            KeyLaneMacroPlaceholder(aLogicalKeyIndex, 'D') + ", " +
            "&(pWorkSpace->mKeyBox" + std::string(1U, aKeyBoxName) +
            "[" + std::to_string(aKeyRowIndex) + "U][0]));"
        );
        pExpander->mSeed.AddLine("");
    }
    pExpander->mSeed.AddLine("//");
    pExpander->mSeed.AddLine("////////////////////////////////////////////////////////");
    return true;
}
