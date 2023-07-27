//
// Created by 48782 on 25.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_ALGORITHM_H
#define PATHFINDINGALGORITHMSCOMPARISON_ALGORITHM_H

#include <memory>
#include <functional>
#include "Data/include/BoardInteractiveSymbol.h"
#include "Data/include/Board.h"
#include "Node.h"

class Algorithm {
public:
    explicit Algorithm(BoardInteractiveSymbol& movingObject, Board& initialBoard,
                       BoardInteractiveSymbol& endPoint, Reader& reader, const std::function<void(std::string)>& toQueueWritingMethod);
    virtual ~Algorithm() = default;

    virtual std::shared_ptr<Node> Pathfinding() = 0;
    std::vector<std::shared_ptr<Node>> GenerateNodes(std::shared_ptr<Node> currentNode) const;
    bool ObjectReachedEndPoint(BoardInteractiveSymbol player) const;
    virtual float CalculateWeight(const BoardInteractiveSymbol& currentPlayer) const = 0;
    virtual void WriteToFile(std::shared_ptr<Node>, char) const;

    Board* GetInitialBoard() const;
    Board* GetUpdatedBoard() const;
    BoardInteractiveSymbol GetPlayer() const;
    BoardInteractiveSymbol* GetEndPoint() const;
    const std::string* GetOrder() const;
    const std::string* GetBlockingSymbols() const;
    char GetReplacementSymbol() const;
    char GetStartPointReplacement() const;
    int GetVisitedCount() const;
    void SetVisitedCount(int);

protected:
    std::function<void(Node, char)> UpdateBoardAction;
    const std::function<void(std::string)>& ToQueueWritingMethod;
    virtual void WritingLogic(std::shared_ptr<Node>, std::shared_ptr<Node>) const;

private:
    BoardInteractiveSymbol* _movingObject;
    BoardInteractiveSymbol* _endPoint;
    Board* _initialBoard;
    Board* _boardToUpdate;
    const std::string& _order;
    const std::string& _blockingSymbols;
    char _replacementSymbol = 0;
    char _startPointReplacement;
    int _visitedCount = 0;
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_ALGORITHM_H
