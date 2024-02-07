//
// Created by 48782 on 01.08.2023.
//

#include <queue>
#include "Logic/include/Algorithms/AStar.h"

AStar::AStar(BoardInteractiveSymbol &movingObject, Board &initialBoard, BoardInteractiveSymbol &endPoint,
             Reader &reader, const std::function<void(std::string)> &toQueueWritingMethod) :
             Algorithm(movingObject, initialBoard, endPoint, reader, toQueueWritingMethod){

}

struct CompareNodes {
    bool operator()(std::shared_ptr<Node> a, std::shared_ptr<Node> b) const {
        return a->GetWeight() > b->GetWeight(); // Smaller distance has higher priority
    }
};

//change it to allow passing heuristics methods
std::shared_ptr<Node> AStar::Pathfinding(std::function<float(const BoardInteractiveSymbol&, const BoardInteractiveSymbol&)> CalculateWeight) {
    using NodePtr = std::shared_ptr<Node>;

    std::priority_queue<NodePtr, std::vector<NodePtr>, CompareNodes> pq;
    std::shared_ptr<Node> previousNode;
    std::unordered_map<std::string, bool> visited;

    pq.push(std::make_shared<Node>(*GetInitialBoard(), 0, *GetPlayer(), GetOrder(), GetBlockingSymbols(), nullptr, 0, Direction::STARTPOINT));

    while(!pq.empty())
    {
        NodePtr node = pq.top();
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
            float weight = CalculateWeight(child->GetPlayer(), *GetEndPoint());

            SetProcessedCount(GetProcessedCount() + 1);

            if (!visited[nextState]) {
                child->SetWeight(weight);
                pq.push(child);
            }
        }

        WritingLogic(node, previousNode);

        previousNode = node;
    }

    return nullptr;
}
