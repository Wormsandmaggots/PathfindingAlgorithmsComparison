//
// Created by 48782 on 25.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_ALGORITHM_H
#define PATHFINDINGALGORITHMSCOMPARISON_ALGORITHM_H

#include <memory>
#include "Data/include/BoardInteractiveSymbol.h"
#include "Data/include/Board.h"
#include "Node.h"

class Algorithm {
public:
    explicit Algorithm(BoardInteractiveSymbol& movingObject, Board& initialBoard, const std::string& order, const std::string& blockingSymbols, BoardInteractiveSymbol& endPoint, char replacementSymbol);
    virtual ~Algorithm() = default;

    virtual std::shared_ptr<Node> Pathfinding() const = 0;
    std::vector<std::shared_ptr<Node>> GenerateNodes(std::shared_ptr<Node> currentNode) const;
    bool ObjectReachedEndPoint(BoardInteractiveSymbol player) const;
    virtual float CalculateWeight(const BoardInteractiveSymbol& currentPlayer) const = 0;

    Board GetBoard() const;
    BoardInteractiveSymbol GetPlayer() const;
    BoardInteractiveSymbol* GetEndPoint() const;
    const std::string* GetOrder() const;
    const std::string* GetBlockingSymbols() const;
    char GetReplacementSymbol() const;

private:
    BoardInteractiveSymbol* _movingObject;
    BoardInteractiveSymbol* _endPoint;
    Board* _initialBoard;
    const std::string* _order;
    const std::string* _blockingSymbols;
    char _replacementSymbol = 0;
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_ALGORITHM_H
