//
// Created by 48782 on 25.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_NODE_H
#define PATHFINDINGALGORITHMSCOMPARISON_NODE_H

#include "Data/include/Board.h"
#include "Data/include/BoardInteractiveSymbol.h"
#include "Data/include/Direction.h"

class Node {
public:
    explicit Node(Board board, float weight, BoardInteractiveSymbol player, const std::string* order, const std::string* blockingSymbols, std::shared_ptr<Node> parent, int pathLen);
    ~Node() = default;

    const std::vector<Direction>& GetAvailableMoves() const;

    float GetWeight() const;
    Board GetBoard() const;
    std::shared_ptr<Node> GetParent() const;
    int GetPathLength() const;
    const std::string* GetOrder() const;
    BoardInteractiveSymbol GetPlayer() const;
    void SetWeight(float weight);

private:
    Board _nodesBoard;
    BoardInteractiveSymbol _player;
    float _nodeWeight;
    std::vector<Direction> _availableMoves;
    const std::string* _order;
    std::shared_ptr<Node> _parent;
    int _pathLength = 0;

    void GenerateAvailableMoves(std::string blockingSymbols);
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_NODE_H
