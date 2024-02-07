//
// Created by 48782 on 09.12.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_STATISTICS_H
#define PATHFINDINGALGORITHMSCOMPARISON_STATISTICS_H

#include <memory>
#include "chrono"

class Node;

struct Statistics{
    std::string usedAlgorithm;
    std::string usedHeuristic;
    std::shared_ptr<Node> endNode;
    std::chrono::microseconds duration;
    std::string path;
    int pathLen;
    int processedNodes = 0;
    int visitedNodes = 0;
};
#endif //PATHFINDINGALGORITHMSCOMPARISON_STATISTICS_H
