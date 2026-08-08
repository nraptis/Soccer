//
//  SoccerFoldingTool.hpp
//  Scramble
//

#ifndef SoccerFoldingTool_hpp
#define SoccerFoldingTool_hpp

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

struct SoccerFoldingToolSpecification {
    std::string                         mFunctionDeclaration;

    std::size_t                         mInputLaneByteCount;
    std::vector<std::string>            mInputLaneNames;

    std::size_t                         mOutputLaneByteCount;
    std::vector<std::string>            mOutputLaneNames;

    std::size_t                         mInputBlockCount;
    std::size_t                         mFoldItemCount;
    std::size_t                         mRandomTrialCount;
    std::uint64_t                       mRandomSeed;
};

class SoccerFoldingTool {
public:
    static bool                         Emit(const SoccerFoldingToolSpecification &pSpecification);
    static bool                         Run();
    static bool                         Run(std::size_t pRandomTrialCount,
                                            std::uint64_t pRunSeed);
};

#endif /* SoccerFoldingTool_hpp */
