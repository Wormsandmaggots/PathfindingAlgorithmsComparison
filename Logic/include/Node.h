//
// Created by 48782 on 25.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_NODE_H
#define PATHFINDINGALGORITHMSCOMPARISON_NODE_H

#include "include/Board.h"
#include "Data/include/Direction.h"

class Node {
public:
    explicit Node(Board* board, float weight);
    ~Node() = default;

    std::vector<Direction> AvailableMoves(std::string blockingSymbols) const;

private:
    Board* _nodesBoard;
    float _nodeWeight;

};


#endif //PATHFINDINGALGORITHMSCOMPARISON_NODE_H
