//
// Created by 48782 on 24.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_BOARD_H
#define PATHFINDINGALGORITHMSCOMPARISON_BOARD_H
#include "Data/include/FileHandlers/Reader.h"

class Board {
public:
    Board(std::vector<std::string>& board);
    ~Board() = default;

    std::pair<int, int> GetElementPosition(char elementSymbol) const;
    std::string ToString() const;
    const std::vector<std::string>& GetBoard() const;
    char GetSymbolFromPosition(int x, int y) const;
    void SetSymbolAtPosition(int x, int y, char symbol);

private:
    std::vector<std::string> _board;
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_BOARD_H
