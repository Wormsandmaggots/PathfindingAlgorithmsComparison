//
// Created by 48782 on 03.08.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_JPS_H
#define PATHFINDINGALGORITHMSCOMPARISON_JPS_H

#include "Logic/include/Algorithms/Algorithm.h"

class JPS : public Algorithm{
public:
    JPS(BoardInteractiveSymbol& movingObject, Board& initialBoard,
            BoardInteractiveSymbol& endPoint, Reader& reader,
    const std::function<void(std::string)>& toQueueWritingMethod);
    ~JPS() override = default;

    std::shared_ptr<Node> Pathfinding(std::function<float(const BoardInteractiveSymbol&, const BoardInteractiveSymbol&)>) override;
    std::vector<std::shared_ptr<Node>> GenerateNodes(std::shared_ptr<Node> currentNode) const override;

private:
    std::shared_ptr<Node> Jump(std::shared_ptr<Node> currentNode, const Direction& direction);
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_JPS_H
