#include "Logic/include/LogicManager.h"
#include "Data/include/JsonReader.h"
#include "Data/include/TxtWriter.h"
#include "Logic/include/DirectorySystem.h"

int main() {
    DirectorySystem::CreateDirectories({"Stats", "Stats/Dijkstra", "Stats/BFS", "Stats/DFS"});

    LogicManager* lm = new LogicManager(*new JsonReader("config.json"), *new TxtWriter("Stats/Dijkstra/Dijkstra.txt"));
    std::shared_ptr<Node> n = lm->StartPathfinding(AlgorithmEnum::DIJKSTRA);

    lm->ChangeWritingFile("Stats/DFS/DFS.txt");

    lm->StartPathfinding(AlgorithmEnum::DFS);

    lm->ChangeWritingFile("Stats/BFS/BFS.txt");

    lm->StartPathfinding(AlgorithmEnum::BFS);

    std::cout << n->GetBoard().ToString() << std::endl;
    //std::system("cls");
    return 0;
}

void PrintBoard(std::shared_ptr<Node> node)
{

}
