//
// Created by 48782 on 25.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_ENDPOINT_H
#define PATHFINDINGALGORITHMSCOMPARISON_ENDPOINT_H

#include "Data/include/BoardInteractiveSymbol.h"

class EndPoint : public BoardInteractiveSymbol{
public:
    EndPoint(int x, int y, char symbol);
    virtual ~EndPoint() = default;
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_ENDPOINT_H
