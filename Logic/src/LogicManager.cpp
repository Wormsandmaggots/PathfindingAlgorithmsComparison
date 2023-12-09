//
// Created by 48782 on 26.07.2023.
//

#include "Logic/include/LogicManager.h"
#include "Data/include/FileHandlers/JsonReader.h"
#include "Logic/include/Algorithms/Dijkstra.h"
#include "Logic/include/Algorithms/BFS.h"
#include "Logic/include/Algorithms/DFS.h"
#include "Logic/include/Heuristic.h"
#include "Logic/include/Algorithms/AStar.h"
#include "Logic/include/Algorithms/JPS.h"
#include "Logic/include/DirectorySystem.h"

LogicManager::LogicManager(Reader& reader, Writer& writer, bool createDefaultAlgorithms, bool createDefaultHeuristics) {
    DirectorySystem::CreateDirectories({"Stats"});

    _dm = new DataManager(reader, writer);

    if(createDefaultAlgorithms)
    {
        AddNewAlgorithm("ASTAR", ALGORITHMLAMBDA(AStar));
        AddNewAlgorithm("DIJKSTRA", ALGORITHMLAMBDA(Dijkstra));
        AddNewAlgorithm("BFS", ALGORITHMLAMBDA(BFS));
        AddNewAlgorithm("DFS", ALGORITHMLAMBDA(DFS));
        AddNewAlgorithm("JPS", ALGORITHMLAMBDA(JPS));
    }

    if(createDefaultHeuristics)
    {
        AddNewHeuristic("EUCLIDEANDISTANCE", Heuristic::EuclideanDistance);
        AddNewHeuristic("MANHATTANDISTANCE", Heuristic::ManhattanDistance);
        AddNewHeuristic("CHEBYSHEVDISTANCE", Heuristic::ChebyshevDistance);
        AddNewHeuristic("INVERSE", Heuristic::InverseHeuristic);
    }
}

std::shared_ptr<Node> LogicManager::StartPathfinding(std::string chosenAlgorithm, std::string chosenHeuristic) {
    //change this path name to lower case
    ChangeWritingFile("Stats/" + (chosenAlgorithm + "/" + chosenAlgorithm + chosenHeuristic + ".txt"));

    auto toQueue = [this](std::string info){_dm->GetWriter().ToQueue(info);};

    Algorithm* newAlgorithm = _algorithmsMap[_algorithmsNames->Find(chosenAlgorithm)](_dm->GetPlayer(), _dm->GetBoard(),
            _dm->GetEndPoint(), _dm->GetReader(), toQueue);

    _dm->GetWriter().ToFile();

    std::shared_ptr<Node> node;

    if(!chosenHeuristic.empty())
    {
        node = newAlgorithm->Pathfinding(_weightMethods[_heuristicsNames->Find(chosenHeuristic)]);
        //DirectorySystem::CreateDirectories({"Stats/" + *chosenAlgorithm + "/" + *chosenHeuristic});
    }
    else
        node = newAlgorithm->Pathfinding();

    while(!_dm->GetWriter().IsQueueEmpty()){
        std::cout << "wait:" << std::endl;
    }

    delete newAlgorithm;
    _dm->GetWriter().StopWriting();

    return node;
}

void LogicManager::ChangeWritingFile(std::string newFile) {
    if(_dm->GetWriter().IsThreadRunning())
        _dm->GetWriter().StopWriting();

    _dm->GetWriter().ChangeToWriteFile(newFile);
}

//should be reference
void LogicManager::AddNewHeuristic(std::string heuristicName, WeightMethodType weightMethod) {
    _heuristicsNames->Add(heuristicName);
    _weightMethods[_heuristicsNames->GetLen() - 1] = weightMethod;
}

void LogicManager::AddNewAlgorithm(std::string algorithmName, AlgorithmMethodType algorithmMethod) {
    _algorithmsNames->Add(algorithmName);
    DirectorySystem::CreateDirectories({"Stats/" + algorithmName});
    _algorithmsMap[_algorithmsNames->GetLen() - 1] = algorithmMethod;
}