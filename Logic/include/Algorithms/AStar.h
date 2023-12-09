//
// Created by 48782 on 01.08.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_ASTAR_H
#define PATHFINDINGALGORITHMSCOMPARISON_ASTAR_H
#include "Logic/include/Algorithms/Algorithm.h"

class AStar : public Algorithm {
public:
    AStar(BoardInteractiveSymbol& movingObject, Board& initialBoard,
            BoardInteractiveSymbol& endPoint, Reader& reader,
            const std::function<void(std::string)>& toQueueWritingMethod);
    ~AStar() override = default;

    std::shared_ptr<Node> Pathfinding(std::function<float(const BoardInteractiveSymbol&, const BoardInteractiveSymbol&)>) override;
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_ASTAR_H
