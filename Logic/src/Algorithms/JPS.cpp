//
// Created by 48782 on 03.08.2023.
//

#include <queue>
#include "Logic/include/Algorithms/JPS.h"

JPS::JPS(BoardInteractiveSymbol &movingObject, Board &initialBoard, BoardInteractiveSymbol &endPoint, Reader &reader,
         const std::function<void(std::string)> &toQueueWritingMethod) : Algorithm(movingObject, initialBoard, endPoint,
                                                                                   reader, toQueueWritingMethod) {

}

struct CompareNodes {
    bool operator()(std::shared_ptr<Node> a, std::shared_ptr<Node> b) const {
        return a->GetWeight() > b->GetWeight(); // Smaller distance has higher priority
    }
};

std::shared_ptr<Node>
JPS::Pathfinding(std::function<float(const BoardInteractiveSymbol &, const BoardInteractiveSymbol &)> CalculateWeight) {
    using NodePtr = std::shared_ptr<Node>;

    std::priority_queue<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>, CompareNodes> openList;
    std::unordered_map<std::string, bool> visited;

    openList.push(std::make_shared<Node>(*GetInitialBoard(), 0, *GetPlayer(), GetOrder(), GetBlockingSymbols(), nullptr, 0, Direction::STARTPOINT));

//    while (!openList.empty()) {
//        std::shared_ptr<Node> currentNode = openList.top();
//        openList.pop();
//
//        std::string currentState = currentNode->GetBoard().ToString();
//        if (visited[currentState]) {
//            continue;
//        }
//
//        visited[currentState] = true;
//        SetVisitedCount(GetVisitedCount() + 1);
//
//        if (ObjectReachedEndPoint(currentNode->GetPlayer())) {
//            // Znaleziono drogę do końcowego punktu
//            if (currentNode->GetParent() != nullptr)
//                GetUpdatedBoard()->SetSymbolAtPosition(currentNode->GetPlayer().GetX(), currentNode->GetPlayer().GetY(), GetReplacementSymbol());
//
//            WriteToFile(currentNode, GetPlayer().GetSymbol());
//
//            return currentNode;
//        }
//
//        for (std::shared_ptr<Node> child : GenerateNodes(currentNode)) {
//            std::string nextState = child->GetBoard().ToString();
//            float weight = CalculateWeight(child->GetPlayer(), *GetEndPoint());
//
//            if (!visited[nextState]) {
//                child->SetWeight(weight);
//                openList.push(child);
//            }
//        }
//
//        WritingLogic(currentNode, nullptr);
//    }

    return nullptr; // N
}

bool CheckNextMove(std::vector<Direction> dirs, Direction currDir)
{
    for (Direction d : dirs) {
        if (currDir == d)
            return true;
    }

    return false;
}

std::vector<std::shared_ptr<Node>> JPS::GenerateNodes(std::shared_ptr<Node> currentNode) const {
    std::vector<std::shared_ptr<Node>> childNodes;

    for (Direction dir : currentNode->GetAvailableMoves()) { //it searches for available moves

        std::shared_ptr<Node> nextMove = currentNode;

        while(CheckNextMove(nextMove->GetAvailableMoves(), dir)) { // it searches for forced neighbours
            Board newBoard(nextMove->GetBoard());

            BoardInteractiveSymbol newPlayer = nextMove->GetPlayer();

            char replaceSymbol;

            if(nextMove->GetParent() != nullptr) {
                replaceSymbol = nextMove->GetParent()->GetBoard().GetSymbolFromPosition(newPlayer.GetX(), newPlayer.GetY());
            }
            else {
                replaceSymbol = GetStartPointReplacement();
            }

            newBoard.SetSymbolAtPosition(nextMove->GetPlayer().GetX(), nextMove->GetPlayer().GetY(), replaceSymbol);

            if (dir == Direction::LEFT || dir == Direction::RIGHT) {
                newPlayer.SetX(newPlayer.GetX() + ConvertDirectionToInt(dir));
            }
            else {
                newPlayer.SetY(newPlayer.GetY() + ConvertDirectionToInt(dir));
            }

            newBoard.SetSymbolAtPosition(newPlayer.GetX(), newPlayer.GetY(), GetPlayer()->GetSymbol());

            nextMove = std::make_shared<Node>(newBoard, -1., newPlayer, nextMove->GetOrder(), GetBlockingSymbols(), nextMove, nextMove->GetPathLength() + 1, dir);
        }

        childNodes.push_back(nextMove);
    }

    return childNodes;
}

std::shared_ptr<Node> JPS::Jump(std::shared_ptr<Node> currentNode, const Direction& direction) {
    // Get the neighbor in the given direction

//    NodePtr neighbor = GetNeighbor(currentNode, direction);

//    if (neighbor == nullptr) {
//        return nullptr; // No neighbor, cannot jump
//    }
//
//    // Check if the neighbor is the goal
//    if (neighbor->GetBoard() == *GetEndPoint()) {
//        return neighbor;
//    }
//
//    // Check if the neighbor has a forced neighbor in the opposite direction
//    if (HasForcedNeighbor(neighbor, ReverseDirection(direction))) {
//        return neighbor;
//    }
//
//    // Check if diagonal movement is possible
//    if (direction.IsDiagonal()) {
//        // Check for diagonal forced neighbors
//        if (IsDiagonalForced(neighbor, direction)) {
//            return neighbor;
//        }
//
//        // Perform diagonal pruning
//        if (Jump(neighbor, direction) != nullptr || Jump(neighbor, direction.GetCardinalX()) != nullptr ||
//            Jump(neighbor, direction.GetCardinalY()) != nullptr) {
//            return neighbor;
//        }
//    }

    // Continue jumping in the same direction
    //return Jump(neighbor, direction);
    return nullptr;
}
