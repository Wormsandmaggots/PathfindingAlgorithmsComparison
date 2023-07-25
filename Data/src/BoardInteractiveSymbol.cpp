//
// Created by 48782 on 25.07.2023.
//

#include <sstream>
#include "include/BoardInteractiveSymbol.h"

BoardInteractiveSymbol::BoardInteractiveSymbol(int x, int y, char symbol) : _x(x), _y(y), _elementSymbol(symbol) {}


int BoardInteractiveSymbol::GetX() const {
    return _x;
}

int BoardInteractiveSymbol::GetY() const {
    return _y;
}

void BoardInteractiveSymbol::SetX(int x) {
    _x = x;
}

void BoardInteractiveSymbol::SetY(int y) {
    _y = y;
}

char BoardInteractiveSymbol::GetSymbol() const {
    return _elementSymbol;
}

void BoardInteractiveSymbol::SetSymbol(char symbol) {
    _elementSymbol = symbol;
}

std::string BoardInteractiveSymbol::ToString() const {
    std::stringstream ss;

    ss << _elementSymbol << " " << _x << " " << _y << "\n";

    return ss.str();
}

bool BoardInteractiveSymbol::ComparePositions(BoardInteractiveSymbol *other) const {
    return other->_x == _x && other->_y == _y;
}
