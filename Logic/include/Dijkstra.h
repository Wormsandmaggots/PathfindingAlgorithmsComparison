//
// Created by 48782 on 25.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_DIJKSTRA_H
#define PATHFINDINGALGORITHMSCOMPARISON_DIJKSTRA_H

#include "Logic/include/Algorithm.h"

class Dijkstra : public Algorithm {
public:
    Dijkstra(BoardInteractiveSymbol& movingObject, Board& initialBoard, const std::string& order,const std::string& blockingSymbols, BoardInteractiveSymbol& endPoint, char replacementSymbol);
    ~Dijkstra() override = default;

    std::shared_ptr<Node> Pathfinding() const override;
    float CalculateWeight(const BoardInteractiveSymbol& currentPlayer) const override;
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_DIJKSTRA_H
