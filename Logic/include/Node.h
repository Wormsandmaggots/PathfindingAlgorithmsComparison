//
// Created by 48782 on 25.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_NODE_H
#define PATHFINDINGALGORITHMSCOMPARISON_NODE_H

#include "Data/include/Board/Board.h"
#include "Data/include/Board/BoardInteractiveSymbol.h"
#include "Data/include/Direction.h"

class Node {
public:
    explicit Node(Board board, float weight, BoardInteractiveSymbol player, const std::string* order, const std::string* blockingSymbols, std::shared_ptr<Node> parent, int pathLen, Direction move);
    virtual ~Node();

    const std::vector<Direction>& GetAvailableMoves() const;

    float GetWeight() const;
    Board GetBoard() const;
    std::shared_ptr<Node> GetParent() const;
    int GetPathLength() const;
    const std::string* GetOrder() const;
    BoardInteractiveSymbol GetPlayer() const;
    void SetWeight(float weight);
    Direction GetMove() const;

private:
    Board _nodesBoard;
    BoardInteractiveSymbol _player;
    float _nodeWeight;
    Direction _move;
    std::vector<Direction> _availableMoves;
    //every node has the same _order,
    //consider changing this
    const std::string* _order;
    std::shared_ptr<Node> _parent;
    int _pathLength = 0;

    void GenerateAvailableMoves(std::string blockingSymbols);
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_NODE_H
