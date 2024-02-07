//
// Created by 48782 on 27.07.2023.
//

#include <list>
#include <algorithm>
#include "Logic/include/Algorithms/DFS.h"

DFS::DFS(BoardInteractiveSymbol &movingObject, Board &initialBoard, BoardInteractiveSymbol &endPoint, Reader &reader,
         const std::function<void(std::string)> &toQueueWritingMethod) :
         Algorithm(movingObject, initialBoard, endPoint,
                   reader, toQueueWritingMethod) {}
std::string reverseString(const std::string& str) {
    std::string reversedStr;
    for (int i = str.length() - 1; i >= 0; --i) {
        reversedStr.push_back(str[i]);
    }
    return reversedStr;
}

std::shared_ptr<Node> DFS::Pathfinding(std::function<float(const BoardInteractiveSymbol&, const BoardInteractiveSymbol&)> CalculateWeight) {
    using NodePtr = std::shared_ptr<Node>;

    std::list<NodePtr> pq;
    std::shared_ptr<Node> previousNode;
    std::unordered_map<std::string, bool> visited;

    std::string reversedOrder = reverseString(*GetOrder());

    pq.push_back(std::make_shared<Node>(*GetInitialBoard(), 0, *GetPlayer(), &reversedOrder, GetBlockingSymbols(), nullptr, 0,
                                        Direction::STARTPOINT));

    while(!pq.empty())
    {
        NodePtr node = pq.back();
        pq.pop_back();

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
                pq.push_back(child);
            }
        }

        WritingLogic(node, previousNode);

        previousNode = node;
    }

    return nullptr;
}

