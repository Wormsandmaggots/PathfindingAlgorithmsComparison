//
// Created by 48782 on 25.07.2023.
//

#include <memory>
#include "Logic/include/Algorithm.h"


Algorithm::Algorithm(BoardInteractiveSymbol &movingObject, Board &initialBoard, BoardInteractiveSymbol &endPoint,
                     Reader &reader, const std::function<void(std::string)> &toQueueWritingMethod) :
                     _movingObject(&movingObject), _initialBoard(&initialBoard), _endPoint(&endPoint),
                     _order(reader.GetOrder()), _blockingSymbols(reader.GetBlockingSymbols()), _replacementSymbol(reader.GetVisitedReplacement()),
                     _startPointReplacement(reader.GetStartPointReplacement()), ToQueueWritingMethod(toQueueWritingMethod) {

    _boardToUpdate = new Board(initialBoard);
    UpdateBoardAction = [this](Node node, char replaceSymbol){
        GetUpdatedBoard()->SetSymbolAtPosition(node.GetPlayer().GetX(), node.GetPlayer().GetY(), replaceSymbol);
        ToQueueWritingMethod(std::to_string(GetVisitedCount()) + ".\n" + GetUpdatedBoard()->ToString());
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
            replaceSymbol = GetStartPointReplacement();
        }

        newBoard.SetSymbolAtPosition(currentNode->GetPlayer().GetX(), currentNode->GetPlayer().GetY(), replaceSymbol);

        if (dir == Direction::LEFT || dir == Direction::RIGHT) {
            newPlayer.SetX(newPlayer.GetX() + ConvertDirectionToInt(dir));
        }
        else {
            newPlayer.SetY(newPlayer.GetY() + ConvertDirectionToInt(dir));
        }

        newBoard.SetSymbolAtPosition(newPlayer.GetX(), newPlayer.GetY(), _movingObject->GetSymbol());

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

void Algorithm::WriteToFile(std::shared_ptr<Node> node, char replaceSymbol) const {
    UpdateBoardAction(*node, replaceSymbol);
}

int Algorithm::GetVisitedCount() const {
    return _visitedCount;
}

void Algorithm::SetVisitedCount(int newVisitedCount) {
    _visitedCount = newVisitedCount;
}

char Algorithm::GetStartPointReplacement() const {
    return _startPointReplacement;
}

void Algorithm::WritingLogic(std::shared_ptr<Node> crNode, std::shared_ptr<Node> prNode) const {
    if(GetReplacementSymbol() != 0)
    {
        if(crNode->GetPathLength() == 0)
            WriteToFile(crNode, GetStartPointReplacement());
        else
        {
            if(prNode->GetParent() != nullptr)
                GetUpdatedBoard()->SetSymbolAtPosition(prNode->GetPlayer().GetX(), prNode->GetPlayer().GetY(), GetReplacementSymbol());

            WriteToFile(crNode, GetPlayer().GetSymbol());
        }

    }
}

float Algorithm::CalculateWeight(const BoardInteractiveSymbol &currentPlayer) const {
    return 0;
}

