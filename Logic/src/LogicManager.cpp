//
// Created by 48782 on 26.07.2023.
//

#include <sstream>
#include "Logic/include/LogicManager.h"
#include "Data/include/FileHandlers/JsonReader.h"
#include "Logic/include/Algorithms/Dijkstra.h"
#include "Logic/include/Algorithms/BFS.h"
#include "Logic/include/Algorithms/DFS.h"
#include "Logic/include/Heuristic.h"
#include "Logic/include/Algorithms/AStar.h"
#include "Logic/include/Algorithms/JPS.h"
#include "Logic/include/DirectorySystem.h"
#include "chrono"

LogicManager::LogicManager(Reader& reader, Writer& writer, bool createDefaultAlgorithms, bool createDefaultHeuristics) {
    DirectorySystem::CreateDirectories({"Stats"});

    _dm = new DataManager(reader, writer);

    if(createDefaultAlgorithms)
    {
        AddNewAlgorithm(ASTAR, ALGORITHMLAMBDA(AStar));
        AddNewAlgorithm(DIJKSTRA, ALGORITHMLAMBDA(Dijkstra));
        AddNewAlgorithm(BFSA, ALGORITHMLAMBDA(BFS));
        AddNewAlgorithm(DFSA, ALGORITHMLAMBDA(DFS));
        AddNewAlgorithm(JPSA, ALGORITHMLAMBDA(JPS));
    }

    if(createDefaultHeuristics)
    {
        AddNewHeuristic(EUCLIDEAN, Heuristic::EuclideanDistance);
        AddNewHeuristic(MANHATTAN, Heuristic::ManhattanDistance);
        AddNewHeuristic(CHEBYSHEV, Heuristic::ChebyshevDistance);
        AddNewHeuristic(INVERSE, Heuristic::InverseHeuristic);
    }
}

void WriteStatistics(Statistics& s, std::shared_ptr<Node> endNode)
{
    s.pathLen = endNode->GetPathLength();
    s.endNode = endNode;

    std::string temp;

    std::shared_ptr<Node> lastNode = endNode;

    while(lastNode->GetParent() != nullptr)
    {
        temp += ConvertDirectionToChar(lastNode->GetMove());

        lastNode = lastNode->GetParent();
    }

    int j = temp.size() - 1;

    for(int i = 0; i <= j; i++, j--)
    {
        char a = temp[i];
        temp[i] = temp[j];
        temp[j] = a;
    }

    s.path = temp;
}

Statistics LogicManager::StartPathfinding(std::string chosenAlgorithm, std::string chosenHeuristic) {

    std::string dirPath;
    if(chosenHeuristic.empty()){
        dirPath = "Stats/" + chosenAlgorithm;
    }
    else{
        dirPath = "Stats/" + chosenAlgorithm + "/" + chosenHeuristic;
    }

    Statistics s;

    DirectorySystem::CreateDirectories({dirPath});
    ChangeWritingFile(dirPath + "/" + (chosenAlgorithm + chosenHeuristic + ".txt"));

    auto toQueue = [this](std::string info){_dm->GetWriter().ToQueue(info);};

    Algorithm* newAlgorithm = _algorithmsMap.Find(_algorithmsNames->IndexOf(chosenAlgorithm))(_dm->GetPlayer(), _dm->GetBoard(),
            _dm->GetEndPoint(), _dm->GetReader(), toQueue);

    std::shared_ptr<Node> node;

    auto startTime = std::chrono::system_clock::now();

    if(!chosenHeuristic.empty())
    {
        node = newAlgorithm->Pathfinding(_weightMethods.Find(_heuristicsNames->IndexOf(chosenHeuristic)));
    }
    else
    {
        node = newAlgorithm->Pathfinding();
    }

    auto duration = std::chrono::system_clock::now() - startTime;

    _dm->WriteAll();

    s.processedNodes = newAlgorithm->GetProcessedCount();
    s.visitedNodes = newAlgorithm->GetVisitedCount();

    delete newAlgorithm;

    auto convertedDuration = std::chrono::duration_cast<std::chrono::microseconds>(duration);

    ChangeWritingFile(dirPath + "/" + (chosenAlgorithm + chosenHeuristic + "Stats.txt"));

    s.duration = convertedDuration;
    s.usedAlgorithm = chosenAlgorithm;
    s.usedHeuristic = chosenHeuristic;

    WriteStatistics(s, node);

    _dm->ToQueue("------------------------------------------------------");
    _dm->ToQueue("Algorithm: " + s.usedAlgorithm);
    _dm->ToQueue("Heuristic: " + s.usedHeuristic);
    _dm->ToQueue("------------------------------------------------------");
    _dm->ToQueue("Algorithm found path length: " + std::to_string(s.pathLen));
    _dm->ToQueue("Algorithm found path: " + s.path);
    _dm->ToQueue("Algorithm searching time: " + std::to_string(s.duration.count() / 1000.f) + " milliseconds");
    _dm->ToQueue("Algorithm processed nodes: " + std::to_string(s.processedNodes));
    _dm->ToQueue("Algorithm visited nodes: " + std::to_string(s.visitedNodes));

    _dm->WriteAll();

    return s;
}

void LogicManager::ChangeWritingFile(std::string newFile) {
    if(_dm->IsWriting())
        _dm->StopWriting();

    _dm->ChangeWritingFile(newFile);
}

//should be reference
void LogicManager::AddNewHeuristic(std::string heuristicName, WeightMethodType weightMethod) {
    _heuristicsNames->Add(heuristicName);
    _weightMethods.Add(weightMethod);//[_heuristicsNames->GetLen() - 1] = weightMethod;
}

void LogicManager::AddNewAlgorithm(std::string algorithmName, AlgorithmMethodType algorithmMethod) {
    _algorithmsNames->Add(algorithmName);
    //DirectorySystem::CreateDirectories({"Stats/" + algorithmName});
    _algorithmsMap.Add(algorithmMethod);//[_algorithmsNames->GetLen() - 1] = algorithmMethod;
}

LogicManager::~LogicManager() {
    delete _dm;
    delete _algorithmsNames;
    delete _heuristicsNames;
}
