//
//  EncryptionPlan.hpp
//  Scramble
//
//  Created by nick on 8/4/26.
//

#ifndef EncryptionPlan_hpp
#define EncryptionPlan_hpp

#include "SoccerTypes.hpp"
#include <cstddef>
#include <cstdint>

#define SHUFFLED_CIPHERS_LENGTH 256


struct EncryptionPlanStage {
    CipherType      mType[12];
    std::size_t     mCount = 0;
};

struct EncryptionPlan {
    
    EncryptionPlanStage             mL3A;
    EncryptionPlanStage             mL2A;
    EncryptionPlanStage             mL1A;
    
    EncryptionPlanStage             mL3B;
    EncryptionPlanStage             mL2B;
    EncryptionPlanStage             mL1B;
    
    EncryptionPlanStage             mL3C;
};

class EncryptionPlanTool {
    
public:

    /*
     The lane-combination tables remain the authority for key material use.

     WeakLaneCombination:
     struct WeakLaneCombination {
         std::uint8_t mL3A[1];
         std::uint8_t mL2A[1];
         std::uint8_t mL1A[1];
         std::uint8_t mL3B[1];
     };

     L3A { Baryon, Muon, Fermion, Lepton(mL3A[0]) }
     L2A { Fermion, Quasiparticle, Fermion, Lepton(mL2A[0]) }
     L1A { Baryon, Neutrino, Fermion, Lepton(mL1A[0]) }

     L3B { Fermion, Lepton(mL3B[0]) }
     L2B { Muon }
     L1B { }

     L3C { Fermion }

     Rotation total: 2 Baryon, 6 Fermion.
     Key total: 4 Lepton, 0 Boson.
     Non-rotation total: 2 Muon, 1 Quasiparticle, 1 Neutrino.


     NormalLaneCombination:
     struct NormalLaneCombination {
         std::uint8_t mL3A[1];
         std::uint8_t mL2A[1];
         std::uint8_t mL1A[1];
         std::uint8_t mL3B[1];
         std::uint8_t mL2B[1];
         std::uint8_t mL1B[1];
         std::uint8_t mL3C[1];
     };

     L3A { Baryon, Boson(mL3A[0]), Fermion }
     L2A { Muon, Lepton(mL2A[0]), Baryon }
     L1A { Lepton(mL1A[0]), Baryon }

     L3B { Quasiparticle, Lepton(mL3B[0]), Fermion }
     L2B { Lepton(mL2B[0]), Baryon }
     L1B { Neutrino, Lepton(mL1B[0]), Fermion }

     L3C { Lepton(mL3C[0]), Baryon }

     Rotation total: 5 Baryon, 3 Fermion.
     Key total: 6 Lepton, 1 Boson.
     Non-rotation total: 1 Muon, 1 Quasiparticle, 1 Neutrino.


     StrongLaneCombination:
     struct StrongLaneCombination {
         std::uint8_t mL3A[2];
         std::uint8_t mL2A[2];
         std::uint8_t mL1A[2];
         std::uint8_t mL3B[2];
         std::uint8_t mL2B[2];
         std::uint8_t mL1B[2];
         std::uint8_t mL3C[2];
     };

     L3A { Boson(mL3A[0]), Baryon, Lepton(mL3A[1]), Muon }
     L2A { Boson(mL2A[0]), Baryon, Lepton(mL2A[1]), Quasiparticle }
     L1A { Lepton(mL1A[0]), Baryon, Lepton(mL1A[1]), Neutrino }

     L3B { Lepton(mL3B[0]), Baryon, Lepton(mL3B[1]), Muon }
     L2B { Lepton(mL2B[0]), Baryon, Lepton(mL2B[1]), Baryon }
     L1B { Lepton(mL1B[0]), Baryon, Lepton(mL1B[1]), Muon }

     L3C { Lepton(mL3C[0]), Baryon, Lepton(mL3C[1]) }

     Rotation total: 8 Baryon, 0 Fermion.
     Key total: 12 Lepton, 2 Boson.
     Non-rotation total: 3 Muon, 1 Quasiparticle, 1 Neutrino.

     Across stage boundaries as well as within a stage:
     - rotations are never adjacent;
     - Lepton/Boson key ciphers are never adjacent.
     */

    static EncryptionPlan               MakePlanWeak(std::uint64_t pLaneSelect,
                                                     CipherType *pShuffledCiphers);
    static EncryptionPlan               MakePlanNormal(std::uint64_t pLaneSelect,
                                                       CipherType *pShuffledCiphers);
    static EncryptionPlan               MakePlanStrong(std::uint64_t pLaneSelect,
                                                       CipherType *pShuffledCiphers);

private:
    // pIndex can be [0...255]. If a category is absent from the shuffled
    // ring, the category's deterministic default is returned.
    static CipherType                   RingFetchLepton(CipherType *pShuffledCiphers, std::uint8_t pLaneCount, std::size_t *pIndex);
    static CipherType                   RingFetchBoson(CipherType *pShuffledCiphers, std::uint8_t pLaneCount, std::size_t *pIndex);
    static CipherType                   RingFetchHadron(CipherType *pShuffledCiphers, std::uint8_t pLaneCount, std::size_t *pIndex);

    static CipherType                   RingFetchBaryon(CipherType *pShuffledCiphers, std::size_t *pIndex);
    static CipherType                   RingFetchFermion(CipherType *pShuffledCiphers, std::size_t *pIndex);
    static CipherType                   RingFetchMeson(CipherType *pShuffledCiphers, std::size_t *pIndex);

    static CipherType                   RingFetchMuon(CipherType *pShuffledCiphers, std::size_t *pIndex);
    static CipherType                   RingFetchQuasiparticle(CipherType *pShuffledCiphers, std::size_t *pIndex);
    static CipherType                   RingFetchNeutrino(CipherType *pShuffledCiphers, std::size_t *pIndex);
    
};

#endif /* EncryptionPlan_hpp */
