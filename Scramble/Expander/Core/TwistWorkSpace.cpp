//
//  TwistWorkSpace.cpp
//  Gorgon
//

#include "TwistWorkSpace.hpp"
#include "TwistExpander.hpp"
#include <cstring>

TwistBufferKey TwistBufferKey::Salt(TwistSaltOwner pOwner,
                                    TwistDomain pDomain,
                                    TwistWorkSpaceSlot pSlot) {
    TwistBufferKey aKey;
    aKey.mKind = TwistBufferKind::kSalt;
    aKey.mSaltOwner = pOwner;
    aKey.mDomain = pDomain;
    aKey.mSlot = static_cast<std::uint16_t>(pSlot);
    return aKey;
}

TwistBufferKey TwistBufferKey::Constants(TwistSaltOwner pOwner,
                                         TwistDomain pDomain) {
    TwistBufferKey aKey;
    aKey.mKind = TwistBufferKind::kConstants;
    aKey.mSaltOwner = pOwner;
    aKey.mDomain = pDomain;
    return aKey;
}

bool TwistBufferKey::IsValid() const {
    return mKind != TwistBufferKind::kInvalid;
}

bool TwistBufferKey::IsSalt() const {
    return mKind == TwistBufferKind::kSalt;
}

bool TwistBufferKey::IsConstants() const {
    return mKind == TwistBufferKind::kConstants;
}

TwistDomainBundle *TwistWorkSpace::GetSaltDomainBundle(TwistExpander *pExpander,
                                                        TwistSaltOwner pOwner) {
    switch (pOwner) {
        case TwistSaltOwner::kInbuilt:
            return pExpander ? pExpander->GetDomainBundleInbuilt() : nullptr;
        case TwistSaltOwner::kEphemeral:
            return pExpander ? pExpander->GetDomainBundleEphemeral() : nullptr;
        default:
            return nullptr;
    }
}

namespace {

TwistDomainSaltSet *GetSaltSet(TwistDomainBundle *pBundle,
                               TwistDomain pDomain) {
    if (pBundle == nullptr) {
        return nullptr;
    }
    switch (pDomain) {
        case TwistDomain::kPhaseA: return &pBundle->mPhaseASalts;
        case TwistDomain::kPhaseB: return &pBundle->mPhaseBSalts;
        case TwistDomain::kPhaseC: return &pBundle->mPhaseCSalts;
        case TwistDomain::kPhaseD: return &pBundle->mPhaseDSalts;
        default: return nullptr;
    }
}

TwistDomainConstants *GetDomainConstants(TwistDomainBundle *pBundle,
                                         TwistDomain pDomain) {
    if (pBundle == nullptr) {
        return nullptr;
    }
    switch (pDomain) {
        case TwistDomain::kPhaseA: return &pBundle->mPhaseAConstants;
        case TwistDomain::kPhaseB: return &pBundle->mPhaseBConstants;
        case TwistDomain::kPhaseC: return &pBundle->mPhaseCConstants;
        case TwistDomain::kPhaseD: return &pBundle->mPhaseDConstants;
        default: return nullptr;
    }
}

std::uint64_t *GetSaltLane(TwistDomainSeedRoundMaterial *pMaterial,
                           int pLane) {
    if (pMaterial == nullptr) {
        return nullptr;
    }
    switch (pLane) {
        case 0: return pMaterial->mSaltA;
        case 1: return pMaterial->mSaltB;
        case 2: return pMaterial->mSaltC;
        case 3: return pMaterial->mSaltD;
        case 4: return pMaterial->mSaltE;
        case 5: return pMaterial->mSaltF;
        default: return nullptr;
    }
}

TwistDomainSeedRoundMaterial *GetSaltMaterial(TwistDomainSaltSet *pSet,
                                              int pRole) {
    if (pSet == nullptr) {
        return nullptr;
    }
    switch (pRole) {
        case 0: return &pSet->mOrbiterAssign;
        case 1: return &pSet->mOrbiterUpdate;
        case 2: return &pSet->mWandererUpdate;
        default: return nullptr;
    }
}

bool DecodeParamSaltSlot(TwistWorkSpaceSlot pSlot,
                         int *pRoleOut,
                         int *pLaneOut) {
    const int aValue = static_cast<int>(pSlot);
    const int aBase = static_cast<int>(TwistWorkSpaceSlot::kParamDomainSaltOrbiterAssignA);
    const int aCount = 18;
    if ((aValue < aBase) || (aValue >= (aBase + aCount))) {
        return false;
    }
    const int aOffset = aValue - aBase;
    if (pRoleOut != nullptr) {
        *pRoleOut = aOffset / 6;
    }
    if (pLaneOut != nullptr) {
        *pLaneOut = aOffset % 6;
    }
    return true;
}

bool DecodePhaseSaltSlot(TwistWorkSpaceSlot pSlot,
                         TwistDomain *pDomainOut,
                         int *pRoleOut,
                         int *pLaneOut) {
    const int aValue = static_cast<int>(pSlot);
    const int aBase = static_cast<int>(TwistWorkSpaceSlot::kPhaseASaltOrbiterAssignA);
    const int aCountPerPhase = 18;
    const int aPhaseCount = 4;
    if ((aValue < aBase) || (aValue >= (aBase + aCountPerPhase * aPhaseCount))) {
        return false;
    }

    const int aOffset = aValue - aBase;
    const int aPhaseIndex = aOffset / aCountPerPhase;
    const int aRoleLaneOffset = aOffset % aCountPerPhase;
    if (pDomainOut != nullptr) {
        *pDomainOut = static_cast<TwistDomain>(static_cast<int>(TwistDomain::kPhaseA) + aPhaseIndex);
    }
    if (pRoleOut != nullptr) {
        *pRoleOut = aRoleLaneOffset / 6;
    }
    if (pLaneOut != nullptr) {
        *pLaneOut = aRoleLaneOffset % 6;
    }
    return true;
}

std::uint64_t *GetSaltSlot(TwistDomainSaltSet *pSet,
                           int pRole,
                           int pLane) {
    return GetSaltLane(GetSaltMaterial(pSet, pRole), pLane);
}

std::uint64_t *GetParamSaltSlot(TwistDomainSaltSet *pSet,
                                TwistWorkSpaceSlot pSlot) {
    int aRole = 0;
    int aLane = 0;
    if (!DecodeParamSaltSlot(pSlot, &aRole, &aLane)) {
        return nullptr;
    }
    return GetSaltSlot(pSet, aRole, aLane);
}

std::uint64_t *GetPhaseSaltSlot(TwistWorkSpace *pWorkSpace,
                                TwistWorkSpaceSlot pSlot) {
    if (pWorkSpace == nullptr) {
        return nullptr;
    }
    TwistDomain aDomain = TwistDomain::kInvalid;
    int aRole = 0;
    int aLane = 0;
    if (!DecodePhaseSaltSlot(pSlot, &aDomain, &aRole, &aLane)) {
        return nullptr;
    }
    return GetSaltSlot(GetSaltSet(&pWorkSpace->mDomainBundle, aDomain), aRole, aLane);
}

} // namespace

TwistWorkSpace::TwistWorkSpace() {
    std::memset(this, 0, sizeof(*this));
}

void TwistWorkSpace::ShiftKeyBoxA(std::uint8_t *pBox) {
    std::uint8_t *aDest = pBox + (H_KEY - 1) * W_KEY;
    std::uint8_t *aSource = aDest - W_KEY;
    for (int i = 0; i < (H_KEY - 1); i++) {
        std::memcpy(aDest, aSource, W_KEY);
        aDest = aSource;
        aSource = aDest - W_KEY;
    }
}

void TwistWorkSpace::ShiftKeyBoxB(std::uint8_t *pBox) {
    std::uint8_t *aDest = pBox + (H_KEY - 1) * W_KEY;
    std::uint8_t *aSource = aDest - W_KEY;
    for (int i = 0; i < (H_KEY - 1); i++) {
        std::memcpy(aDest, aSource, W_KEY);
        aDest = aSource;
        aSource = aDest - W_KEY;
    }
}

std::uint8_t *TwistWorkSpace::GetBuffer(TwistWorkSpace *pWorkSpace,
                                        TwistExpander *pExpander,
                                        TwistWorkSpaceSlot pSlot) {
    return GetBuffer(pWorkSpace,
                     pExpander,
                     pSlot,
                     nullptr,
                     nullptr);
}

std::uint8_t *TwistWorkSpace::GetBuffer(TwistWorkSpace *pWorkSpace,
                                        TwistExpander *pExpander,
                                        TwistWorkSpaceSlot pSlot,
                                        std::uint8_t *pParamSource,
                                        std::uint8_t *pParamDestination) {
    return GetBuffer(pWorkSpace,
                     pExpander,
                     pSlot,
                     pParamSource,
                     pParamDestination,
                     nullptr);
}

std::uint8_t *TwistWorkSpace::GetBuffer(TwistWorkSpace *pWorkSpace,
                                        TwistExpander *pExpander,
                                        TwistWorkSpaceSlot pSlot,
                                        std::uint8_t *pParamSource,
                                        std::uint8_t *pParamDestination,
                                        TwistDomainSaltSet *pParamSaltSet) {
    if (pWorkSpace == nullptr) {
        return nullptr;
    }

    if (pExpander == nullptr) {
        if (DecodeParamSaltSlot(pSlot, nullptr, nullptr) &&
            (pParamSaltSet == nullptr)) {
            return nullptr;
        }
        switch (pSlot) {
            case TwistWorkSpaceSlot::kParamSnow:
            case TwistWorkSpaceSlot::kIndexList256A:
            case TwistWorkSpaceSlot::kIndexList256B:
            case TwistWorkSpaceSlot::kIndexList256C:
            case TwistWorkSpaceSlot::kIndexList256D:
                return nullptr;
            default:
                break;
        }
    }

    switch (pSlot) {
        case TwistWorkSpaceSlot::kSource: return pWorkSpace->mSource;
        case TwistWorkSpaceSlot::kParamSource: return pParamSource;
        case TwistWorkSpaceSlot::kParamDestination: return pParamDestination;
        case TwistWorkSpaceSlot::kParamSnow: return nullptr;
        case TwistWorkSpaceSlot::kHeartLaneA: return pWorkSpace->mHeartLaneA;
        case TwistWorkSpaceSlot::kHeartLaneB: return pWorkSpace->mHeartLaneB;
        case TwistWorkSpaceSlot::kHeartLaneC: return pWorkSpace->mHeartLaneC;
        case TwistWorkSpaceSlot::kHeartLaneD: return pWorkSpace->mHeartLaneD;
        case TwistWorkSpaceSlot::kPoisonLaneA: return pWorkSpace->mPoisonLaneA;
        case TwistWorkSpaceSlot::kPoisonLaneB: return pWorkSpace->mPoisonLaneB;
        case TwistWorkSpaceSlot::kPoisonLaneC: return pWorkSpace->mPoisonLaneC;
        case TwistWorkSpaceSlot::kPoisonLaneD: return pWorkSpace->mPoisonLaneD;
        case TwistWorkSpaceSlot::kSpiritLaneA: return pWorkSpace->mSpiritLaneA;
        case TwistWorkSpaceSlot::kSpiritLaneB: return pWorkSpace->mSpiritLaneB;
        case TwistWorkSpaceSlot::kSpiritLaneC: return pWorkSpace->mSpiritLaneC;
        case TwistWorkSpaceSlot::kSpiritLaneD: return pWorkSpace->mSpiritLaneD;
        case TwistWorkSpaceSlot::kSnowLaneA: return pWorkSpace->mHeartLaneA;
        case TwistWorkSpaceSlot::kSnowLaneB: return pWorkSpace->mHeartLaneB;
        case TwistWorkSpaceSlot::kSnowLaneC: return pWorkSpace->mHeartLaneC;
        case TwistWorkSpaceSlot::kSnowLaneD: return pWorkSpace->mHeartLaneD;
        case TwistWorkSpaceSlot::kFireLaneA: return pWorkSpace->mFireLaneA;
        case TwistWorkSpaceSlot::kFireLaneB: return pWorkSpace->mFireLaneB;
        case TwistWorkSpaceSlot::kFireLaneC: return pWorkSpace->mFireLaneC;
        case TwistWorkSpaceSlot::kFireLaneD: return pWorkSpace->mFireLaneD;
        case TwistWorkSpaceSlot::kWaterLaneA: return pWorkSpace->mWaterLaneA;
        case TwistWorkSpaceSlot::kWaterLaneB: return pWorkSpace->mWaterLaneB;
        case TwistWorkSpaceSlot::kWaterLaneC: return pWorkSpace->mWaterLaneC;
        case TwistWorkSpaceSlot::kWaterLaneD: return pWorkSpace->mWaterLaneD;
        case TwistWorkSpaceSlot::kEarthLaneA: return pWorkSpace->mEarthLaneA;
        case TwistWorkSpaceSlot::kEarthLaneB: return pWorkSpace->mEarthLaneB;
        case TwistWorkSpaceSlot::kEarthLaneC: return pWorkSpace->mEarthLaneC;
        case TwistWorkSpaceSlot::kEarthLaneD: return pWorkSpace->mEarthLaneD;
        case TwistWorkSpaceSlot::kWindLaneA: return pWorkSpace->mWindLaneA;
        case TwistWorkSpaceSlot::kWindLaneB: return pWorkSpace->mWindLaneB;
        case TwistWorkSpaceSlot::kWindLaneC: return pWorkSpace->mWindLaneC;
        case TwistWorkSpaceSlot::kWindLaneD: return pWorkSpace->mWindLaneD;
        case TwistWorkSpaceSlot::kFuseLaneA: return pWorkSpace->mFuseLaneA;
        case TwistWorkSpaceSlot::kFuseLaneB: return pWorkSpace->mFuseLaneB;
        case TwistWorkSpaceSlot::kFuseLaneC: return pWorkSpace->mFuseLaneC;
        case TwistWorkSpaceSlot::kFuseLaneD: return pWorkSpace->mFuseLaneD;
        case TwistWorkSpaceSlot::kWoodLaneA: return pWorkSpace->mWoodLaneA;
        case TwistWorkSpaceSlot::kWoodLaneB: return pWorkSpace->mWoodLaneB;
        case TwistWorkSpaceSlot::kWoodLaneC: return pWorkSpace->mWoodLaneC;
        case TwistWorkSpaceSlot::kWoodLaneD: return pWorkSpace->mWoodLaneD;
        case TwistWorkSpaceSlot::kIceLaneA: return pWorkSpace->mIceLaneA;
        case TwistWorkSpaceSlot::kIceLaneB: return pWorkSpace->mIceLaneB;
        case TwistWorkSpaceSlot::kIceLaneC: return pWorkSpace->mIceLaneC;
        case TwistWorkSpaceSlot::kIceLaneD: return pWorkSpace->mIceLaneD;
        case TwistWorkSpaceSlot::kIndexList256A: return reinterpret_cast<std::uint8_t *>(pExpander->mIndexList256A);
        case TwistWorkSpaceSlot::kIndexList256B: return reinterpret_cast<std::uint8_t *>(pExpander->mIndexList256B);
        case TwistWorkSpaceSlot::kIndexList256C: return reinterpret_cast<std::uint8_t *>(pExpander->mIndexList256C);
        case TwistWorkSpaceSlot::kIndexList256D: return reinterpret_cast<std::uint8_t *>(pExpander->mIndexList256D);
        case TwistWorkSpaceSlot::kKeyBoxUnrolledA: return &(pWorkSpace->mKeyBoxA[0][0]);
        case TwistWorkSpaceSlot::kKeyBoxUnrolledB: return &(pWorkSpace->mKeyBoxB[0][0]);
        case TwistWorkSpaceSlot::kKeyRowReadA: return &(pWorkSpace->mKeyBoxA[H_KEY - 1][0]);
        case TwistWorkSpaceSlot::kKeyRowReadB: return &(pWorkSpace->mKeyBoxB[H_KEY - 1][0]);
        case TwistWorkSpaceSlot::kKeyRowWriteA: return &(pWorkSpace->mKeyBoxA[0][0]);
        case TwistWorkSpaceSlot::kKeyRowWriteB: return &(pWorkSpace->mKeyBoxB[0][0]);
            
        default:
            break;
    }

    if (DecodeParamSaltSlot(pSlot, nullptr, nullptr)) {
        return reinterpret_cast<std::uint8_t *>(
            GetParamSaltSlot(pParamSaltSet, pSlot)
        );
    }

    if (DecodePhaseSaltSlot(pSlot, nullptr, nullptr, nullptr)) {
        return reinterpret_cast<std::uint8_t *>(GetPhaseSaltSlot(pWorkSpace, pSlot));
    }

    return pWorkSpace->mPoisonLaneA;
}

std::uint8_t *TwistWorkSpace::GetBuffer(TwistWorkSpace *pWorkSpace,
                                        TwistWorkSpaceSlot pSlot) {
    return GetBuffer(pWorkSpace, nullptr, pSlot);
}

std::uint8_t *TwistWorkSpace::GetBuffer(TwistWorkSpace *pWorkSpace,
                                        TwistExpander *pExpander,
                                        TwistBufferKey pKey) {
    (void)pWorkSpace;
    if (!pKey.IsValid()) {
        return nullptr;
    }

    if (pKey.IsSalt()) {
        TwistDomainBundle *aBundle = GetSaltDomainBundle(pExpander, pKey.mSaltOwner);
        TwistDomainSaltSet *aSet = GetSaltSet(aBundle, pKey.mDomain);
        const TwistWorkSpaceSlot aSlot = static_cast<TwistWorkSpaceSlot>(pKey.mSlot);
        std::uint64_t *aLane = GetParamSaltSlot(aSet, aSlot);
        if (aLane == nullptr) {
            int aRole = 0;
            int aLaneIndex = 0;
            if (DecodePhaseSaltSlot(aSlot, nullptr, &aRole, &aLaneIndex)) {
                aLane = GetSaltSlot(aSet, aRole, aLaneIndex);
            }
        }
        return reinterpret_cast<std::uint8_t *>(aLane);
    }

    if (pKey.IsConstants()) {
        TwistDomainBundle *aBundle = GetSaltDomainBundle(pExpander, pKey.mSaltOwner);
        TwistDomainConstants *aConstants = GetDomainConstants(aBundle, pKey.mDomain);
        return reinterpret_cast<std::uint8_t *>(aConstants);
    }

    return nullptr;
}

std::uint8_t *TwistWorkSpace::GetBuffer(TwistWorkSpace *pWorkSpace,
                                        TwistBufferKey pKey) {
    return GetBuffer(pWorkSpace, nullptr, pKey);
}

int TwistWorkSpace::GetBufferLength(TwistWorkSpaceSlot pSlot) {
    if (DecodeParamSaltSlot(pSlot, nullptr, nullptr) ||
        DecodePhaseSaltSlot(pSlot, nullptr, nullptr, nullptr)) {
        return S_SALT;
    }

    switch (pSlot) {
        case TwistWorkSpaceSlot::kKeyBoxUnrolledA: return S_KEY;
        case TwistWorkSpaceSlot::kKeyBoxUnrolledB: return S_KEY;
        case TwistWorkSpaceSlot::kKeyRowReadA:
        case TwistWorkSpaceSlot::kKeyRowWriteA: return W_KEY;
        case TwistWorkSpaceSlot::kKeyRowReadB:
        case TwistWorkSpaceSlot::kKeyRowWriteB: return W_KEY;

        case TwistWorkSpaceSlot::kIndexList256A:
        case TwistWorkSpaceSlot::kIndexList256B:
        case TwistWorkSpaceSlot::kIndexList256C:
        case TwistWorkSpaceSlot::kIndexList256D:
            return static_cast<int>(256U * sizeof(std::size_t));

        default:
            return S_BLOCK;
    }
}

int TwistWorkSpace::GetBufferLength(TwistBufferKey pKey) {
    switch (pKey.mKind) {
        case TwistBufferKind::kSalt:
            return static_cast<int>(S_SALT * sizeof(std::uint64_t));

        case TwistBufferKind::kConstants:
            return static_cast<int>(sizeof(TwistDomainConstants));

        default:
            return 0;
    }
}

bool TwistWorkSpace::IsSalt(TwistWorkSpaceSlot pSlot) {
    if (DecodeParamSaltSlot(pSlot, nullptr, nullptr) ||
        DecodePhaseSaltSlot(pSlot, nullptr, nullptr, nullptr)) {
        return true;
    }
    return false;
}

bool TwistWorkSpace::IsSalt(TwistBufferKey pKey) {
    return pKey.mKind == TwistBufferKind::kSalt;
}

void TwistWorkSpace::Zero() {
    Zero_PostSeed();
    mDomainBundle.Zero();
}

void TwistWorkSpace::Zero_PostSeed() {
 
    memset(mSource, 0, sizeof(mSource));

    memset(mHeartLaneA, 0, sizeof(mHeartLaneA));
    memset(mHeartLaneB, 0, sizeof(mHeartLaneB));
    memset(mHeartLaneC, 0, sizeof(mHeartLaneC));
    memset(mHeartLaneD, 0, sizeof(mHeartLaneD));
    
    memset(mPoisonLaneA, 0, sizeof(mPoisonLaneA));
    memset(mPoisonLaneB, 0, sizeof(mPoisonLaneB));
    memset(mPoisonLaneC, 0, sizeof(mPoisonLaneC));
    memset(mPoisonLaneD, 0, sizeof(mPoisonLaneD));
    
    memset(mSpiritLaneA, 0, sizeof(mSpiritLaneA));
    memset(mSpiritLaneB, 0, sizeof(mSpiritLaneB));
    memset(mSpiritLaneC, 0, sizeof(mSpiritLaneC));
    memset(mSpiritLaneD, 0, sizeof(mSpiritLaneD));
    
    memset(mFireLaneA, 0, sizeof(mFireLaneA));
    memset(mFireLaneB, 0, sizeof(mFireLaneB));
    memset(mFireLaneC, 0, sizeof(mFireLaneC));
    memset(mFireLaneD, 0, sizeof(mFireLaneD));

    memset(mWaterLaneA, 0, sizeof(mWaterLaneA));
    memset(mWaterLaneB, 0, sizeof(mWaterLaneB));
    memset(mWaterLaneC, 0, sizeof(mWaterLaneC));
    memset(mWaterLaneD, 0, sizeof(mWaterLaneD));

    memset(mEarthLaneA, 0, sizeof(mEarthLaneA));
    memset(mEarthLaneB, 0, sizeof(mEarthLaneB));
    memset(mEarthLaneC, 0, sizeof(mEarthLaneC));
    memset(mEarthLaneD, 0, sizeof(mEarthLaneD));

    memset(mWindLaneA, 0, sizeof(mWindLaneA));
    memset(mWindLaneB, 0, sizeof(mWindLaneB));
    memset(mWindLaneC, 0, sizeof(mWindLaneC));
    memset(mWindLaneD, 0, sizeof(mWindLaneD));

    memset(mFuseLaneA, 0, sizeof(mFuseLaneA));
    memset(mFuseLaneB, 0, sizeof(mFuseLaneB));
    memset(mFuseLaneC, 0, sizeof(mFuseLaneC));
    memset(mFuseLaneD, 0, sizeof(mFuseLaneD));

    memset(mWoodLaneA, 0, sizeof(mWoodLaneA));
    memset(mWoodLaneB, 0, sizeof(mWoodLaneB));
    memset(mWoodLaneC, 0, sizeof(mWoodLaneC));
    memset(mWoodLaneD, 0, sizeof(mWoodLaneD));

    memset(mIceLaneA, 0, sizeof(mIceLaneA));
    memset(mIceLaneB, 0, sizeof(mIceLaneB));
    memset(mIceLaneC, 0, sizeof(mIceLaneC));
    memset(mIceLaneD, 0, sizeof(mIceLaneD));
    
}
