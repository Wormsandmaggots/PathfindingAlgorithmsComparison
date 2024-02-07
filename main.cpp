#include "Logic/include/LogicManager.h"
#include "Data/include/FileHandlers/JsonReader.h"
#include "Data/include/FileHandlers/TxtWriter.h"

int main() {
    LogicManager* lm = new LogicManager(*new JsonReader("res/config.json"), *new TxtWriter(""));

    lm->StartPathfinding(DIJKSTRA, EUCLIDEAN);
    lm->StartPathfinding(DIJKSTRA, CHEBYSHEV);
    lm->StartPathfinding(DIJKSTRA, MANHATTAN);
    lm->StartPathfinding(DIJKSTRA, INVERSE);
    lm->StartPathfinding(DFSA);
    lm->StartPathfinding(BFSA);
    lm->StartPathfinding(ASTAR, MANHATTAN);
    lm->StartPathfinding(ASTAR, CHEBYSHEV);
    lm->StartPathfinding(ASTAR, INVERSE);

    Statistics s = lm->StartPathfinding(ASTAR, EUCLIDEAN);

    //lm->StartPathfinding(JPSA, EUCLIDEAN);

    std::cout << s.endNode->GetBoard().ToString() << std::endl;

    delete lm;

    //std::system("cls");
    return 0;
}
