//
// Created by 48782 on 25.07.2023.
//

#include <queue>
#include <functional>
#include <cmath>
#include <memory>
#include "Logic/include/Dijkstra.h"
#include "Logic/include/Node.h"

Dijkstra::Dijkstra(BoardInteractiveSymbol& movingObject, Board& initialBoard,
                   BoardInteractiveSymbol& endPoint, Reader& reader, const std::function<void(std::string)>& toQueueWritingMethod) :
                   Algorithm(movingObject, initialBoard, endPoint, reader, toQueueWritingMethod){

}

struct CompareNodes {
    bool operator()(std::shared_ptr<Node> a, std::shared_ptr<Node> b) const {
        return a->GetWeight() > b->GetWeight(); // Smaller distance has higher priority
    }
};

std::shared_ptr<Node> Dijkstra::Pathfinding() const {
    using NodePtr = std::shared_ptr<Node>;
    // Priority queue using a custom comparison lambda
    std::priority_queue<NodePtr, std::vector<NodePtr>, CompareNodes> pq;

    std::unordered_map<std::string, bool> visited;

    Board* newBoard = new Board(*GetInitialBoard());

    pq.push(std::make_shared<Node>(*newBoard, 0, GetPlayer(), GetOrder(), GetBlockingSymbols(), nullptr, 0));

    while(!pq.empty())
    {
        NodePtr node = pq.top();
        pq.pop();

        std::string currentState = node->GetBoard().ToString();
        if (visited[currentState]) {
            continue;
        }

        visited[currentState] = true;

        if (ObjectReachedEndPoint(node->GetPlayer())) {
            UpdateBoardAction(node->GetPlayer(), GetPlayer().GetSymbol());
            return node;
        }

        for(NodePtr child : GenerateNodes(node))
        {
            std::string nextState = child->GetBoard().ToString();
            float weight = CalculateWeight(child->GetPlayer());

            if (!visited[nextState] && (child->GetWeight() == -1 || node->GetWeight() + weight < child->GetWeight())) {
                child->SetWeight(node->GetWeight() + weight);
                pq.push(child);
            }
        }

        if(GetReplacementSymbol() != 0)
        {
            //instead of 'S' it is better to use value from config
            //saving position of a player
            //work with synchronization maybe because program can shut down before saving all boards
            if(node->GetPathLength() == 0)
                UpdateBoardAction(node->GetPlayer(), 'S');
            else
                UpdateBoardAction(node->GetPlayer(), GetReplacementSymbol());
        }
    }

    return nullptr;
}

float Dijkstra::CalculateWeight(const BoardInteractiveSymbol& currentPlayer) const {
    return sqrt(pow(currentPlayer.GetX() - GetEndPoint()->GetX(),2) +
                pow(currentPlayer.GetY() - GetEndPoint()->GetY(),2));
}
