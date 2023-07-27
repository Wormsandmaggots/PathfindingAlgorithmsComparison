#include "Logic/include/LogicManager.h"
#include "Data/include/JsonReader.h"
#include "Data/include/TxtWriter.h"
#include "Logic/include/DirectorySystem.h"

int main() {
    DirectorySystem::CreateDirectories({"Stats", "Stats/Dijkstra"});

    LogicManager* lm = new LogicManager(*new JsonReader("config.json"), *new TxtWriter("Stats/Dijkstra/Dijkstra.txt"));

    std::shared_ptr<Node> n = lm->StartPathfinding(AlgorithmEnum::DIJKSTRA);

    std::cout << n->GetBoard().ToString() << std::endl;
    //std::system("cls");
    return 0;
}
