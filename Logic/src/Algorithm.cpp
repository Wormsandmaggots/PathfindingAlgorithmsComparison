//
// Created by 48782 on 25.07.2023.
//

#include "Logic/include/Algorithm.h"

Algorithm::Algorithm(BoardInteractiveSymbol *movingObject, Board *initialBoard) {

}

std::vector<Node> Algorithm::GenerateNodes(Node *currentNode) {
    return std::vector<Node>();
}

bool Algorithm::ObjectReachedEndPoint() const {
    return _movingObject->ComparePositions(_endPoint);
}
