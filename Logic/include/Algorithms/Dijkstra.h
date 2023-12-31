//
// Created by 48782 on 25.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_DIJKSTRA_H
#define PATHFINDINGALGORITHMSCOMPARISON_DIJKSTRA_H

#include "Logic/include/Algorithms/Algorithm.h"

class Dijkstra : public Algorithm {
public:
    Dijkstra(BoardInteractiveSymbol& movingObject, Board& initialBoard,
             BoardInteractiveSymbol& endPoint, Reader& reader,
             const std::function<void(std::string)>& toQueueWritingMethod);
    ~Dijkstra() override = default;

    std::shared_ptr<Node> Pathfinding(std::function<float(const BoardInteractiveSymbol&, const BoardInteractiveSymbol&)>) override;
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_DIJKSTRA_H
