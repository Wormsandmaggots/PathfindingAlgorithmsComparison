//
// Created by 48782 on 26.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_LOGICMANAGER_H
#define PATHFINDINGALGORITHMSCOMPARISON_LOGICMANAGER_H

#include <memory>
#include "Data/include/DataManager.h"
#include "Node.h"
#include "Data/include/FileHandlers/Writer.h"
#include "Logic/include/Heuristic.h"
#include "Logic/include/Algorithms/Algorithm.h"
#include "Data/include/DynamicEnum/IntDynamicEnum.h"
#include "Data/include/Statistics.h"

#define ASTAR "AStar"
#define DIJKSTRA "Dijkstra"
#define BFSA "BFS"
#define DFSA "DFS"
#define JPSA "JPS"

#define EUCLIDEAN "EuclideanDistance"
#define INVERSE "Inverse"
#define CHEBYSHEV "ChebyshevDistance"
#define MANHATTAN "ManhattanDistance"

//method that will return a float
//parameters will be a player and endPoint as BoardInteractiveSymbol
#define WeightMethodType std::function<float(const BoardInteractiveSymbol&, const BoardInteractiveSymbol&)>

#define AlgorithmMethodType std::function<Algorithm*(BoardInteractiveSymbol&, Board&,BoardInteractiveSymbol&, Reader&, const std::function<void(std::string)>&)>

#define ALGORITHMLAMBDA(algorithmName)  [](BoardInteractiveSymbol& movingObject, Board& initialBoard,\
                                        BoardInteractiveSymbol& endPoint, Reader& reader,\
                                        const std::function<void(std::string)>& toQueueWritingMethod) {\
                                        return new algorithmName(movingObject, initialBoard, endPoint, reader, toQueueWritingMethod); \
                                        }

class LogicManager {
public:
    LogicManager(Reader& reader, Writer& writer, bool createDefaultAlgorithms = true, bool createDefaultHeuristics = true);
    virtual ~LogicManager();

    Statistics  StartPathfinding(std::string , std::string = "");
    void ChangeWritingFile(std::string);
    void AddNewHeuristic(std::string, WeightMethodType);
    void AddNewAlgorithm(std::string, AlgorithmMethodType);

private:
    DataManager* _dm;

    IntDynamicEnum<WeightMethodType> _weightMethods;

    IntDynamicEnum<AlgorithmMethodType>
            _algorithmsMap;

    IntDynamicEnum<std::string> *_algorithmsNames = new IntDynamicEnum<std::string>();
    IntDynamicEnum<std::string> *_heuristicsNames = new IntDynamicEnum<std::string>();
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_LOGICMANAGER_H
