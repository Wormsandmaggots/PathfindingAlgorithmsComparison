//
// Created by 48782 on 26.07.2023.
//

#include "Logic/include/LogicManager.h"
#include "Data/include/JsonReader.h"
#include "Logic/include/Dijkstra.h"

#define ALGORITHMLAMBDA(algorithmName)  [](BoardInteractiveSymbol& movingObject, Board& initialBoard,\
                                        BoardInteractiveSymbol& endPoint, Reader& reader,\
                                        const std::function<void(std::string)>& toQueueWritingMethod) {\
                                        return new algorithmName(movingObject, initialBoard, endPoint, reader, toQueueWritingMethod);}


std::unordered_map<AlgorithmEnum,
        std::function<Algorithm*(BoardInteractiveSymbol&, Board&,
        BoardInteractiveSymbol&, Reader&, const std::function<void(std::string)>&)>>
        AlgorithmsMap =
{
        {AlgorithmEnum::DIJKSTRA, ALGORITHMLAMBDA(Dijkstra)}
};

LogicManager::LogicManager(Reader& reader, Writer& writer) {
    _dm = new DataManager(reader, writer);
}

std::shared_ptr<Node> LogicManager::StartPathfinding(AlgorithmEnum chosenAlgorithm) {
    auto toQueue = [this](std::string info){_dm->GetWriter().ToQueue(info);};
    Algorithm* newAlgorithm = AlgorithmsMap[chosenAlgorithm](_dm->GetPlayer(), _dm->GetBoard(),
            _dm->GetEndPoint(), _dm->GetReader(), toQueue);

    _dm->GetWriter().ToFile();
    return newAlgorithm->Pathfinding();
}



