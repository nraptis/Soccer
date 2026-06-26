//
//  TwistExpander.hpp
//  MeanMachine
//

#ifndef TwistExpander_hpp
#define TwistExpander_hpp

#include "TwistWorkSpace.hpp"

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>
#include "M88/M88.hpp"



class TwistFarmSalt;

class TwistExpanderArx;

class TwistExpander {
public:
    
    TwistExpander();
    
    virtual ~TwistExpander();

    static void                             UnrollPasswordToSource(std::uint8_t *pSource,
                                                                   std::uint8_t *pPassword,
                                                                   const unsigned int pPasswordByteLength);
    static void                             UnrollPasswordToSource(std::uint8_t *pSource,
                                                                   std::uint8_t *pPassword,
                                                                   const unsigned int pPasswordByteLength,
                                                                   const unsigned int pSourceByteLength);
    
    virtual void                            KDF(std::uint64_t pNonce,
                                                TwistDomainConstants *pDomainConstants,
                                                TwistDomainSaltSet *pDomainSaltSet);

    virtual void                            KDF_A(std::uint64_t pNonce,
                                                  TwistDomainConstants *pDomainConstants,
                                                  TwistDomainSaltSet *pDomainSaltSet);

    virtual void                            KDF_B(std::uint64_t pNonce,
                                                  TwistDomainConstants *pDomainConstants,
                                                  TwistDomainSaltSet *pDomainSaltSet);

    virtual void                            Seed(TwistWorkSpace *pWorkSpace,
                                                 TwistFarmSalt *pFarmSalt,
                                                 std::uint64_t pNonce,
                                                 std::uint8_t *pSource,
                                                 std::uint8_t *pPassword,
                                                 unsigned int pPasswordByteLength,
                                                 std::uint8_t *pDestination);

    virtual void                            TwistBlock(TwistWorkSpace *pWorkSpace,
                                                       std::uint64_t pNonce,
                                                       std::uint8_t *pSource,
                                                       std::size_t pBlockIndex,
                                                       std::size_t pBlockCount,
                                                       
                                                       std::uint8_t *pDestination);
    
    virtual void                            SquashInvestToKeyBoxes();
    
    virtual void                            GrowKeyA(TwistWorkSpace *pWorkSpace);
    virtual void                            GrowKeyB(TwistWorkSpace *pWorkSpace);
    
    
    // this is not virtual, it calls TwistBlock on every block
    void                                    Twist(TwistWorkSpace *pWorkSpace,
                                                  std::uint64_t pNonce,
                                                  std::uint8_t *pSource,
                                                  std::uint8_t *pDestination,
                                                  unsigned int pDestinationByteLength);
    
    
    std::size_t                             mIndexList256A[256];
    std::size_t                             mIndexList256B[256];
    std::size_t                             mIndexList256C[256];
    std::size_t                             mIndexList256D[256];

    TwistDomainConstants                    *mActiveConstants;
    TwistDomainSaltSet                      *mActiveSaltSet;
    
    std::uint8_t                            *mSource;
    std::uint8_t                            *mSnow;
    std::uint8_t                            *mDest;
    
    M88                                     mMatrix;

    TwistFarmSalt                           *GetFarmSalt() const;
    std::uint64_t                           GetSessionNonce() const;

    TwistDomainBundle                       mDomainBundleInbuilt;
    TwistDomainBundle                       mDomainBundleEphemeral;
    
    TwistWorkSpace                          *mWorkspace;
    
    void                                    Zero_PostSeed();
    void                                    Zero();
    
protected:
    
    
    TwistFarmSalt                           *mFarmSalt;
    std::uint64_t                           mKDFCallCounter;
    std::uint64_t                           mKDFSessionNonce;
    
};


class TwistExpanderArx {
  
public:
    virtual ~TwistExpanderArx() = default;

    virtual void                            KDF_A_A(TwistWorkSpace *pWorkSpace,
                                                    std::uint64_t pNonce,
                                                    TwistDomainConstants *pConstants,
                                                    TwistDomainSaltSet *pDomainSaltSet,
                                                    std::uint8_t *pSource,
                                                    std::uint8_t *pSnow,
                                                    std::uint64_t *pPrevious,
                                                    std::uint64_t *pIngress,
                                                    std::uint64_t *pCarry,
                                                    std::uint64_t *pWandererA,
                                                    std::uint64_t *pWandererB,
                                                    std::uint64_t *pWandererC,
                                                    std::uint64_t *pWandererD,
                                                    std::uint64_t *pWandererE,
                                                    std::uint64_t *pWandererF,
                                                    std::uint64_t *pWandererG,
                                                    std::uint64_t *pWandererH,
                                                    std::uint64_t *pWandererI,
                                                    std::uint64_t *pWandererJ,
                                                    std::uint64_t *pWandererK) = 0;

    virtual void                            KDF_A_B(TwistWorkSpace *pWorkSpace,
                                                    std::uint64_t pNonce,
                                                    TwistDomainConstants *pConstants,
                                                    TwistDomainSaltSet *pDomainSaltSet,
                                                    std::uint8_t *pSource,
                                                    std::uint64_t *pPrevious,
                                                    std::uint64_t *pIngress,
                                                    std::uint64_t *pCarry,
                                                    std::uint64_t *pWandererA,
                                                    std::uint64_t *pWandererB,
                                                    std::uint64_t *pWandererC,
                                                    std::uint64_t *pWandererD,
                                                    std::uint64_t *pWandererE,
                                                    std::uint64_t *pWandererF,
                                                    std::uint64_t *pWandererG,
                                                    std::uint64_t *pWandererH,
                                                    std::uint64_t *pWandererI,
                                                    std::uint64_t *pWandererJ,
                                                    std::uint64_t *pWandererK) = 0;

    virtual void                            KDF_A_C(TwistWorkSpace *pWorkSpace,
                                                    std::uint64_t pNonce,
                                                    TwistDomainConstants *pConstants,
                                                    TwistDomainSaltSet *pDomainSaltSet,
                                                    std::uint8_t *pSource,
                                                    std::uint64_t *pPrevious,
                                                    std::uint64_t *pIngress,
                                                    std::uint64_t *pCarry,
                                                    std::uint64_t *pWandererA,
                                                    std::uint64_t *pWandererB,
                                                    std::uint64_t *pWandererC,
                                                    std::uint64_t *pWandererD,
                                                    std::uint64_t *pWandererE,
                                                    std::uint64_t *pWandererF,
                                                    std::uint64_t *pWandererG,
                                                    std::uint64_t *pWandererH,
                                                    std::uint64_t *pWandererI,
                                                    std::uint64_t *pWandererJ,
                                                    std::uint64_t *pWandererK) = 0;

    virtual void                            KDF_A_D(TwistWorkSpace *pWorkSpace,
                                                    std::uint64_t pNonce,
                                                    TwistDomainConstants *pConstants,
                                                    TwistDomainSaltSet *pDomainSaltSet,
                                                    std::uint8_t *pSource,
                                                    std::uint64_t *pPrevious,
                                                    std::uint64_t *pIngress,
                                                    std::uint64_t *pCarry,
                                                    std::uint64_t *pWandererA,
                                                    std::uint64_t *pWandererB,
                                                    std::uint64_t *pWandererC,
                                                    std::uint64_t *pWandererD,
                                                    std::uint64_t *pWandererE,
                                                    std::uint64_t *pWandererF,
                                                    std::uint64_t *pWandererG,
                                                    std::uint64_t *pWandererH,
                                                    std::uint64_t *pWandererI,
                                                    std::uint64_t *pWandererJ,
                                                    std::uint64_t *pWandererK) = 0;

    virtual void                            KDF_B_A(TwistWorkSpace *pWorkSpace,
                                                    std::uint64_t pNonce,
                                                    TwistDomainConstants *pConstants,
                                                    TwistDomainSaltSet *pDomainSaltSet,
                                                    std::uint8_t *pSource,
                                                    std::uint64_t *pPrevious,
                                                    std::uint64_t *pIngress,
                                                    std::uint64_t *pCarry,
                                                    std::uint64_t *pWandererA,
                                                    std::uint64_t *pWandererB,
                                                    std::uint64_t *pWandererC,
                                                    std::uint64_t *pWandererD,
                                                    std::uint64_t *pWandererE,
                                                    std::uint64_t *pWandererF,
                                                    std::uint64_t *pWandererG,
                                                    std::uint64_t *pWandererH,
                                                    std::uint64_t *pWandererI,
                                                    std::uint64_t *pWandererJ,
                                                    std::uint64_t *pWandererK) = 0;

    virtual void                            KDF_B_B(TwistWorkSpace *pWorkSpace,
                                                    std::uint64_t pNonce,
                                                    TwistDomainConstants *pConstants,
                                                    TwistDomainSaltSet *pDomainSaltSet,
                                                    std::uint8_t *pSource,
                                                    std::uint64_t *pPrevious,
                                                    std::uint64_t *pIngress,
                                                    std::uint64_t *pCarry,
                                                    std::uint64_t *pWandererA,
                                                    std::uint64_t *pWandererB,
                                                    std::uint64_t *pWandererC,
                                                    std::uint64_t *pWandererD,
                                                    std::uint64_t *pWandererE,
                                                    std::uint64_t *pWandererF,
                                                    std::uint64_t *pWandererG,
                                                    std::uint64_t *pWandererH,
                                                    std::uint64_t *pWandererI,
                                                    std::uint64_t *pWandererJ,
                                                    std::uint64_t *pWandererK) = 0;

    virtual void                            KDF_B_C(TwistWorkSpace *pWorkSpace,
                                                    std::uint64_t pNonce,
                                                    TwistDomainConstants *pConstants,
                                                    TwistDomainSaltSet *pDomainSaltSet,
                                                    std::uint8_t *pSource,
                                                    std::uint64_t *pPrevious,
                                                    std::uint64_t *pIngress,
                                                    std::uint64_t *pCarry,
                                                    std::uint64_t *pWandererA,
                                                    std::uint64_t *pWandererB,
                                                    std::uint64_t *pWandererC,
                                                    std::uint64_t *pWandererD,
                                                    std::uint64_t *pWandererE,
                                                    std::uint64_t *pWandererF,
                                                    std::uint64_t *pWandererG,
                                                    std::uint64_t *pWandererH,
                                                    std::uint64_t *pWandererI,
                                                    std::uint64_t *pWandererJ,
                                                    std::uint64_t *pWandererK) = 0;

    virtual void                            Seed_A(TwistWorkSpace *pWorkSpace,
                                                   std::uint64_t pNonce,
                                                   std::uint8_t *pSource,
                                                   std::uint64_t *pPrevious,
                                                   std::uint64_t *pIngress,
                                                   std::uint64_t *pCarry,
                                                   std::uint64_t *pWandererA,
                                                   std::uint64_t *pWandererB,
                                                   std::uint64_t *pWandererC,
                                                   std::uint64_t *pWandererD,
                                                   std::uint64_t *pWandererE,
                                                   std::uint64_t *pWandererF,
                                                   std::uint64_t *pWandererG,
                                                   std::uint64_t *pWandererH,
                                                   std::uint64_t *pWandererI,
                                                   std::uint64_t *pWandererJ,
                                                   std::uint64_t *pWandererK) = 0;

    virtual void                            Seed_B(TwistWorkSpace *pWorkSpace,
                                                   std::uint64_t pNonce,
                                                   std::uint8_t *pSource,
                                                   std::uint64_t *pPrevious,
                                                   std::uint64_t *pIngress,
                                                   std::uint64_t *pCarry,
                                                   std::uint64_t *pWandererA,
                                                   std::uint64_t *pWandererB,
                                                   std::uint64_t *pWandererC,
                                                   std::uint64_t *pWandererD,
                                                   std::uint64_t *pWandererE,
                                                   std::uint64_t *pWandererF,
                                                   std::uint64_t *pWandererG,
                                                   std::uint64_t *pWandererH,
                                                   std::uint64_t *pWandererI,
                                                   std::uint64_t *pWandererJ,
                                                   std::uint64_t *pWandererK) = 0;

    virtual void                            Seed_C(TwistWorkSpace *pWorkSpace,
                                                   std::uint64_t pNonce,
                                                   std::uint8_t *pSource,
                                                   std::uint64_t *pPrevious,
                                                   std::uint64_t *pIngress,
                                                   std::uint64_t *pCarry,
                                                   std::uint64_t *pWandererA,
                                                   std::uint64_t *pWandererB,
                                                   std::uint64_t *pWandererC,
                                                   std::uint64_t *pWandererD,
                                                   std::uint64_t *pWandererE,
                                                   std::uint64_t *pWandererF,
                                                   std::uint64_t *pWandererG,
                                                   std::uint64_t *pWandererH,
                                                   std::uint64_t *pWandererI,
                                                   std::uint64_t *pWandererJ,
                                                   std::uint64_t *pWandererK) = 0;

    virtual void                            Seed_D(TwistWorkSpace *pWorkSpace,
                                                   std::uint64_t pNonce,
                                                   std::uint8_t *pSource,
                                                   std::uint64_t *pPrevious,
                                                   std::uint64_t *pIngress,
                                                   std::uint64_t *pCarry,
                                                   std::uint64_t *pWandererA,
                                                   std::uint64_t *pWandererB,
                                                   std::uint64_t *pWandererC,
                                                   std::uint64_t *pWandererD,
                                                   std::uint64_t *pWandererE,
                                                   std::uint64_t *pWandererF,
                                                   std::uint64_t *pWandererG,
                                                   std::uint64_t *pWandererH,
                                                   std::uint64_t *pWandererI,
                                                   std::uint64_t *pWandererJ,
                                                   std::uint64_t *pWandererK) = 0;

    virtual void                            Seed_E(TwistWorkSpace *pWorkSpace,
                                                   std::uint64_t pNonce,
                                                   std::uint8_t *pSource,
                                                   std::uint64_t *pPrevious,
                                                   std::uint64_t *pIngress,
                                                   std::uint64_t *pCarry,
                                                   std::uint64_t *pWandererA,
                                                   std::uint64_t *pWandererB,
                                                   std::uint64_t *pWandererC,
                                                   std::uint64_t *pWandererD,
                                                   std::uint64_t *pWandererE,
                                                   std::uint64_t *pWandererF,
                                                   std::uint64_t *pWandererG,
                                                   std::uint64_t *pWandererH,
                                                   std::uint64_t *pWandererI,
                                                   std::uint64_t *pWandererJ,
                                                   std::uint64_t *pWandererK) = 0;

    virtual void                            Seed_F(TwistWorkSpace *pWorkSpace,
                                                   std::uint64_t pNonce,
                                                   std::uint8_t *pSource,
                                                   std::uint64_t *pPrevious,
                                                   std::uint64_t *pIngress,
                                                   std::uint64_t *pCarry,
                                                   std::uint64_t *pWandererA,
                                                   std::uint64_t *pWandererB,
                                                   std::uint64_t *pWandererC,
                                                   std::uint64_t *pWandererD,
                                                   std::uint64_t *pWandererE,
                                                   std::uint64_t *pWandererF,
                                                   std::uint64_t *pWandererG,
                                                   std::uint64_t *pWandererH,
                                                   std::uint64_t *pWandererI,
                                                   std::uint64_t *pWandererJ,
                                                   std::uint64_t *pWandererK) = 0;

    virtual void                            Seed_G(TwistWorkSpace *pWorkSpace,
                                                   std::uint64_t pNonce,
                                                   std::uint8_t *pSource,
                                                   std::uint64_t *pPrevious,
                                                   std::uint64_t *pIngress,
                                                   std::uint64_t *pCarry,
                                                   std::uint64_t *pWandererA,
                                                   std::uint64_t *pWandererB,
                                                   std::uint64_t *pWandererC,
                                                   std::uint64_t *pWandererD,
                                                   std::uint64_t *pWandererE,
                                                   std::uint64_t *pWandererF,
                                                   std::uint64_t *pWandererG,
                                                   std::uint64_t *pWandererH,
                                                   std::uint64_t *pWandererI,
                                                   std::uint64_t *pWandererJ,
                                                   std::uint64_t *pWandererK) = 0;

    virtual void                            Twist_A(TwistWorkSpace *pWorkSpace,
                                                    std::uint8_t *pSource,
                                                    std::uint64_t *pPrevious,
                                                    std::uint64_t *pIngress,
                                                    std::uint64_t *pCarry,
                                                    std::uint64_t *pWandererA,
                                                    std::uint64_t *pWandererB,
                                                    std::uint64_t *pWandererC,
                                                    std::uint64_t *pWandererD,
                                                    std::uint64_t *pWandererE,
                                                    std::uint64_t *pWandererF,
                                                    std::uint64_t *pWandererG,
                                                    std::uint64_t *pWandererH,
                                                    std::uint64_t *pWandererI,
                                                    std::uint64_t *pWandererJ,
                                                    std::uint64_t *pWandererK) = 0;

    virtual void                            Twist_B(TwistWorkSpace *pWorkSpace,
                                                    std::uint8_t *pSource,
                                                    std::uint64_t *pPrevious,
                                                    std::uint64_t *pIngress,
                                                    std::uint64_t *pCarry,
                                                    std::uint64_t *pWandererA,
                                                    std::uint64_t *pWandererB,
                                                    std::uint64_t *pWandererC,
                                                    std::uint64_t *pWandererD,
                                                    std::uint64_t *pWandererE,
                                                    std::uint64_t *pWandererF,
                                                    std::uint64_t *pWandererG,
                                                    std::uint64_t *pWandererH,
                                                    std::uint64_t *pWandererI,
                                                    std::uint64_t *pWandererJ,
                                                    std::uint64_t *pWandererK) = 0;

    virtual void                            Twist_C(TwistWorkSpace *pWorkSpace,
                                                    std::uint8_t *pSource,
                                                    std::uint64_t *pPrevious,
                                                    std::uint64_t *pIngress,
                                                    std::uint64_t *pCarry,
                                                    std::uint64_t *pWandererA,
                                                    std::uint64_t *pWandererB,
                                                    std::uint64_t *pWandererC,
                                                    std::uint64_t *pWandererD,
                                                    std::uint64_t *pWandererE,
                                                    std::uint64_t *pWandererF,
                                                    std::uint64_t *pWandererG,
                                                    std::uint64_t *pWandererH,
                                                    std::uint64_t *pWandererI,
                                                    std::uint64_t *pWandererJ,
                                                    std::uint64_t *pWandererK) = 0;

    virtual void                            Twist_D(TwistWorkSpace *pWorkSpace,
                                                    std::uint8_t *pSource,
                                                    std::uint64_t *pPrevious,
                                                    std::uint64_t *pIngress,
                                                    std::uint64_t *pCarry,
                                                    std::uint64_t *pWandererA,
                                                    std::uint64_t *pWandererB,
                                                    std::uint64_t *pWandererC,
                                                    std::uint64_t *pWandererD,
                                                    std::uint64_t *pWandererE,
                                                    std::uint64_t *pWandererF,
                                                    std::uint64_t *pWandererG,
                                                    std::uint64_t *pWandererH,
                                                    std::uint64_t *pWandererI,
                                                    std::uint64_t *pWandererJ,
                                                    std::uint64_t *pWandererK) = 0;

    virtual void                            GROW_A(TwistWorkSpace *,
                                                   std::uint64_t *,
                                                   std::uint64_t *,
                                                   std::uint64_t *,
                                                   std::uint64_t *,
                                                   std::uint64_t *,
                                                   std::uint64_t *,
                                                   std::uint64_t *,
                                                   std::uint64_t *,
                                                   std::uint64_t *,
                                                   std::uint64_t *,
                                                   std::uint64_t *,
                                                   std::uint64_t *,
                                                   std::uint64_t *,
                                                   std::uint64_t *) {
    }

    virtual void                            GROW_B(TwistWorkSpace *,
                                                   std::uint64_t *,
                                                   std::uint64_t *,
                                                   std::uint64_t *,
                                                   std::uint64_t *,
                                                   std::uint64_t *,
                                                   std::uint64_t *,
                                                   std::uint64_t *,
                                                   std::uint64_t *,
                                                   std::uint64_t *,
                                                   std::uint64_t *,
                                                   std::uint64_t *,
                                                   std::uint64_t *,
                                                   std::uint64_t *,
                                                   std::uint64_t *) {
    }
    
};

#endif /* TwistExpander_hpp */
