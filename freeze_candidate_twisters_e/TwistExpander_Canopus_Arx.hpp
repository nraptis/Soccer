#pragma once

#include "TwistExpander.hpp"

class TwistExpander_Canopus_Arx {
public:
    static void KDF_A_A_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_B_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_C_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_D_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_A_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_B_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_C_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_D_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_A_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_B_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_C_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_D_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_D_A_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_D_B_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_D_C_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_D_D_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_A_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_B_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_C_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_D_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_A_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_B_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_C_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_D_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_A_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_B_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_C_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_D_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_D_A_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_D_B_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_D_C_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_D_D_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_A_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_B_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_C_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_D_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_A_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_B_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_C_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_D_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_A_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_B_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_C_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_D_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_D_A_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_D_B_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_D_C_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_D_D_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_A_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_B_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_C_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_D_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_A_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_B_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_C_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_D_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_A_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_B_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_C_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_D_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_D_A_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_D_B_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_D_C_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_D_D_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_A_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_B_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_C_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_D_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_A_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_B_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_C_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_D_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_A_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_B_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_C_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_D_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_D_A_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_D_B_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_D_C_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_D_D_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_A_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_B_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_C_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_D_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_A_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_B_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_C_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_D_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_A_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_B_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_C_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_D_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_D_A_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_D_B_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_D_C_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_D_D_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void SEED_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void SEED_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void SEED_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void SEED_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void SEED_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void SEED_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void SEED_G(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void SEED_H(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void SEED_I(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void SEED_J(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void SEED_K(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void SEED_L(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void SEED_M(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void SEED_N(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_G(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_H(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_G(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_H(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void TWIST_A(TwistWorkSpace *pWorkSpace,
                     std::uint8_t *pSource,
                     std::uint8_t *pCrossLaneA,
                     std::uint8_t *pCrossLaneB,
                     std::uint8_t *pCrossLaneC,
                     std::uint8_t *pCrossLaneD,
                     MUTABLE_PARAMS);
    static void TWIST_B(TwistWorkSpace *pWorkSpace,
                     std::uint8_t *pSource,
                     std::uint8_t *pCrossLaneA,
                     std::uint8_t *pCrossLaneB,
                     std::uint8_t *pCrossLaneC,
                     std::uint8_t *pCrossLaneD,
                     MUTABLE_PARAMS);
    static void TWIST_C(TwistWorkSpace *pWorkSpace,
                     std::uint8_t *pSource,
                     std::uint8_t *pCrossLaneA,
                     std::uint8_t *pCrossLaneB,
                     std::uint8_t *pCrossLaneC,
                     std::uint8_t *pCrossLaneD,
                     MUTABLE_PARAMS);
    static void TWIST_D(TwistWorkSpace *pWorkSpace,
                     std::uint8_t *pSource,
                     std::uint8_t *pCrossLaneA,
                     std::uint8_t *pCrossLaneB,
                     std::uint8_t *pCrossLaneC,
                     std::uint8_t *pCrossLaneD,
                     MUTABLE_PARAMS);
    static void TWIST_E(TwistWorkSpace *pWorkSpace,
                     std::uint8_t *pSource,
                     std::uint8_t *pCrossLaneA,
                     std::uint8_t *pCrossLaneB,
                     std::uint8_t *pCrossLaneC,
                     std::uint8_t *pCrossLaneD,
                     MUTABLE_PARAMS);
    static void TWIST_F(TwistWorkSpace *pWorkSpace,
                     std::uint8_t *pSource,
                     std::uint8_t *pCrossLaneA,
                     std::uint8_t *pCrossLaneB,
                     std::uint8_t *pCrossLaneC,
                     std::uint8_t *pCrossLaneD,
                     MUTABLE_PARAMS);
    static void TWIST_G(TwistWorkSpace *pWorkSpace,
                     std::uint8_t *pSource,
                     std::uint8_t *pCrossLaneA,
                     std::uint8_t *pCrossLaneB,
                     std::uint8_t *pCrossLaneC,
                     std::uint8_t *pCrossLaneD,
                     MUTABLE_PARAMS);
    static void TWIST_H(TwistWorkSpace *pWorkSpace,
                     std::uint8_t *pSource,
                     std::uint8_t *pCrossLaneA,
                     std::uint8_t *pCrossLaneB,
                     std::uint8_t *pCrossLaneC,
                     std::uint8_t *pCrossLaneD,
                     MUTABLE_PARAMS);
    static void GROW_A_A(TwistWorkSpace *pWorkSpace,
                     MUTABLE_PARAMS);
    static void GROW_A_B(TwistWorkSpace *pWorkSpace,
                     MUTABLE_PARAMS);
    static void GROW_A_C(TwistWorkSpace *pWorkSpace,
                     MUTABLE_PARAMS);
    static void GROW_A_D(TwistWorkSpace *pWorkSpace,
                     MUTABLE_PARAMS);
    static void GROW_A_E(TwistWorkSpace *pWorkSpace,
                     MUTABLE_PARAMS);
    static void GROW_B_A(TwistWorkSpace *pWorkSpace,
                     MUTABLE_PARAMS);
    static void GROW_B_B(TwistWorkSpace *pWorkSpace,
                     MUTABLE_PARAMS);
    static void GROW_B_C(TwistWorkSpace *pWorkSpace,
                     MUTABLE_PARAMS);
    static void GROW_B_D(TwistWorkSpace *pWorkSpace,
                     MUTABLE_PARAMS);
    static void GROW_B_E(TwistWorkSpace *pWorkSpace,
                     MUTABLE_PARAMS);
};
