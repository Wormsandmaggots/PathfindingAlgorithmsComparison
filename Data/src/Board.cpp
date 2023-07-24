//
// Created by 48782 on 24.07.2023.
//

#include "include/Board.h"

#include <sstream>

Board::Board(Reader& reader) : _reader(reader) {
    _board = _reader.ReadBoardFromLabyrinthPath();
}

const std::vector<std::string>& Board::GetBoard() const {
    return _board;
}

std::string Board::ToString() const {
    std::stringstream ss;

    for (auto line : _board) {
        ss << line << "\n";
    }

    return ss.str();
}
