//
// Created by 48782 on 25.07.2023.
//

#include <memory>
#include "Logic/include/Algorithm.h"


Algorithm::Algorithm(BoardInteractiveSymbol &movingObject, Board &initialBoard, BoardInteractiveSymbol &endPoint,
                     Reader &reader, const std::function<void(std::string)> &toQueueWritingMethod) :
                     _movingObject(&movingObject), _initialBoard(&initialBoard), _endPoint(&endPoint),
                     _order(reader.GetOrder()), _blockingSymbols(reader.GetBlockingSymbols()), _replacementSymbol(reader.GetVisitedReplacement()),
                     ToQueueWritingMethod(toQueueWritingMethod) {

    _boardToUpdate = new Board(initialBoard);
    UpdateBoardAction = [this](BoardInteractiveSymbol player, char replaceSymbol){
        GetUpdatedBoard()->SetSymbolAtPosition(player.GetX(), player.GetY(), replaceSymbol);
        ToQueueWritingMethod(GetUpdatedBoard()->ToString());
    };
}

std::vector<std::shared_ptr<Node>> Algorithm::GenerateNodes(std::shared_ptr<Node> currentNode) const {
    std::vector<std::shared_ptr<Node>> childNodes;

    for (Direction dir : currentNode->GetAvailableMoves()) {
        Board newBoard(currentNode->GetBoard());

        BoardInteractiveSymbol newPlayer = currentNode->GetPlayer();

        char replaceSymbol;

        if(currentNode->GetParent() != nullptr) {
            replaceSymbol = currentNode->GetParent()->GetBoard().GetSymbolFromPosition(newPlayer.GetX(), newPlayer.GetY());
        }
        else {
            //consider setting in config sth like start position symbol to replace that 'S'
            replaceSymbol = 'S';
        }

        newBoard.SetSymbolAtPosition(currentNode->GetPlayer().GetX(), currentNode->GetPlayer().GetY(), replaceSymbol);

        if (dir == Direction::LEFT || dir == Direction::RIGHT) {
            newPlayer.SetX(newPlayer.GetX() + ConvertDirectionToInt(dir));
        }
        else {
            newPlayer.SetY(newPlayer.GetY() + ConvertDirectionToInt(dir));
        }

        newBoard.SetSymbolAtPosition(newPlayer.GetX(), newPlayer.GetY(), _movingObject->GetSymbol());

        //childNodes.emplace_back(newBoard, -1., newPlayer, _order, _blockingSymbols, &currentNode, currentNode.GetPathLength() + 1);
        childNodes.push_back(std::make_shared<Node>(newBoard, -1., newPlayer, &_order, &_blockingSymbols, currentNode, currentNode->GetPathLength() + 1));
    }

    return childNodes;
}

bool Algorithm::ObjectReachedEndPoint(BoardInteractiveSymbol player) const {
    return player.ComparePositions(_endPoint);
}

Board* Algorithm::GetInitialBoard() const {
    return _initialBoard;
}

BoardInteractiveSymbol Algorithm::GetPlayer() const {
    return *_movingObject;
}

const std::string* Algorithm::GetOrder() const {
    return &_order;
}

const std::string* Algorithm::GetBlockingSymbols() const {
    return &_blockingSymbols;
}

BoardInteractiveSymbol *Algorithm::GetEndPoint() const {
    return _endPoint;
}

char Algorithm::GetReplacementSymbol() const {
    return _replacementSymbol;
}

Board *Algorithm::GetUpdatedBoard() const {
    return _boardToUpdate;
}

