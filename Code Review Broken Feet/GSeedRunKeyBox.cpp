

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
    // Crystal A-D + Ice A-D -> Earth A-D.
    // Eight inherited residual lanes are consumed.
    //
    const GPassFactoryStarter::SlotArray8 aPrimarySourcesA = {
        Slot::kCrystalLaneA, Slot::kCrystalLaneB,
        Slot::kCrystalLaneC, Slot::kCrystalLaneD,
        Slot::kIceLaneA, Slot::kIceLaneB,
        Slot::kIceLaneC, Slot::kIceLaneD,
    };
    const GPassFactoryStarter::SlotArray4 aDestinationsA = {
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
    };

    //
    // KEY — Phase B
    // Earth A-D -> Aether A-D.
    // Sixteen inherited residual lanes are consumed.
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesB = {
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsB = {
        Slot::kAetherLaneA, Slot::kAetherLaneB,
        Slot::kAetherLaneC, Slot::kAetherLaneD,
    };

    // KeyDiffuse transforms Aether A-D into Celestial A-D here.

    //
    // KEY — Phase C
    // Celestial A-D -> Aether A-D.
    // Sixteen inherited residual lanes are consumed.
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesC = {
        Slot::kCelestialLaneA, Slot::kCelestialLaneB,
        Slot::kCelestialLaneC, Slot::kCelestialLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsC = {
        Slot::kAetherLaneA, Slot::kAetherLaneB,
        Slot::kAetherLaneC, Slot::kAetherLaneD,
    };

    // These lanes have fixed jobs in the three phases. Source and Nonce are
    // deliberately excluded from key construction. No phase adds its output
    // lanes back; each independent flow drains this inherited bucket.
    const std::vector<Slot> aUnavailableResiduals = {
        Slot::kSourceLane,
        Slot::kNonceLane,
        Slot::kIceLaneA, Slot::kIceLaneB,
        Slot::kIceLaneC, Slot::kIceLaneD,
        Slot::kCrystalLaneA, Slot::kCrystalLaneB,
        Slot::kCrystalLaneC, Slot::kCrystalLaneD,
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
        Slot::kAetherLaneA, Slot::kAetherLaneB,
        Slot::kAetherLaneC, Slot::kAetherLaneD,
        Slot::kCelestialLaneA, Slot::kCelestialLaneB,
        Slot::kCelestialLaneC, Slot::kCelestialLaneD,
    };

}
