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
#include "M88.hpp"



class TwistFarmSalt;

class TwistExpander {
public:
    
    TwistExpander();
    
    virtual ~TwistExpander();
    
    static void                             UnrollPasswordToSource(std::uint8_t *pSource,
                                                                   std::uint8_t *pPassword,
                                                                   std::size_t pPasswordByteLength);
    static void                             UnrollPasswordToSource(std::uint8_t *pSource,
                                                                   std::uint8_t *pPassword,
                                                                   std::size_t pPasswordByteLength,
                                                                   std::size_t pSourceByteLength);
    
    virtual void                            KDF(std::uint64_t pNonce,
                                                TwistDomainConstants *pDomainConstants,
                                                TwistDomainSaltSet *pDomainSaltSet);
    
    virtual void                            KDF_A(TwistWorkSpace *pWorkSpace,
                                                  std::uint64_t pNonce,
                                                  TwistDomainConstants *pDomainConstants,
                                                  TwistDomainSaltSet *pDomainSaltSet,
                                                  std::uint8_t *pSnow);
    
    virtual void                            KDF_B(TwistWorkSpace *pWorkSpace,
                                                  std::uint64_t pNonce,
                                                  TwistDomainConstants *pDomainConstants,
                                                  TwistDomainSaltSet *pDomainSaltSet,
                                                  std::uint8_t *pSnow);

    virtual void                            KDF_C(TwistWorkSpace *pWorkSpace,
                                                  std::uint64_t pNonce,
                                                  TwistDomainConstants *pDomainConstants,
                                                  TwistDomainSaltSet *pDomainSaltSet,
                                                  std::uint8_t *pSnow);

    virtual void                            KDF_D(TwistWorkSpace *pWorkSpace,
                                                  std::uint64_t pNonce,
                                                  TwistDomainConstants *pDomainConstants,
                                                  TwistDomainSaltSet *pDomainSaltSet,
                                                  std::uint8_t *pSnow);
    
    virtual void                            Seed(TwistWorkSpace *pWorkSpace,
                                                 TwistFarmSalt *pFarmSalt,
                                                 std::uint64_t pNonce,
                                                 std::uint8_t *pPassword,
                                                 std::size_t pPasswordByteLength,
                                                 std::uint8_t *pSnowLaneA,
                                                 std::uint8_t *pSnowLaneB,
                                                 std::uint8_t *pSnowLaneC,
                                                 std::uint8_t *pSnowLaneD,
                                                 std::uint8_t *pDestination);
    
    virtual void                            TwistBlock(TwistWorkSpace *pWorkSpace,
                                                       std::uint8_t *pSource,
                                                       std::uint8_t *pSnowLaneA,
                                                       std::uint8_t *pSnowLaneB,
                                                       std::uint8_t *pSnowLaneC,
                                                       std::uint8_t *pSnowLaneD,
                                                       std::uint8_t *pDestination);

    virtual void                            FoldSeed(TwistWorkSpace *pWorkSpace,
                                                     std::uint8_t *pDestination);
    virtual void                            FoldTwist(TwistWorkSpace *pWorkSpace,
                                                      std::uint8_t *pDestination);
    
    virtual void                            GrowKeyA(TwistWorkSpace *pWorkSpace,
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
                                                     std::uint64_t *pWandererK);
    virtual void                            GrowKeyB(TwistWorkSpace *pWorkSpace,
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
                                                     std::uint64_t *pWandererK);
    
    
    // this is not virtual, it calls TwistBlock on every block
    void                                    Twist(TwistWorkSpace *pWorkSpace,
                                                  std::uint8_t *pSource,
                                                  std::uint8_t *pSnowLaneA,
                                                  std::uint8_t *pSnowLaneB,
                                                  std::uint8_t *pSnowLaneC,
                                                  std::uint8_t *pSnowLaneD,
                                                  std::uint8_t *pDestination,
                                                  std::size_t pDestinationByteLength);
    
    void                                    AutoSeedThenTwist(TwistWorkSpace *pWorkSpace,
                                                              TwistFarmSalt *pFarmSalt,
                                                              std::uint64_t pNonce,
                                                              std::uint8_t *pPassword,
                                                              std::size_t pPasswordByteLength,
                                                              std::uint8_t *pSnowLaneA,
                                                              std::uint8_t *pSnowLaneB,
                                                              std::uint8_t *pSnowLaneC,
                                                              std::uint8_t *pSnowLaneD,
                                                              std::uint8_t *pDestination,
                                                              std::size_t pDestinationByteLength);
    
    // Assumes the work space is seeded...
    // Assumes pSource has at least S_BLOCK bytes...
    void                                    AutoTwist(TwistWorkSpace *pWorkSpace,
                                                      std::uint8_t *pSource,
                                                      std::uint8_t *pSnowLaneA,
                                                      std::uint8_t *pSnowLaneB,
                                                      std::uint8_t *pSnowLaneC,
                                                      std::uint8_t *pSnowLaneD,
                                                      std::uint8_t *pDestination,
                                                      std::size_t pDestinationByteLength);
    
    std::size_t                             mIndexList256A[256];
    std::size_t                             mIndexList256B[256];
    std::size_t                             mIndexList256C[256];
    std::size_t                             mIndexList256D[256];
    
    M88                                     mMatrix;
    
    TwistDomainBundle                       *GetDomainBundleInbuilt() {
        return &mDomainBundleInbuilt;
    }
    const TwistDomainBundle                 *GetDomainBundleInbuilt() const {
        return &mDomainBundleInbuilt;
    }
    TwistDomainBundle                       *GetDomainBundleEphemeral() {
        return &mDomainBundleEphemeral;
    }
    const TwistDomainBundle                 *GetDomainBundleEphemeral() const {
        return &mDomainBundleEphemeral;
    }
    
    void                                    Zero_PostSeed();
    
    void                                    Zero();
    
protected:
    
    TwistDomainBundle                       mDomainBundleInbuilt;
    TwistDomainBundle                       mDomainBundleEphemeral;
    
};


#endif /* TwistExpander_hpp */
