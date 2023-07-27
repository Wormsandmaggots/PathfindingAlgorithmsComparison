//
// Created by 48782 on 27.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_BFS_H
#define PATHFINDINGALGORITHMSCOMPARISON_BFS_H

#include "Algorithm.h"

class BFS : public Algorithm{
public:
    BFS(BoardInteractiveSymbol &movingObject, Board &initialBoard, BoardInteractiveSymbol &endPoint, Reader &reader,
        const std::function<void(std::string)> &toQueueWritingMethod);

    ~BFS() override = default;

    std::shared_ptr<Node> Pathfinding() override;
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_BFS_H
