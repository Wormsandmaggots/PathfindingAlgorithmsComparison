//
// Created by 48782 on 26.07.2023.
//

#include "Logic/include/LogicManager.h"
#include "Data/include/JsonReader.h"
#include "Logic/include/Dijkstra.h"
#include "Logic/include/BFS.h"
#include "Logic/include/DFS.h"

#define ALGORITHMLAMBDA(algorithmName)  [](BoardInteractiveSymbol& movingObject, Board& initialBoard,\
                                        BoardInteractiveSymbol& endPoint, Reader& reader,\
                                        const std::function<void(std::string)>& toQueueWritingMethod) {\
                                        return new algorithmName(movingObject, initialBoard, endPoint, reader, toQueueWritingMethod);}


std::unordered_map<AlgorithmEnum,
        std::function<Algorithm*(BoardInteractiveSymbol&, Board&,
        BoardInteractiveSymbol&, Reader&, const std::function<void(std::string)>&)>>
        AlgorithmsMap =
{
        {AlgorithmEnum::DIJKSTRA, ALGORITHMLAMBDA(Dijkstra)},
        {AlgorithmEnum::BFS, ALGORITHMLAMBDA(BFS)},
        {AlgorithmEnum::DFS, ALGORITHMLAMBDA(DFS)}
};

LogicManager::LogicManager(Reader& reader, Writer& writer) {
    _dm = new DataManager(reader, writer);
}

std::shared_ptr<Node> LogicManager::StartPathfinding(AlgorithmEnum chosenAlgorithm) {
    auto toQueue = [this](std::string info){_dm->GetWriter().ToQueue(info);};
    Algorithm* newAlgorithm = AlgorithmsMap[chosenAlgorithm](_dm->GetPlayer(), _dm->GetBoard(),
            _dm->GetEndPoint(), _dm->GetReader(), toQueue);

    _dm->GetWriter().ToFile();

    std::shared_ptr<Node> node = newAlgorithm->Pathfinding();

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



