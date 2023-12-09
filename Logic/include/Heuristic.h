//
// Created by 48782 on 01.08.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_HEURISTIC_H
#define PATHFINDINGALGORITHMSCOMPARISON_HEURISTIC_H
#include "Data/include/Board/BoardInteractiveSymbol.h"

enum class HeuristicEnum{
    EUCLIDEANDISTANCE,
    MANHATTANDISTANCE,
    CHEBYSHEVDISTANCE,
    INVERSE,
};

class Heuristic {
public:
    static float EuclideanDistance(const BoardInteractiveSymbol&, const BoardInteractiveSymbol&);
    static float ManhattanDistance(const BoardInteractiveSymbol&, const BoardInteractiveSymbol&);
    static float ChebyshevDistance(const BoardInteractiveSymbol&, const BoardInteractiveSymbol&);
    static float InverseHeuristic(const BoardInteractiveSymbol&, const BoardInteractiveSymbol&);
};

#endif //PATHFINDINGALGORITHMSCOMPARISON_HEURISTIC_H
