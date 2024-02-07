//
// Created by 48782 on 27.07.2023.
//

#include "Logic/include/Algorithms/BFS.h"

#include <queue>

BFS::BFS(BoardInteractiveSymbol &movingObject, Board &initialBoard, BoardInteractiveSymbol &endPoint, Reader &reader,
         const std::function<void(std::string)> &toQueueWritingMethod)
         : Algorithm(movingObject, initialBoard, endPoint,
                     reader, toQueueWritingMethod) {}

std::shared_ptr<Node> BFS::Pathfinding(std::function<float(const BoardInteractiveSymbol&, const BoardInteractiveSymbol&)> CalculateWeight) {
    using NodePtr = std::shared_ptr<Node>;

    std::queue<NodePtr> pq;
    std::shared_ptr<Node> previousNode;
    std::unordered_map<std::string, bool> visited;

    pq.push(std::make_shared<Node>(*GetInitialBoard(), 0, *GetPlayer(), GetOrder(), GetBlockingSymbols(), nullptr, 0, Direction::STARTPOINT));

    while(!pq.empty())
    {
        NodePtr node = pq.front();
        pq.pop();

        std::string currentState = node->GetBoard().ToString();
        if (visited[currentState]) {
            continue;
        }

        visited[currentState] = true;

        SetVisitedCount(GetVisitedCount() + 1);

        if (ObjectReachedEndPoint(node->GetPlayer())) {
            if(previousNode->GetParent() != nullptr)
                GetUpdatedBoard()->SetSymbolAtPosition(previousNode->GetPlayer().GetX(), previousNode->GetPlayer().GetY(), GetReplacementSymbol());

            WriteToFile(node, GetPlayer()->GetSymbol());

            return node;
        }

        for(NodePtr child : GenerateNodes(node))
        {
            std::string nextState = child->GetBoard().ToString();

            SetProcessedCount(GetProcessedCount() + 1);

            if (!visited[nextState]) {
                pq.push(child);
            }
        }

        WritingLogic(node, previousNode);

        previousNode = node;
    }

    return nullptr;
}

