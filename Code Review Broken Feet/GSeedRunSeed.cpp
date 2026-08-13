//
//  GSeedRunSeed.cpp
//  MeanMachine
//

#include "GSeedRunSeed.hpp"
#include "ArrangementFour.hpp"
#include "GPassFactoryMidstage.hpp"
#include "GPassFactoryStarter.hpp"
#include "GPassFactoryTrunk.hpp"
#include "Random.hpp"
#include "ResidualBucket.hpp"
#include "GSeedRunStageConfigValidator.hpp"

#include <algorithm>
#include <array>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>

namespace {

using Slot = TwistWorkSpaceSlot;
using SlotArray4 = GPassFactoryMidstage::SlotArray4;

const std::array<const char *, 16> kNonceVariableNames = {
    "aNonceWordA", "aNonceWordB", "aNonceWordC", "aNonceWordD",
    "aNonceWordE", "aNonceWordF", "aNonceWordG", "aNonceWordH",
    "aNonceWordI", "aNonceWordJ", "aNonceWordK", "aNonceWordL",
    "aNonceWordM", "aNonceWordN", "aNonceWordO", "aNonceWordP",
};

const std::array<const char *, 3> kNonceDiffuseNames = {
    "DiffuseA", "DiffuseB", "DiffuseC",
};

struct SeedStagePlan {
    char                                    mLetter;
    SlotArray4                              mPrimarySources;
    SlotArray4                              mDestinations;
    bool                                    mIsTrunk;
    int                                     mArrangementOffset;
};

int PhaseIndex(const TwistDomain pDomain) {
    switch (pDomain) {
        case TwistDomain::kKeySpawnA: return 1;
        case TwistDomain::kSeed: return 2;
        case TwistDomain::kTwist: return 3;
        case TwistDomain::kKeyRotateB: return 4;
        case TwistDomain::kKeySpawnB: return 5;
        case TwistDomain::kKeyRotateA:
        default:
            return 0;
    }
}

std::string SeedStageName(const char pStageLetter) {
    return "GSeedRunSeed_" + std::string(1U, pStageLetter);
}

std::string SeedStageTitle(const char pStageLetter) {
    return "Seed — Stage " + std::string(1U, pStageLetter);
}

std::string SeedLoopName(const std::string &pStageName) {
    std::string aResult = "seed_loop";
    if (!pStageName.empty()) {
        const char aStageLetter = pStageName.back();
        if ((aStageLetter >= 'A') && (aStageLetter <= 'Q')) {
            aResult.push_back('_');
            aResult.push_back(
                static_cast<char>('a' + (aStageLetter - 'A')));
        }
    }
    return aResult;
}

std::string UInt64Literal(const std::uint64_t pValue) {
    std::ostringstream aStream;
    aStream << "0x" << std::uppercase << std::hex << pValue << "ULL";
    return aStream.str();
}

const char *RandomNonceDiffuseName() {
    return kNonceDiffuseNames[static_cast<std::size_t>(
        Random::Get(static_cast<int>(kNonceDiffuseNames.size())))];
}

std::string NonceDeclareLine(const GSymbol &pNonceSymbol) {
    const std::uint64_t aMultiplyWord = Random::Get64HighOdd();
    const std::uint64_t aAddWord = Random::Get64High();

    std::ostringstream aLine;
    aLine << "const std::uint64_t " << pNonceSymbol.mName
          << " = TwistMix64::" << RandomNonceDiffuseName()
          << "(pNonce * " << UInt64Literal(aMultiplyWord)
          << " + " << UInt64Literal(aAddWord) << ");";
    return aLine.str();
}

void AddSeedNoncePrologue(TwistProgramBranch &pBranch) {
    for (const char *aNonceVariableName : kNonceVariableNames) {
        pBranch.AddLine(
            NonceDeclareLine(GSymbol::Var(aNonceVariableName)));
    }
}

std::vector<Slot> PhaseSalts(const TwistDomain pDomain,
                             const Slot pBaseSlot,
                             const int pLaneCount) {
    const int aBase = static_cast<int>(pBaseSlot);
    const int aOffset = PhaseIndex(pDomain) * 24;

    std::vector<Slot> aResult;
    aResult.reserve(static_cast<std::size_t>(pLaneCount));
    for (int i = 0; i < pLaneCount; ++i) {
        aResult.push_back(static_cast<Slot>(aBase + aOffset + i));
    }
    return aResult;
}

GSeedRunStageConfig BaseConfig(const std::string &pStageName,
                               const bool pUseNonces,
                               const GAXSFormat pFormat) {
    constexpr TwistDomain kDomain = TwistDomain::kSeed;
    const std::string aLoopName = SeedLoopName(pStageName);

    GSeedRunStageConfig aConfig;
    aConfig.mStageName = pStageName;
    aConfig.mBatchName = aLoopName;
    aConfig.mStartLine =
        "// " + pStageName + " " + aLoopName + " (start)";
    aConfig.mEndLine =
        "// " + pStageName + " " + aLoopName + " (end)";
    aConfig.mFormat = pFormat;
    aConfig.mIgnoreNonces = !pUseNonces;
    aConfig.mDomain = kDomain;
    aConfig.mIsNonKDF = true;
    aConfig.mSaltsOrbiterAssign = PhaseSalts(
        kDomain, Slot::kKeyRotateASaltOrbiterAssignA, 8);
    aConfig.mSaltsOrbiterUpdate = PhaseSalts(
        kDomain, Slot::kKeyRotateASaltOrbiterUpdateA, 8);
    aConfig.mSaltsWandererUpdate = PhaseSalts(
        kDomain, Slot::kKeyRotateASaltWandererUpdateA, 8);
    return aConfig;
}

std::vector<Slot> WithdrawResidualsWithSource(
    ResidualBucket &pResidualBucket,
    const std::string &pStageName) {
    const std::size_t aPoolCount =
        std::min<std::size_t>(15U,
                              pResidualBucket.CountValidResiduals());
    std::vector<Slot> aResiduals =
        pResidualBucket.Withdraw(pStageName,
                                 static_cast<int>(aPoolCount));
    aResiduals.push_back(Slot::kSourceLane);
    return aResiduals;
}

std::vector<Slot> StageOutputs(const SeedStagePlan &pPlan) {
    return GPassFactoryMidstage::ToVector(pPlan.mDestinations);
}

void AddCompletedStageLanes(ResidualBucket &pResidualBucket,
                            const SeedStagePlan &pPlan) {
    std::vector<Slot> aResiduals(
        pPlan.mPrimarySources.begin(),
        pPlan.mPrimarySources.end());
    const std::vector<Slot> aOutputs = StageOutputs(pPlan);
    aResiduals.insert(aResiduals.end(),
                      aOutputs.begin(),
                      aOutputs.end());
    pResidualBucket.AddResiduals(
        SeedStageTitle(pPlan.mLetter),
        std::move(aResiduals));
}

} // namespace

namespace GSeedRunSeedConfig {

SeedStageConfigs MakeSeedConfig(const bool pUseNonces,
                                ResidualBucket &pResidualBucket,
                                const std::size_t pCandidateIndex) {
    SeedStageConfigs aConfigs;

    // Lane Plan

    // A: Source + Nonce -> Water.
    const GPassFactoryStarter::SlotArray2 aPrimarySourcesA = {
        Slot::kSourceLane, Slot::kNonceLane,
    };
    const SlotArray4 aDestinationsA = {
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kWaterLaneC, Slot::kWaterLaneD,
    };

    // Eight ARX/ARX/diffuse rounds, followed by one final ARX stage. Every
    // write family is unique. Stages after A retain Source as one fixed
    // residual; no KDF residual material enters this schedule.
    const std::array<SeedStagePlan, 16U> aLanePlans = {{
        {'B', {Slot::kWaterLaneA, Slot::kWaterLaneB, Slot::kWaterLaneC, Slot::kWaterLaneD},
              {Slot::kSpiritLaneA, Slot::kSpiritLaneB, Slot::kSpiritLaneC, Slot::kSpiritLaneD},
              false, 0},
        {'C', {Slot::kStasisLaneA, Slot::kStasisLaneB, Slot::kStasisLaneC, Slot::kStasisLaneD},
              {Slot::kLightningLaneA, Slot::kLightningLaneB, Slot::kLightningLaneC, Slot::kLightningLaneD},
              true, 7},
        {'D', {Slot::kLightningLaneA, Slot::kLightningLaneB, Slot::kLightningLaneC, Slot::kLightningLaneD},
              {Slot::kWindLaneA, Slot::kWindLaneB, Slot::kWindLaneC, Slot::kWindLaneD},
              false, 0},
        {'E', {Slot::kVaporLaneA, Slot::kVaporLaneB, Slot::kVaporLaneC, Slot::kVaporLaneD},
              {Slot::kPlasmaLaneA, Slot::kPlasmaLaneB, Slot::kPlasmaLaneC, Slot::kPlasmaLaneD},
              true, 9},
        {'F', {Slot::kPlasmaLaneA, Slot::kPlasmaLaneB, Slot::kPlasmaLaneC, Slot::kPlasmaLaneD},
              {Slot::kAetherLaneA, Slot::kAetherLaneB, Slot::kAetherLaneC, Slot::kAetherLaneD},
              false, 0},
        {'G', {Slot::kShadowLaneA, Slot::kShadowLaneB, Slot::kShadowLaneC, Slot::kShadowLaneD},
              {Slot::kMysticalLaneA, Slot::kMysticalLaneB, Slot::kMysticalLaneC, Slot::kMysticalLaneD},
              true, 13},
        {'H', {Slot::kMysticalLaneA, Slot::kMysticalLaneB, Slot::kMysticalLaneC, Slot::kMysticalLaneD},
              {Slot::kKineticLaneA, Slot::kKineticLaneB, Slot::kKineticLaneC, Slot::kKineticLaneD},
              false, 0},
        {'I', {Slot::kSonicLaneA, Slot::kSonicLaneB, Slot::kSonicLaneC, Slot::kSonicLaneD},
              {Slot::kPlanarLaneA, Slot::kPlanarLaneB, Slot::kPlanarLaneC, Slot::kPlanarLaneD},
              true, 2},
        {'J', {Slot::kPlanarLaneA, Slot::kPlanarLaneB, Slot::kPlanarLaneC, Slot::kPlanarLaneD},
              {Slot::kFrostLaneA, Slot::kFrostLaneB, Slot::kFrostLaneC, Slot::kFrostLaneD},
              false, 0},
        {'K', {Slot::kArcaneLaneA, Slot::kArcaneLaneB, Slot::kArcaneLaneC, Slot::kArcaneLaneD},
              {Slot::kLunarLaneA, Slot::kLunarLaneB, Slot::kLunarLaneC, Slot::kLunarLaneD},
              true, 6},
        {'L', {Slot::kLunarLaneA, Slot::kLunarLaneB, Slot::kLunarLaneC, Slot::kLunarLaneD},
              {Slot::kRunicLaneA, Slot::kRunicLaneB, Slot::kRunicLaneC, Slot::kRunicLaneD},
              false, 0},
        {'M', {Slot::kGloomLaneA, Slot::kGloomLaneB, Slot::kGloomLaneC, Slot::kGloomLaneD},
              {Slot::kAbjurationLaneA, Slot::kAbjurationLaneB, Slot::kAbjurationLaneC, Slot::kAbjurationLaneD},
              true, 11},
        {'N', {Slot::kAbjurationLaneA, Slot::kAbjurationLaneB, Slot::kAbjurationLaneC, Slot::kAbjurationLaneD},
              {Slot::kDivinationLaneA, Slot::kDivinationLaneB, Slot::kDivinationLaneC, Slot::kDivinationLaneD},
              false, 0},
        {'O', {Slot::kEvocationLaneA, Slot::kEvocationLaneB, Slot::kEvocationLaneC, Slot::kEvocationLaneD},
              {Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD},
              true, 5},
        {'P', {Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD},
              {Slot::kCovenLaneA, Slot::kCovenLaneB, Slot::kCovenLaneC, Slot::kCovenLaneD},
              false, 0},
        {'Q', {Slot::kHeartLaneA, Slot::kHeartLaneB, Slot::kHeartLaneC, Slot::kHeartLaneD},
              {Slot::kAlchemyLaneA, Slot::kAlchemyLaneB, Slot::kAlchemyLaneC, Slot::kAlchemyLaneD},
              true, 3},
    }};

    // Stage Construction

    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aPrimarySourcesA));
    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aDestinationsA));
    pResidualBucket.Withdraw("Seed — Stage A", 0);

    GSeedRunStageConfig aConfigA = BaseConfig(
        "GSeedRunSeed_A", pUseNonces, GAXSFormat::kN11);
    aConfigA.mSlices = GPassFactoryStarter::KDF_A_AStarterSlices(
        aPrimarySourcesA,
        aDestinationsA,
        pCandidateIndex);
    aConfigA.mExpectedSkeletonCount =
        static_cast<int>(aDestinationsA.size());
    aConfigA.mHotPackCount =
        static_cast<int>(aDestinationsA.size());

    std::string aErrorMessageA;
    if (!GSeedRunStageConfigValidator::ValidateStarter(
            aConfigA,
            GPassFactoryMidstage::ToVector(aPrimarySourcesA),
            GPassFactoryMidstage::ToVector(aDestinationsA),
            &aErrorMessageA)) {
        printf("MakeSeedConfig stage A was not valid with ValidateStarter");
        printf("%s\n", aErrorMessageA.c_str());
        exit(0);
    }
    aConfigs[0] = aConfigA;
    pResidualBucket.AddResiduals(
        "Seed — Stage A",
        GPassFactoryMidstage::ToVector(aDestinationsA));

    for (std::size_t aPlanIndex = 0U;
         aPlanIndex < aLanePlans.size();
         ++aPlanIndex) {
        const SeedStagePlan &aPlan = aLanePlans[aPlanIndex];
        const std::size_t aConfigIndex = aPlanIndex + 1U;
        const std::string aStageName = SeedStageName(aPlan.mLetter);
        const std::string aStageTitle = SeedStageTitle(aPlan.mLetter);
        const std::vector<Slot> aOutputs = StageOutputs(aPlan);

        pResidualBucket.Remove(
            GPassFactoryMidstage::ToVector(aPlan.mPrimarySources));
        pResidualBucket.Remove(aOutputs);

        GSeedRunStageConfig aConfig = BaseConfig(
            aStageName, pUseNonces, GAXSFormat::kN11);
        std::string aErrorMessage;
        const std::vector<Slot> aResiduals =
            WithdrawResidualsWithSource(pResidualBucket,
                                        aStageTitle);
        aConfig.mExpectedSkeletonCount =
            static_cast<int>(aPlan.mDestinations.size());
        aConfig.mHotPackCount =
            static_cast<int>(aPlan.mDestinations.size());

        if (aPlan.mIsTrunk) {
            const ArrangementFour::SlotArray4 aArrangedPrimarySources =
                ArrangementFour::Arrange(
                    aPlan.mPrimarySources,
                    static_cast<int>(pCandidateIndex),
                    aPlan.mArrangementOffset);
            aConfig.mSlices = GPassFactoryTrunk::FourPassVariableResidualSlices(
                aArrangedPrimarySources,
                aResiduals,
                aPlan.mDestinations);
            if (!GSeedRunStageConfigValidator::ValidateTrunk(
                    aConfig,
                    GPassFactoryMidstage::ToVector(aArrangedPrimarySources),
                    aResiduals,
                    GPassFactoryMidstage::ToVector(aPlan.mDestinations),
                    &aErrorMessage)) {
                printf("MakeSeedConfig stage %c was not valid with ValidateTrunk",
                       aPlan.mLetter);
                printf("%s\n", aErrorMessage.c_str());
                exit(0);
            }
        } else {
            aConfig.mSlices =
                GPassFactoryMidstage::FourPassVariableResidualSlices(
                    aPlan.mPrimarySources,
                    aResiduals,
                    aPlan.mDestinations);
            if (!GSeedRunStageConfigValidator::ValidateMidstage(
                    aConfig,
                    GPassFactoryMidstage::ToVector(aPlan.mPrimarySources),
                    aResiduals,
                    GPassFactoryMidstage::ToVector(aPlan.mDestinations),
                    &aErrorMessage)) {
                printf("MakeSeedConfig stage %c was not valid with ValidateMidstage",
                       aPlan.mLetter);
                printf("%s\n", aErrorMessage.c_str());
                exit(0);
            }
        }

        aConfigs[aConfigIndex] = aConfig;
        AddCompletedStageLanes(pResidualBucket, aPlan);
    }

    pResidualBucket.Print("Seed — Final");
    return aConfigs;
}

} // namespace GSeedRunSeedConfig

GSeedRunSeed::GSeedRunSeed(const GSeedRunStageConfig &pConfig,
                           const bool pUseNonces,
                           const bool pEmitNoncePrologue)
: mStage(pConfig),
  mUseNonces(pUseNonces),
  mEmitNoncePrologue(pEmitNoncePrologue) {
}

bool GSeedRunSeed::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunSeed::Build(TwistProgramBranch &pBranch,
                         std::string *pErrorMessage) {
    if (mUseNonces && mEmitNoncePrologue) {
        AddSeedNoncePrologue(pBranch);
    }
    return mStage.Build(pBranch, pErrorMessage);
}
