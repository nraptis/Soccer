//
//  LaneCombosTest.mm
//  ScrambleTests
//

#import <XCTest/XCTest.h>

#include "EncryptionPlan.hpp"
#include "LaneCombinations.hpp"

#include <cstddef>
#include <cstdint>
#include <cstring>

namespace {

enum class ExpectedCipherClass : std::uint8_t {
    kLepton,
    kBoson,
    kBaryon,
    kFermion,
    kMuon,
    kQuasiparticle,
    kNeutrino,
};

struct ExpectedCipher {
    ExpectedCipherClass mClass;
    std::uint8_t mLaneCount;
};

struct PlanFailure {
    const char *mStage = "";
    std::size_t mSlot = 0U;
    std::size_t mExpectedStageCount = 0U;
    std::size_t mActualStageCount = 0U;
    ExpectedCipher mExpected{ExpectedCipherClass::kLepton, 0U};
    CipherType mActual = CipherType::kNone;
};

struct RotationSummary {
    std::size_t mRotationCount = 0U;
    std::size_t mMaskedRotationCount = 0U;
    bool mHasAdjacentRotations = false;
    const char *mAdjacentRotationStage = "";
    std::size_t mAdjacentRotationSlot = 0U;
    bool mHasAdjacentKeys = false;
    const char *mAdjacentKeyStage = "";
    std::size_t mAdjacentKeySlot = 0U;
};

const char *ClassName(ExpectedCipherClass pClass) {
    switch (pClass) {
        case ExpectedCipherClass::kLepton: return "Lepton";
        case ExpectedCipherClass::kBoson: return "Boson";
        case ExpectedCipherClass::kBaryon: return "Baryon";
        case ExpectedCipherClass::kFermion: return "Fermion";
        case ExpectedCipherClass::kMuon: return "Muon";
        case ExpectedCipherClass::kQuasiparticle: return "Quasiparticle";
        case ExpectedCipherClass::kNeutrino: return "Neutrino";
    }
    return "Unknown";
}

bool IsExpectedClass(CipherType pType, ExpectedCipherClass pClass) {
    switch (pClass) {
        case ExpectedCipherClass::kLepton: return IS_LEPTON(pType);
        case ExpectedCipherClass::kBoson: return IS_BOSON(pType);
        case ExpectedCipherClass::kBaryon: return IS_BARYON(pType);
        case ExpectedCipherClass::kFermion: return IS_FERMION(pType);
        case ExpectedCipherClass::kMuon: return IS_MUON(pType);
        case ExpectedCipherClass::kQuasiparticle: return IS_QUASIPARTICLE(pType);
        case ExpectedCipherClass::kNeutrino: return IS_NEUTRINO(pType);
    }
    return false;
}

template <std::size_t tCount>
bool ValidateStage(const char *pStageName,
                   const EncryptionPlanStage &pStage,
                   const ExpectedCipher (&pExpected)[tCount],
                   PlanFailure *pFailure) {
    if (pStage.mCount != tCount) {
        pFailure->mStage = pStageName;
        pFailure->mExpectedStageCount = tCount;
        pFailure->mActualStageCount = pStage.mCount;
        return false;
    }

    for (std::size_t aSlot=0U; aSlot<tCount; aSlot++) {
        const CipherType aType = pStage.mType[aSlot];
        if (!IsExpectedClass(aType, pExpected[aSlot].mClass) ||
            (CipherTool::CountLanes(aType) != pExpected[aSlot].mLaneCount)) {
            pFailure->mStage = pStageName;
            pFailure->mSlot = aSlot;
            pFailure->mExpectedStageCount = tCount;
            pFailure->mActualStageCount = pStage.mCount;
            pFailure->mExpected = pExpected[aSlot];
            pFailure->mActual = aType;
            return false;
        }
    }

    return true;
}

bool ValidateEmptyStage(const char *pStageName,
                        const EncryptionPlanStage &pStage,
                        PlanFailure *pFailure) {
    if (pStage.mCount == 0U) {
        return true;
    }

    pFailure->mStage = pStageName;
    pFailure->mExpectedStageCount = 0U;
    pFailure->mActualStageCount = pStage.mCount;
    return false;
}

RotationSummary SummarizeRotations(const EncryptionPlan &pPlan) {
    const EncryptionPlanStage *aStages[] = {
        &pPlan.mL3A,
        &pPlan.mL2A,
        &pPlan.mL1A,
        &pPlan.mL3B,
        &pPlan.mL2B,
        &pPlan.mL1B,
        &pPlan.mL3C,
    };
    const char *aStageNames[] = {
        "L3A",
        "L2A",
        "L1A",
        "L3B",
        "L2B",
        "L1B",
        "L3C",
    };

    RotationSummary aResult;
    bool aPreviousWasRotation = false;
    bool aPreviousWasKey = false;

    for (std::size_t aStageIndex=0U; aStageIndex<7U; aStageIndex++) {
        const EncryptionPlanStage &aStage = *aStages[aStageIndex];
        for (std::size_t aSlot=0U; aSlot<aStage.mCount; aSlot++) {
            const CipherType aType = aStage.mType[aSlot];
            const bool aIsRotation = IS_MESON(aType);
            const bool aIsKey = IS_LEPTON(aType) || IS_BOSON(aType);

            if (aIsRotation) {
                aResult.mRotationCount++;
                if (IS_BARYON(aType)) {
                    aResult.mMaskedRotationCount++;
                }
                if (aPreviousWasRotation && !aResult.mHasAdjacentRotations) {
                    aResult.mHasAdjacentRotations = true;
                    aResult.mAdjacentRotationStage = aStageNames[aStageIndex];
                    aResult.mAdjacentRotationSlot = aSlot;
                }
            }

            if (aIsKey && aPreviousWasKey && !aResult.mHasAdjacentKeys) {
                aResult.mHasAdjacentKeys = true;
                aResult.mAdjacentKeyStage = aStageNames[aStageIndex];
                aResult.mAdjacentKeySlot = aSlot;
            }

            aPreviousWasRotation = aIsRotation;
            aPreviousWasKey = aIsKey;
        }
    }

    return aResult;
}

bool ValidateWeakPlan(const EncryptionPlan &pPlan,
                      const WeakLaneCombination &pCombo,
                      PlanFailure *pFailure) {
    const ExpectedCipher aL3A[] = {
        {ExpectedCipherClass::kBaryon, 0U},
        {ExpectedCipherClass::kMuon, 0U},
        {ExpectedCipherClass::kFermion, 0U},
        {ExpectedCipherClass::kLepton, pCombo.mL3A[0]},
    };
    const ExpectedCipher aL2A[] = {
        {ExpectedCipherClass::kFermion, 0U},
        {ExpectedCipherClass::kQuasiparticle, 0U},
        {ExpectedCipherClass::kFermion, 0U},
        {ExpectedCipherClass::kLepton, pCombo.mL2A[0]},
    };
    const ExpectedCipher aL1A[] = {
        {ExpectedCipherClass::kBaryon, 0U},
        {ExpectedCipherClass::kNeutrino, 0U},
        {ExpectedCipherClass::kFermion, 0U},
        {ExpectedCipherClass::kLepton, pCombo.mL1A[0]},
    };
    const ExpectedCipher aL3B[] = {
        {ExpectedCipherClass::kFermion, 0U},
        {ExpectedCipherClass::kLepton, pCombo.mL3B[0]},
    };
    const ExpectedCipher aL2B[] = {
        {ExpectedCipherClass::kMuon, 0U},
    };
    const ExpectedCipher aL3C[] = {
        {ExpectedCipherClass::kFermion, 0U},
    };

    return ValidateStage("L3A", pPlan.mL3A, aL3A, pFailure) &&
           ValidateStage("L2A", pPlan.mL2A, aL2A, pFailure) &&
           ValidateStage("L1A", pPlan.mL1A, aL1A, pFailure) &&
           ValidateStage("L3B", pPlan.mL3B, aL3B, pFailure) &&
           ValidateStage("L2B", pPlan.mL2B, aL2B, pFailure) &&
           ValidateEmptyStage("L1B", pPlan.mL1B, pFailure) &&
           ValidateStage("L3C", pPlan.mL3C, aL3C, pFailure);
}

bool ValidateNormalPlan(const EncryptionPlan &pPlan,
                        const NormalLaneCombination &pCombo,
                        PlanFailure *pFailure) {
    const ExpectedCipher aL3A[] = {
        {ExpectedCipherClass::kBaryon, 0U},
        {ExpectedCipherClass::kBoson, pCombo.mL3A[0]},
        {ExpectedCipherClass::kFermion, 0U},
    };
    const ExpectedCipher aL2A[] = {
        {ExpectedCipherClass::kMuon, 0U},
        {ExpectedCipherClass::kLepton, pCombo.mL2A[0]},
        {ExpectedCipherClass::kBaryon, 0U},
    };
    const ExpectedCipher aL1A[] = {
        {ExpectedCipherClass::kLepton, pCombo.mL1A[0]},
        {ExpectedCipherClass::kBaryon, 0U},
    };
    const ExpectedCipher aL3B[] = {
        {ExpectedCipherClass::kQuasiparticle, 0U},
        {ExpectedCipherClass::kLepton, pCombo.mL3B[0]},
        {ExpectedCipherClass::kFermion, 0U},
    };
    const ExpectedCipher aL2B[] = {
        {ExpectedCipherClass::kLepton, pCombo.mL2B[0]},
        {ExpectedCipherClass::kBaryon, 0U},
    };
    const ExpectedCipher aL1B[] = {
        {ExpectedCipherClass::kNeutrino, 0U},
        {ExpectedCipherClass::kLepton, pCombo.mL1B[0]},
        {ExpectedCipherClass::kFermion, 0U},
    };
    const ExpectedCipher aL3C[] = {
        {ExpectedCipherClass::kLepton, pCombo.mL3C[0]},
        {ExpectedCipherClass::kBaryon, 0U},
    };

    return ValidateStage("L3A", pPlan.mL3A, aL3A, pFailure) &&
           ValidateStage("L2A", pPlan.mL2A, aL2A, pFailure) &&
           ValidateStage("L1A", pPlan.mL1A, aL1A, pFailure) &&
           ValidateStage("L3B", pPlan.mL3B, aL3B, pFailure) &&
           ValidateStage("L2B", pPlan.mL2B, aL2B, pFailure) &&
           ValidateStage("L1B", pPlan.mL1B, aL1B, pFailure) &&
           ValidateStage("L3C", pPlan.mL3C, aL3C, pFailure);
}

bool ValidateStrongPlan(const EncryptionPlan &pPlan,
                        const StrongLaneCombination &pCombo,
                        PlanFailure *pFailure) {
    const ExpectedCipher aL3A[] = {
        {ExpectedCipherClass::kBoson, pCombo.mL3A[0]},
        {ExpectedCipherClass::kBaryon, 0U},
        {ExpectedCipherClass::kLepton, pCombo.mL3A[1]},
        {ExpectedCipherClass::kMuon, 0U},
    };
    const ExpectedCipher aL2A[] = {
        {ExpectedCipherClass::kBoson, pCombo.mL2A[0]},
        {ExpectedCipherClass::kBaryon, 0U},
        {ExpectedCipherClass::kLepton, pCombo.mL2A[1]},
        {ExpectedCipherClass::kQuasiparticle, 0U},
    };
    const ExpectedCipher aL1A[] = {
        {ExpectedCipherClass::kLepton, pCombo.mL1A[0]},
        {ExpectedCipherClass::kBaryon, 0U},
        {ExpectedCipherClass::kLepton, pCombo.mL1A[1]},
        {ExpectedCipherClass::kNeutrino, 0U},
    };
    const ExpectedCipher aL3B[] = {
        {ExpectedCipherClass::kLepton, pCombo.mL3B[0]},
        {ExpectedCipherClass::kBaryon, 0U},
        {ExpectedCipherClass::kLepton, pCombo.mL3B[1]},
        {ExpectedCipherClass::kMuon, 0U},
    };
    const ExpectedCipher aL2B[] = {
        {ExpectedCipherClass::kLepton, pCombo.mL2B[0]},
        {ExpectedCipherClass::kBaryon, 0U},
        {ExpectedCipherClass::kLepton, pCombo.mL2B[1]},
        {ExpectedCipherClass::kBaryon, 0U},
    };
    const ExpectedCipher aL1B[] = {
        {ExpectedCipherClass::kLepton, pCombo.mL1B[0]},
        {ExpectedCipherClass::kBaryon, 0U},
        {ExpectedCipherClass::kLepton, pCombo.mL1B[1]},
        {ExpectedCipherClass::kMuon, 0U},
    };
    const ExpectedCipher aL3C[] = {
        {ExpectedCipherClass::kLepton, pCombo.mL3C[0]},
        {ExpectedCipherClass::kBaryon, 0U},
        {ExpectedCipherClass::kLepton, pCombo.mL3C[1]},
    };

    return ValidateStage("L3A", pPlan.mL3A, aL3A, pFailure) &&
           ValidateStage("L2A", pPlan.mL2A, aL2A, pFailure) &&
           ValidateStage("L1A", pPlan.mL1A, aL1A, pFailure) &&
           ValidateStage("L3B", pPlan.mL3B, aL3B, pFailure) &&
           ValidateStage("L2B", pPlan.mL2B, aL2B, pFailure) &&
           ValidateStage("L1B", pPlan.mL1B, aL1B, pFailure) &&
           ValidateStage("L3C", pPlan.mL3C, aL3C, pFailure);
}

void FillCipherRing(CipherType *pCiphers) {
    constexpr CipherType aTypes[] = {
        CipherType::kPasswordXORCipher,
        CipherType::kPasswordJumpXORCipher,
        CipherType::kPepperJumpNoiseXORCipher,
        CipherType::kPepperDualJumpNoiseXORCipher,
        CipherType::kCascadeCipher,
        CipherType::kCascadeJumpCipher,
        CipherType::kRotateMaskCipher,
        CipherType::kRotateCipher,
        CipherType::kReverseMaskCipher,
        CipherType::kRippleMaskBlockCipher64,
    };

    for (std::size_t aIndex=0U; aIndex<SHUFFLED_CIPHERS_LENGTH; aIndex++) {
        pCiphers[aIndex] = aTypes[aIndex % (sizeof(aTypes) / sizeof(aTypes[0]))];
    }
}

} // namespace

@interface LaneCombosTest : XCTestCase

@end

@implementation LaneCombosTest

- (void)test_WeakPlansWorkInCpp {
    CipherType aCiphers[SHUFFLED_CIPHERS_LENGTH];
    FillCipherRing(aCiphers);

    for (std::size_t aIndex=0U; aIndex<LaneCombinations::mWeakCount; aIndex++) {
        const WeakLaneCombination aExpectedCombo = LaneCombinations::mWeak[aIndex];
        const WeakLaneCombination aPickedCombo = LaneCombinations::PickWeak(aIndex);
        if (std::memcmp(&aExpectedCombo, &aPickedCombo, sizeof(aExpectedCombo)) != 0) {
            XCTFail("test_WeakPlansWorkInCpp: PickWeak failed on combo %zu.", aIndex);
            return;
        }

        const EncryptionPlan aPlan = EncryptionPlanTool::MakePlanWeak(aIndex, aCiphers);
        PlanFailure aFailure;
        if (!ValidateWeakPlan(aPlan, aExpectedCombo, &aFailure)) {
            XCTFail("test_WeakPlansWorkInCpp: combo %zu, stage %s, slot %zu expected %s/%u lanes with stage count %zu; got cipher 0x%08X/%zu lanes with stage count %zu.",
                    aIndex,
                    aFailure.mStage,
                    aFailure.mSlot,
                    ClassName(aFailure.mExpected.mClass),
                    static_cast<unsigned int>(aFailure.mExpected.mLaneCount),
                    aFailure.mExpectedStageCount,
                    static_cast<unsigned int>(aFailure.mActual),
                    CipherTool::CountLanes(aFailure.mActual),
                    aFailure.mActualStageCount);
            return;
        }

        const RotationSummary aRotations = SummarizeRotations(aPlan);
        if ((aRotations.mRotationCount != 8U) ||
            (aRotations.mMaskedRotationCount != 2U) ||
            aRotations.mHasAdjacentRotations ||
            aRotations.mHasAdjacentKeys) {
            XCTFail("test_WeakPlansWorkInCpp: combo %zu expected 8 rotations, 2 masked, no adjacent rotations, and no adjacent keys; got %zu rotations, %zu masked, rotation adjacency at %s[%zu] = %s, key adjacency at %s[%zu] = %s.",
                    aIndex,
                    aRotations.mRotationCount,
                    aRotations.mMaskedRotationCount,
                    aRotations.mAdjacentRotationStage,
                    aRotations.mAdjacentRotationSlot,
                    aRotations.mHasAdjacentRotations ? "true" : "false",
                    aRotations.mAdjacentKeyStage,
                    aRotations.mAdjacentKeySlot,
                    aRotations.mHasAdjacentKeys ? "true" : "false");
            return;
        }
    }
}

- (void)test_NormalPlansWorkInCpp {
    CipherType aCiphers[SHUFFLED_CIPHERS_LENGTH];
    FillCipherRing(aCiphers);

    for (std::size_t aIndex=0U; aIndex<LaneCombinations::mNormalCount; aIndex++) {
        const NormalLaneCombination aExpectedCombo = LaneCombinations::mNormal[aIndex];
        const NormalLaneCombination aPickedCombo = LaneCombinations::PickNormal(aIndex);
        if (std::memcmp(&aExpectedCombo, &aPickedCombo, sizeof(aExpectedCombo)) != 0) {
            XCTFail("test_NormalPlansWorkInCpp: PickNormal failed on combo %zu.", aIndex);
            return;
        }

        const EncryptionPlan aPlan = EncryptionPlanTool::MakePlanNormal(aIndex, aCiphers);
        PlanFailure aFailure;
        if (!ValidateNormalPlan(aPlan, aExpectedCombo, &aFailure)) {
            XCTFail("test_NormalPlansWorkInCpp: combo %zu, stage %s, slot %zu expected %s/%u lanes with stage count %zu; got cipher 0x%08X/%zu lanes with stage count %zu.",
                    aIndex,
                    aFailure.mStage,
                    aFailure.mSlot,
                    ClassName(aFailure.mExpected.mClass),
                    static_cast<unsigned int>(aFailure.mExpected.mLaneCount),
                    aFailure.mExpectedStageCount,
                    static_cast<unsigned int>(aFailure.mActual),
                    CipherTool::CountLanes(aFailure.mActual),
                    aFailure.mActualStageCount);
            return;
        }

        const RotationSummary aRotations = SummarizeRotations(aPlan);
        if ((aRotations.mRotationCount != 8U) ||
            (aRotations.mMaskedRotationCount != 5U) ||
            aRotations.mHasAdjacentRotations ||
            aRotations.mHasAdjacentKeys) {
            XCTFail("test_NormalPlansWorkInCpp: combo %zu expected 8 rotations, 5 masked, no adjacent rotations, and no adjacent keys; got %zu rotations, %zu masked, rotation adjacency at %s[%zu] = %s, key adjacency at %s[%zu] = %s.",
                    aIndex,
                    aRotations.mRotationCount,
                    aRotations.mMaskedRotationCount,
                    aRotations.mAdjacentRotationStage,
                    aRotations.mAdjacentRotationSlot,
                    aRotations.mHasAdjacentRotations ? "true" : "false",
                    aRotations.mAdjacentKeyStage,
                    aRotations.mAdjacentKeySlot,
                    aRotations.mHasAdjacentKeys ? "true" : "false");
            return;
        }
    }
}

- (void)test_StrongPlansWorkInCpp {
    CipherType aCiphers[SHUFFLED_CIPHERS_LENGTH];
    FillCipherRing(aCiphers);

    for (std::size_t aIndex=0U; aIndex<LaneCombinations::mStrongCount; aIndex++) {
        const StrongLaneCombination aExpectedCombo = LaneCombinations::mStrong[aIndex];
        const StrongLaneCombination aPickedCombo = LaneCombinations::PickStrong(aIndex);
        if (std::memcmp(&aExpectedCombo, &aPickedCombo, sizeof(aExpectedCombo)) != 0) {
            XCTFail("test_StrongPlansWorkInCpp: PickStrong failed on combo %zu.", aIndex);
            return;
        }

        const EncryptionPlan aPlan = EncryptionPlanTool::MakePlanStrong(aIndex, aCiphers);
        PlanFailure aFailure;
        if (!ValidateStrongPlan(aPlan, aExpectedCombo, &aFailure)) {
            XCTFail("test_StrongPlansWorkInCpp: combo %zu, stage %s, slot %zu expected %s/%u lanes with stage count %zu; got cipher 0x%08X/%zu lanes with stage count %zu.",
                    aIndex,
                    aFailure.mStage,
                    aFailure.mSlot,
                    ClassName(aFailure.mExpected.mClass),
                    static_cast<unsigned int>(aFailure.mExpected.mLaneCount),
                    aFailure.mExpectedStageCount,
                    static_cast<unsigned int>(aFailure.mActual),
                    CipherTool::CountLanes(aFailure.mActual),
                    aFailure.mActualStageCount);
            return;
        }

        const RotationSummary aRotations = SummarizeRotations(aPlan);
        if ((aRotations.mRotationCount != 8U) ||
            (aRotations.mMaskedRotationCount != 8U) ||
            aRotations.mHasAdjacentRotations ||
            aRotations.mHasAdjacentKeys) {
            XCTFail("test_StrongPlansWorkInCpp: combo %zu expected 8 rotations, 8 masked, no adjacent rotations, and no adjacent keys; got %zu rotations, %zu masked, rotation adjacency at %s[%zu] = %s, key adjacency at %s[%zu] = %s.",
                    aIndex,
                    aRotations.mRotationCount,
                    aRotations.mMaskedRotationCount,
                    aRotations.mAdjacentRotationStage,
                    aRotations.mAdjacentRotationSlot,
                    aRotations.mHasAdjacentRotations ? "true" : "false",
                    aRotations.mAdjacentKeyStage,
                    aRotations.mAdjacentKeySlot,
                    aRotations.mHasAdjacentKeys ? "true" : "false");
            return;
        }
    }
}

@end
