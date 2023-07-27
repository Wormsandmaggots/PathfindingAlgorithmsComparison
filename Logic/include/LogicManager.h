//
// Created by 48782 on 26.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_LOGICMANAGER_H
#define PATHFINDINGALGORITHMSCOMPARISON_LOGICMANAGER_H

#include <memory>
#include "Data/include/DataManager.h"
#include "Node.h"
#include "Data/include/Writer.h"

enum class AlgorithmEnum{
    DIJKSTRA,
    BFS,
    DFS,
};

class LogicManager {
public:
    LogicManager(Reader& reader, Writer& writer);
    ~LogicManager() = default;

    std::shared_ptr<Node>  StartPathfinding(AlgorithmEnum);
    void ChangeWritingFile(std::string);
private:
    DataManager* _dm;
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_LOGICMANAGER_H
