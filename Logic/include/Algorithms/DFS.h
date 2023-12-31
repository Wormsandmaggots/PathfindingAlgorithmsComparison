//
// Created by 48782 on 27.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_DFS_H
#define PATHFINDINGALGORITHMSCOMPARISON_DFS_H

#include "Logic/include/Algorithms/Algorithm.h"

class DFS : public Algorithm {
public:
    DFS(BoardInteractiveSymbol &movingObject, Board &initialBoard, BoardInteractiveSymbol &endPoint, Reader &reader,
        const std::function<void(std::string)> &toQueueWritingMethod);

    ~DFS() override = default;

    std::shared_ptr<Node> Pathfinding(std::function<float(const BoardInteractiveSymbol&, const BoardInteractiveSymbol&)> = nullptr) override;
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_DFS_H
