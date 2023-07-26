#include "include/DataManager.h"
#include "include/JsonReader.h"
#include "Logic/include/Dijkstra.h"

int main() {
    DataManager* dm = new DataManager(*new JsonReader("config.json"));

    Algorithm* dijkstra = new Dijkstra(dm->GetPlayer(), dm->GetBoard(), dm->GetReader().GetOrder(),
                                       dm->GetReader().GetBlockingSymbols(), dm->GetEndPoint(), dm->GetReader().GetVisitedReplacement());

    std::shared_ptr<Node> n = dijkstra->Pathfinding();
    return 0;
}
