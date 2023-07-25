//
// Created by 48782 on 25.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_ALGORITHM_H
#define PATHFINDINGALGORITHMSCOMPARISON_ALGORITHM_H
#include "Data/include/BoardInteractiveSymbol.h"
#include "Data/include/Board.h"
#include "Node.h"

class Algorithm {
public:
    explicit Algorithm(BoardInteractiveSymbol* movingObject, Board* initialBoard);
    virtual ~Algorithm();

    virtual void Pathfinding() const = 0;
    std::vector<Node> GenerateNodes(Node* currentNode);
    bool ObjectReachedEndPoint() const;

private:
    BoardInteractiveSymbol* _movingObject;
    BoardInteractiveSymbol* _endPoint;
    Board* _initialBoard;
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_ALGORITHM_H
