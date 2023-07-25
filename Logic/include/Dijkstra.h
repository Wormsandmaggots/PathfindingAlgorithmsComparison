//
// Created by 48782 on 25.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_DIJKSTRA_H
#define PATHFINDINGALGORITHMSCOMPARISON_DIJKSTRA_H

#include "Logic/include/Algorithm.h"

class Dijkstra : public Algorithm {
public:
    Dijkstra(BoardInteractiveSymbol* movingObject, Board* initialBoard);
    ~Dijkstra() override = default;

    void Pathfinding() const override;
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_DIJKSTRA_H
