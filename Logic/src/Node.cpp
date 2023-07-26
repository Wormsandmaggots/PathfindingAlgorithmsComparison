//
// Created by 48782 on 25.07.2023.
//

#include <memory>
#include "include/Node.h"

const std::vector<Direction>& Node::GetAvailableMoves() const {
    return _availableMoves;
}

void Node::GenerateAvailableMoves(std::string blockingSymbols) {

    for (char dir : *_order) {
        Direction direction = ConvertCharToDirection(dir);

        char boardSymbol;
        if(direction == Direction::LEFT || direction == Direction::RIGHT) {
            boardSymbol = _nodesBoard.GetSymbolFromPosition(_player.GetX() + ConvertDirectionToInt(direction),
                                                             _player.GetY());
        }
        else {
            boardSymbol = _nodesBoard.GetSymbolFromPosition(_player.GetX(),
                                                             _player.GetY() + ConvertDirectionToInt(direction));
        }

        bool isBlocking = false;
        for (char blockingSymbol : blockingSymbols) {
            if(boardSymbol == blockingSymbol) {
                isBlocking = true;
                break;
            }
        }

        if(isBlocking) {
            continue;
        }

        _availableMoves.push_back(direction);
    }
}

Node::Node(Board board, float weight, BoardInteractiveSymbol player, const std::string* order, const std::string* blockingSymbols, std::shared_ptr<Node> parent, int pathLen) :
 _nodesBoard(board), _nodeWeight(weight), _player(player), _order(order), _parent(parent), _pathLength(pathLen)
{
    GenerateAvailableMoves(*blockingSymbols);
}

float Node::GetWeight() const {
    return _nodeWeight;
}

Board Node::GetBoard() const {
    return _nodesBoard;
}

std::shared_ptr<Node> Node::GetParent() const {
    return _parent;
}

std::string Node::GetOrder() const {
    return *_order;
}

BoardInteractiveSymbol Node::GetPlayer() const {
    return _player;
}

void Node::SetWeight(float weight) {
    _nodeWeight = weight;
}

int Node::GetPathLength() const {
    return _pathLength;
}
