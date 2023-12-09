#include "Logic/include/LogicManager.h"
#include "Data/include/FileHandlers/JsonReader.h"
#include "Data/include/FileHandlers/TxtWriter.h"
#include "Logic/include/DirectorySystem.h"

int main() {
    LogicManager* lm = new LogicManager(*new JsonReader("config.json"), *new TxtWriter("Stats/Dijkstra/DijkstraEuclidean.txt"));

    lm->StartPathfinding("DIJKSTRA", "EUCLIDEANDISTANCE");
    lm->StartPathfinding("DIJKSTRA", "CHEBYSHEVDISTANCE");
    lm->StartPathfinding("DIJKSTRA", "MANHATTANDISTANCE");
    lm->StartPathfinding("DIJKSTRA", "INVERSE");
    lm->StartPathfinding("DFS");
    lm->StartPathfinding("BFS");
    lm->StartPathfinding("ASTAR", "MANHATTANDISTANCE");
    lm->StartPathfinding("ASTAR", "CHEBYSHEVDISTANCE");
    lm->StartPathfinding("ASTAR", "INVERSE");

    std::shared_ptr<Node> n = lm->StartPathfinding("ASTAR", "EUCLIDEANDISTANCE");

    lm->StartPathfinding("JPS", "EUCLIDEANDISTANCE");

    std::cout << n->GetBoard().ToString() << std::endl;

    //std::system("cls");
    return 0;
}
