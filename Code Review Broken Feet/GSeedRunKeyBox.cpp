//
//  GSeedRunKeyBox.cpp
//  MeanMachine
//

#include "GSeedRunKeyBox.hpp"

#include "GPassFactoryMidstage.hpp"
#include "GPassFactoryStarter.hpp"
#include "KeyLaneAssignments.hpp"
#include "ResidualBucket.hpp"

#include <array>
#include <utility>
#include <vector>

namespace {

using Slot = TwistWorkSpaceSlot;

constexpr std::size_t kKeyFlowCount = 16U;
constexpr std::size_t kKeyBoxAFlowCount = 8U;
constexpr std::size_t kPhaseAConfigOffset = 0U;
constexpr std::size_t kPhaseBConfigOffset = 16U;
constexpr std::size_t kPhaseCConfigOffset = 32U;
constexpr std::size_t kPhaseDConfigOffset = 48U;
constexpr std::size_t kPhaseEConfigOffset = 64U;

// The names are grouped by phase to match both the lane plan below and the
// three contiguous config ranges consumed by Builder_Seeder.
constexpr std::array<const char *, kKeyFlowCount> kStageNamesA = {
    "GSeedRunKEY_A_A_A", "GSeedRunKEY_A_B_A",
    "GSeedRunKEY_A_C_A", "GSeedRunKEY_A_D_A",
    "GSeedRunKEY_A_E_A", "GSeedRunKEY_A_F_A",
    "GSeedRunKEY_A_G_A", "GSeedRunKEY_A_H_A",
    "GSeedRunKEY_B_A_A", "GSeedRunKEY_B_B_A",
    "GSeedRunKEY_B_C_A", "GSeedRunKEY_B_D_A",
    "GSeedRunKEY_B_E_A", "GSeedRunKEY_B_F_A",
    "GSeedRunKEY_B_G_A", "GSeedRunKEY_B_H_A",
};

constexpr std::array<const char *, kKeyFlowCount> kBatchNamesA = {
    "key_a_loop_a_a", "key_a_loop_b_a",
    "key_a_loop_c_a", "key_a_loop_d_a",
    "key_a_loop_e_a", "key_a_loop_f_a",
    "key_a_loop_g_a", "key_a_loop_h_a",
    "key_b_loop_a_a", "key_b_loop_b_a",
    "key_b_loop_c_a", "key_b_loop_d_a",
    "key_b_loop_e_a", "key_b_loop_f_a",
    "key_b_loop_g_a", "key_b_loop_h_a",
};

constexpr std::array<const char *, kKeyFlowCount> kStageNamesB = {
    "GSeedRunKEY_A_A_B", "GSeedRunKEY_A_B_B",
    "GSeedRunKEY_A_C_B", "GSeedRunKEY_A_D_B",
    "GSeedRunKEY_A_E_B", "GSeedRunKEY_A_F_B",
    "GSeedRunKEY_A_G_B", "GSeedRunKEY_A_H_B",
    "GSeedRunKEY_B_A_B", "GSeedRunKEY_B_B_B",
    "GSeedRunKEY_B_C_B", "GSeedRunKEY_B_D_B",
    "GSeedRunKEY_B_E_B", "GSeedRunKEY_B_F_B",
    "GSeedRunKEY_B_G_B", "GSeedRunKEY_B_H_B",
};

constexpr std::array<const char *, kKeyFlowCount> kBatchNamesB = {
    "key_a_loop_a_b", "key_a_loop_b_b",
    "key_a_loop_c_b", "key_a_loop_d_b",
    "key_a_loop_e_b", "key_a_loop_f_b",
    "key_a_loop_g_b", "key_a_loop_h_b",
    "key_b_loop_a_b", "key_b_loop_b_b",
    "key_b_loop_c_b", "key_b_loop_d_b",
    "key_b_loop_e_b", "key_b_loop_f_b",
    "key_b_loop_g_b", "key_b_loop_h_b",
};

constexpr std::array<const char *, kKeyFlowCount> kStageNamesC = {
    "GSeedRunKEY_A_A_C", "GSeedRunKEY_A_B_C",
    "GSeedRunKEY_A_C_C", "GSeedRunKEY_A_D_C",
    "GSeedRunKEY_A_E_C", "GSeedRunKEY_A_F_C",
    "GSeedRunKEY_A_G_C", "GSeedRunKEY_A_H_C",
    "GSeedRunKEY_B_A_C", "GSeedRunKEY_B_B_C",
    "GSeedRunKEY_B_C_C", "GSeedRunKEY_B_D_C",
    "GSeedRunKEY_B_E_C", "GSeedRunKEY_B_F_C",
    "GSeedRunKEY_B_G_C", "GSeedRunKEY_B_H_C",
};

constexpr std::array<const char *, kKeyFlowCount> kBatchNamesC = {
    "key_a_loop_a_c", "key_a_loop_b_c",
    "key_a_loop_c_c", "key_a_loop_d_c",
    "key_a_loop_e_c", "key_a_loop_f_c",
    "key_a_loop_g_c", "key_a_loop_h_c",
    "key_b_loop_a_c", "key_b_loop_b_c",
    "key_b_loop_c_c", "key_b_loop_d_c",
    "key_b_loop_e_c", "key_b_loop_f_c",
    "key_b_loop_g_c", "key_b_loop_h_c",
};

constexpr std::array<const char *, kKeyFlowCount> kStageNamesD = {
    "GSeedRunKEY_A_A_D", "GSeedRunKEY_A_B_D",
    "GSeedRunKEY_A_C_D", "GSeedRunKEY_A_D_D",
    "GSeedRunKEY_A_E_D", "GSeedRunKEY_A_F_D",
    "GSeedRunKEY_A_G_D", "GSeedRunKEY_A_H_D",
    "GSeedRunKEY_B_A_D", "GSeedRunKEY_B_B_D",
    "GSeedRunKEY_B_C_D", "GSeedRunKEY_B_D_D",
    "GSeedRunKEY_B_E_D", "GSeedRunKEY_B_F_D",
    "GSeedRunKEY_B_G_D", "GSeedRunKEY_B_H_D",
};

constexpr std::array<const char *, kKeyFlowCount> kBatchNamesD = {
    "key_a_loop_a_d", "key_a_loop_b_d",
    "key_a_loop_c_d", "key_a_loop_d_d",
    "key_a_loop_e_d", "key_a_loop_f_d",
    "key_a_loop_g_d", "key_a_loop_h_d",
    "key_b_loop_a_d", "key_b_loop_b_d",
    "key_b_loop_c_d", "key_b_loop_d_d",
    "key_b_loop_e_d", "key_b_loop_f_d",
    "key_b_loop_g_d", "key_b_loop_h_d",
};

constexpr std::array<const char *, kKeyFlowCount> kStageNamesE = {
    "GSeedRunKEY_A_A_E", "GSeedRunKEY_A_B_E",
    "GSeedRunKEY_A_C_E", "GSeedRunKEY_A_D_E",
    "GSeedRunKEY_A_E_E", "GSeedRunKEY_A_F_E",
    "GSeedRunKEY_A_G_E", "GSeedRunKEY_A_H_E",
    "GSeedRunKEY_B_A_E", "GSeedRunKEY_B_B_E",
    "GSeedRunKEY_B_C_E", "GSeedRunKEY_B_D_E",
    "GSeedRunKEY_B_E_E", "GSeedRunKEY_B_F_E",
    "GSeedRunKEY_B_G_E", "GSeedRunKEY_B_H_E",
};

constexpr std::array<const char *, kKeyFlowCount> kBatchNamesE = {
    "key_a_loop_a_e", "key_a_loop_b_e",
    "key_a_loop_c_e", "key_a_loop_d_e",
    "key_a_loop_e_e", "key_a_loop_f_e",
    "key_a_loop_g_e", "key_a_loop_h_e",
    "key_b_loop_a_e", "key_b_loop_b_e",
    "key_b_loop_c_e", "key_b_loop_d_e",
    "key_b_loop_e_e", "key_b_loop_f_e",
    "key_b_loop_g_e", "key_b_loop_h_e",
};

std::vector<Slot> PhaseSalts(const TwistDomain pDomain,
                             const Slot pBaseSlot,
                             const int pLaneCount) {
    int aPhaseIndex = 0;
    switch (pDomain) {
        case TwistDomain::kKeySpawnA: aPhaseIndex = 1; break;
        case TwistDomain::kSeed: aPhaseIndex = 2; break;
        case TwistDomain::kTwist: aPhaseIndex = 3; break;
        case TwistDomain::kKeyRotateB: aPhaseIndex = 4; break;
        case TwistDomain::kKeySpawnB: aPhaseIndex = 5; break;
        case TwistDomain::kKeyRotateA:
        default:
            aPhaseIndex = 0;
            break;
    }

    std::vector<Slot> aResult;
    aResult.reserve(static_cast<std::size_t>(pLaneCount));
    const int aBase = static_cast<int>(pBaseSlot);
    const int aOffset = aPhaseIndex * 24;
    for (int i = 0; i < pLaneCount; ++i) {
        aResult.push_back(
            static_cast<Slot>(aBase + aOffset + i)
        );
    }
    return aResult;
}

GSeedRunStageConfig BaseConfig(const char *pStageName,
                               const char *pBatchName,
                               const TwistDomain pDomain,
                               const GAXSFormat pFormat) {
    GSeedRunStageConfig aConfig;
    aConfig.mStageName = pStageName;
    aConfig.mBatchName = pBatchName;
    aConfig.mFormat = pFormat;
    aConfig.mIgnoreNonces = false;
    aConfig.mAssignType = GAssignType::kSet;
    aConfig.mDomain = pDomain;
    aConfig.mIsNonKDF = true;
    aConfig.mExpectedSkeletonCount = 1;
    aConfig.mHotPackCount = 1;
    aConfig.mMaxContextSourceCount = 4;
    aConfig.mMaxBoundSourceCount = 8;
    aConfig.mBindDuplicateSourceSlots = false;
    aConfig.mFixedDiffuse = GAXSKDiffuseKind::kDiffuseA;
    aConfig.mAutoRangeAdjust = false;
    aConfig.mSourceOffsetRangeLo = 0;
    aConfig.mSourceOffsetRangeHi = W_KEY1;
    aConfig.mEmitLaneFlowComments = true;
    aConfig.mSaltsOrbiterAssign =
        PhaseSalts(pDomain,
                   Slot::kKeyRotateASaltOrbiterAssignA,
                   8);
    aConfig.mSaltsOrbiterUpdate =
        PhaseSalts(pDomain,
                   Slot::kKeyRotateASaltOrbiterUpdateA,
                   8);
    aConfig.mSaltsWandererUpdate =
        PhaseSalts(pDomain,
                   Slot::kKeyRotateASaltWandererUpdateA,
                   8);
    return aConfig;
}

template <std::size_t N>
std::array<Slot, N> WithdrawFlowResiduals(
    ResidualBucket &pResidualBucket,
    const std::string &pStageName) {
    const std::vector<Slot> aWithdrawn =
        pResidualBucket.Withdraw(pStageName, static_cast<int>(N));
    std::array<Slot, N> aResult = {};
    for (std::size_t i = 0U; i < N; ++i) {
        aResult[i] = aWithdrawn[i];
    }
    return aResult;
}

std::uint8_t KeyLaneSplit(
    const Slot pSlot,
    const std::size_t pLogicalKeyIndex,
    const std::size_t pCandidateIndex) {
    return KeyLaneAssignments::Split(pSlot,
                                     pLogicalKeyIndex,
                                     pCandidateIndex);
}

bool ApplyKeyLaneSplits(
    GSeedRunStageConfig *pConfig,
    const std::size_t pLogicalKeyIndex,
    const std::size_t pCandidateIndex,
    std::string *pErrorMessage) {
    if (pConfig == nullptr) {
        return false;
    }

    for (GSeedRunStageSliceSpec &aSlice : pConfig->mSlices) {
        std::vector<Slot> aSources = aSlice.IngressSources();
        const std::vector<Slot> aCrossSources = aSlice.CrossSources();
        aSources.insert(aSources.end(),
                        aCrossSources.begin(),
                        aCrossSources.end());
        for (const Slot aSource : aSources) {
            if (TwistWorkSpace::GetBufferLength(aSource) != S_BLOCK) {
                continue;
            }
            if (!KeyLaneAssignments::HasLane(aSource)) {
                if (pErrorMessage != nullptr) {
                    *pErrorMessage =
                        "Key flow used a full lane without a mandatory "
                        "KeyLaneAssignments entry";
                }
                return false;
            }
            if (!aSlice.SetSourceLaneSplit(
                    aSource,
                    KeyLaneSplit(aSource,
                                 pLogicalKeyIndex,
                                 pCandidateIndex),
                    pErrorMessage)) {
                return false;
            }
        }

        if ((TwistWorkSpace::GetBufferLength(aSlice.mDest) == S_BLOCK) &&
            !KeyLaneAssignments::HasLane(aSlice.mDest)) {
            if (pErrorMessage != nullptr) {
                *pErrorMessage =
                    "Key flow wrote a full lane without a mandatory "
                    "KeyLaneAssignments entry";
            }
            return false;
        }
        if ((TwistWorkSpace::GetBufferLength(aSlice.mDest) == S_BLOCK) &&
            !aSlice.SetDestinationLaneSplit(
                KeyLaneSplit(aSlice.mDest,
                             pLogicalKeyIndex,
                             pCandidateIndex),
                pErrorMessage)) {
            return false;
        }
    }
    return true;
}

GSeedRunStageConfig FinishFourLoopConfig(
    GSeedRunStageConfig pConfig,
    const std::size_t pLogicalKeyIndex,
    const std::size_t pCandidateIndex,
    const TwistDomain pDomain,
    std::string *pErrorMessage) {
    pConfig.mExpectedSkeletonCount = 4;
    pConfig.mHotPackCount = 4;
    pConfig.mLoopBegin = 0;
    pConfig.mLoopBeginText.clear();
    pConfig.mLoopCeiling = W_KEY;
    pConfig.mLoopEndText = "W_KEY";
    pConfig.mSliceDomains.assign(4U, pDomain);
    if (!ApplyKeyLaneSplits(&pConfig,
                            pLogicalKeyIndex,
                            pCandidateIndex,
                            pErrorMessage)) {
        return GSeedRunStageConfig();
    }
    return pConfig;
}

} // namespace

namespace GSeedRunKeyBoxConfig {

bool MakeKeyBoxConfigs(const std::size_t pCandidateIndex,
                       const ResidualBucket &pSeedResidualBucket,
                       KeyBoxStageConfigs *pConfigs,
                       std::string *pErrorMessage) {
    if (pConfigs == nullptr) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = "Key-box config output was null";
        }
        return false;
    }
    // Lane Plan

    //
    // KEY — Phase A
    // Alchemy A-D + Coven A-D -> Earth A-D.
    // Eight inherited residual lanes are consumed.
    //
    const GPassFactoryStarter::SlotArray8 aPrimarySourcesA = {
        Slot::kAlchemyLaneA, Slot::kAlchemyLaneB,
        Slot::kAlchemyLaneC, Slot::kAlchemyLaneD,
        Slot::kCovenLaneA, Slot::kCovenLaneB,
        Slot::kCovenLaneC, Slot::kCovenLaneD,
    };
    const GPassFactoryStarter::SlotArray4 aDestinationsA = {
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
    };

    //
    // KEY — Phase B
    // Earth A-D -> Augury A-D.
    // Sixteen inherited residual lanes are consumed.
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesB = {
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsB = {
        Slot::kAuguryLaneA, Slot::kAuguryLaneB,
        Slot::kAuguryLaneC, Slot::kAuguryLaneD,
    };

    // The current flow's KeyDiffuse_A_*_* transforms Augury A-D into
    // Prophecy A-D here.

    //
    // KEY — Phase C
    // Prophecy A-D -> Transmutation A-D.
    // Sixteen inherited residual lanes are consumed.
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesC = {
        Slot::kProphecyLaneA, Slot::kProphecyLaneB,
        Slot::kProphecyLaneC, Slot::kProphecyLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsC = {
        Slot::kTransmutationLaneA, Slot::kTransmutationLaneB,
        Slot::kTransmutationLaneC, Slot::kTransmutationLaneD,
    };

    //
    // KEY — Phase D
    // Transmutation A-D -> Restoration A-D.
    // Sixteen inherited residual lanes are consumed.
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesD = {
        Slot::kTransmutationLaneA, Slot::kTransmutationLaneB,
        Slot::kTransmutationLaneC, Slot::kTransmutationLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsD = {
        Slot::kRestorationLaneA, Slot::kRestorationLaneB,
        Slot::kRestorationLaneC, Slot::kRestorationLaneD,
    };

    // The current flow's KeyDiffuse_B_*_* transforms Restoration A-D into
    // Celestial A-D here.

    //
    // KEY — Phase E
    // Celestial A-D -> Ice A-D.
    // This overwrites only the current logical key flow's Ice sixteenths;
    // every other flow owns a different KeyLaneAssignments split.
    // Sixteen inherited residual lanes are consumed.
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesE = {
        Slot::kCelestialLaneA, Slot::kCelestialLaneB,
        Slot::kCelestialLaneC, Slot::kCelestialLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsE = {
        Slot::kIceLaneA, Slot::kIceLaneB,
        Slot::kIceLaneC, Slot::kIceLaneD,
    };

    // These lanes have fixed jobs in the five phases. Source and Nonce are
    // deliberately excluded from key construction. No phase adds its output
    // lanes back; each independent flow drains this inherited bucket.
    const std::vector<Slot> aUnavailableResiduals = {
        Slot::kSourceLane,
        Slot::kNonceLane,
        Slot::kIceLaneA, Slot::kIceLaneB,
        Slot::kIceLaneC, Slot::kIceLaneD,
        Slot::kCovenLaneA, Slot::kCovenLaneB,
        Slot::kCovenLaneC, Slot::kCovenLaneD,
        Slot::kAlchemyLaneA, Slot::kAlchemyLaneB,
        Slot::kAlchemyLaneC, Slot::kAlchemyLaneD,
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
        Slot::kCelestialLaneA, Slot::kCelestialLaneB,
        Slot::kCelestialLaneC, Slot::kCelestialLaneD,
        Slot::kAuguryLaneA, Slot::kAuguryLaneB,
        Slot::kAuguryLaneC, Slot::kAuguryLaneD,
        Slot::kProphecyLaneA, Slot::kProphecyLaneB,
        Slot::kProphecyLaneC, Slot::kProphecyLaneD,
        Slot::kTransmutationLaneA, Slot::kTransmutationLaneB,
        Slot::kTransmutationLaneC, Slot::kTransmutationLaneD,
        Slot::kRestorationLaneA, Slot::kRestorationLaneB,
        Slot::kRestorationLaneC, Slot::kRestorationLaneD,
    };

    // Stage Construction

    for (std::size_t aLogicalIndex = 0U;
         aLogicalIndex < kKeyFlowCount;
         ++aLogicalIndex) {
        const TwistDomain aDomain =
            (aLogicalIndex < kKeyBoxAFlowCount)
                ? TwistDomain::kKeySpawnA
                : TwistDomain::kKeySpawnB;
        const std::string aFlowName =
            std::string("KEY flow ") +
            std::to_string(aLogicalIndex);

        // Each logical key flow gets an independent value-copy of the final
        // Seed residual state. Its withdrawals never affect another key flow
        // or the caller's bucket. Flattening the surviving lanes to three
        // makes every withdrawal terminal: a selected lane advances to four
        // and cannot be selected again within this key flow.
        ResidualBucket aFlowResidualBucket = pSeedResidualBucket;
        aFlowResidualBucket.Remove(aUnavailableResiduals);
        aFlowResidualBucket.FlattenUsageCounts(3U);

        const GPassFactoryStarter::SlotArray8 aResidualsA =
            WithdrawFlowResiduals<8U>(
                aFlowResidualBucket,
                aFlowName + " — Phase A");

        const GPassFactoryMidstage::SlotArray16 aResidualsB =
            WithdrawFlowResiduals<16U>(
                aFlowResidualBucket,
                aFlowName + " — Phase B");

        const GPassFactoryMidstage::SlotArray16 aResidualsC =
            WithdrawFlowResiduals<16U>(
                aFlowResidualBucket,
                aFlowName + " — Phase C");

        const GPassFactoryMidstage::SlotArray16 aResidualsD =
            WithdrawFlowResiduals<16U>(
                aFlowResidualBucket,
                aFlowName + " — Phase D");

        const GPassFactoryMidstage::SlotArray16 aResidualsE =
            WithdrawFlowResiduals<16U>(
                aFlowResidualBucket,
                aFlowName + " — Phase E");

        //
        // Build KEY — Phase A
        //
        GSeedRunStageConfig aConfigA = BaseConfig(
            kStageNamesA[aLogicalIndex],
            kBatchNamesA[aLogicalIndex],
            aDomain,
            GAXSFormat::kN11);
        aConfigA.mSlices =
            GPassFactoryStarter::WideFourPassTenResidualSlices(
                aPrimarySourcesA,
                aResidualsA,
                aDestinationsA);
        aConfigA = FinishFourLoopConfig(std::move(aConfigA),
                                        aLogicalIndex,
                                        pCandidateIndex,
                                        aDomain,
                                        pErrorMessage);
        if (aConfigA.mStageName.empty()) {
            return false;
        }
        (*pConfigs)[kPhaseAConfigOffset + aLogicalIndex] =
            std::move(aConfigA);

        //
        // Build KEY — Phase B
        //
        GSeedRunStageConfig aConfigB = BaseConfig(
            kStageNamesB[aLogicalIndex],
            kBatchNamesB[aLogicalIndex],
            aDomain,
            GAXSFormat::kN11);
        aConfigB.mSlices =
            GPassFactoryMidstage::FourPassSixteenResidualSlices(
                aPrimarySourcesB,
                aResidualsB,
                aDestinationsB);
        aConfigB = FinishFourLoopConfig(std::move(aConfigB),
                                        aLogicalIndex,
                                        pCandidateIndex,
                                        aDomain,
                                        pErrorMessage);
        if (aConfigB.mStageName.empty()) {
            return false;
        }
        (*pConfigs)[kPhaseBConfigOffset + aLogicalIndex] =
            std::move(aConfigB);

        //
        // Build KEY — Phase C
        //
        GSeedRunStageConfig aConfigC = BaseConfig(
            kStageNamesC[aLogicalIndex],
            kBatchNamesC[aLogicalIndex],
            aDomain,
            GAXSFormat::kN11);
        aConfigC.mSlices =
            GPassFactoryMidstage::FourPassSixteenResidualSlices(
                aPrimarySourcesC,
                aResidualsC,
                aDestinationsC);
        aConfigC = FinishFourLoopConfig(std::move(aConfigC),
                                        aLogicalIndex,
                                        pCandidateIndex,
                                        aDomain,
                                        pErrorMessage);
        if (aConfigC.mStageName.empty()) {
            return false;
        }
        (*pConfigs)[kPhaseCConfigOffset + aLogicalIndex] =
            std::move(aConfigC);

        //
        // Build KEY — Phase D
        //
        GSeedRunStageConfig aConfigD = BaseConfig(
            kStageNamesD[aLogicalIndex],
            kBatchNamesD[aLogicalIndex],
            aDomain,
            GAXSFormat::kN11);
        aConfigD.mSlices =
            GPassFactoryMidstage::FourPassSixteenResidualSlices(
                aPrimarySourcesD,
                aResidualsD,
                aDestinationsD);
        aConfigD = FinishFourLoopConfig(std::move(aConfigD),
                                        aLogicalIndex,
                                        pCandidateIndex,
                                        aDomain,
                                        pErrorMessage);
        if (aConfigD.mStageName.empty()) {
            return false;
        }
        (*pConfigs)[kPhaseDConfigOffset + aLogicalIndex] =
            std::move(aConfigD);

        //
        // Build KEY — Phase E
        //
        GSeedRunStageConfig aConfigE = BaseConfig(
            kStageNamesE[aLogicalIndex],
            kBatchNamesE[aLogicalIndex],
            aDomain,
            GAXSFormat::kN11);
        aConfigE.mSlices =
            GPassFactoryMidstage::FourPassSixteenResidualSlices(
                aPrimarySourcesE,
                aResidualsE,
                aDestinationsE);
        aConfigE = FinishFourLoopConfig(std::move(aConfigE),
                                        aLogicalIndex,
                                        pCandidateIndex,
                                        aDomain,
                                        pErrorMessage);
        if (aConfigE.mStageName.empty()) {
            return false;
        }
        (*pConfigs)[kPhaseEConfigOffset + aLogicalIndex] =
            std::move(aConfigE);
    }
    return true;
}

} // namespace GSeedRunKeyBoxConfig

GSeedRunKEY::GSeedRunKEY(
    const GSeedRunStageConfig &pConfig)
: mStage(pConfig) {
}

bool GSeedRunKEY::Plan(
    std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunKEY::Build(
    TwistProgramBranch &pBranch,
    std::string *pErrorMessage) {
    return mStage.Build(pBranch, pErrorMessage);
}
