//
// Created by 48782 on 24.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_BOARD_H
#define PATHFINDINGALGORITHMSCOMPARISON_BOARD_H
#include "Reader.h"

class Board {
public:
    Board(std::vector<std::string>& board);
    ~Board() = default;

    std::string ToString() const;
    const std::vector<std::string>& GetBoard() const;

private:
    std::vector<std::string> _board;
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_BOARD_H
