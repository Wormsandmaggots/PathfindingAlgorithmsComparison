#include "Logic/include/LogicManager.h"
#include "Data/include/JsonReader.h"
#include "Data/include/TxtWriter.h"

int main() {
    LogicManager* lm = new LogicManager(*new JsonReader("config.json"), *new TxtWriter("Dijkstra.txt"));

    std::shared_ptr<Node> n = lm->StartPathfinding(AlgorithmEnum::DIJKSTRA);

    std::cout << n->GetBoard().ToString() << std::endl;
    return 0;
}
