//
// Created by 48782 on 25.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_PLAYER_H
#define PATHFINDINGALGORITHMSCOMPARISON_PLAYER_H

#include "Data/include/Board/BoardInteractiveSymbol.h"

enum class Direction;

class Player : public BoardInteractiveSymbol {
public:
    Player(int x, int y, char playerSymbol);
    ~Player() override = default;

    void Move(Direction);
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_PLAYER_H
