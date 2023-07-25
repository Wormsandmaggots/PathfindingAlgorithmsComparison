//
// Created by 48782 on 25.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_DIRECTION_H
#define PATHFINDINGALGORITHMSCOMPARISON_DIRECTION_H

enum class Direction {
    LEFT = -1,
    RIGHT = 1,
    UP = -2,
    DOWN = 2
};

static int ConvertDirectionToInt(Direction dir)
{
    if(dir == Direction::LEFT || dir == Direction::RIGHT)
        return (int)dir;
    else
        return (int)dir / 2;
}

#endif //PATHFINDINGALGORITHMSCOMPARISON_DIRECTION_H
