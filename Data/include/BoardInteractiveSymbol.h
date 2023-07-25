//
// Created by 48782 on 25.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_BOARDINTERACTIVESYMBOL_H
#define PATHFINDINGALGORITHMSCOMPARISON_BOARDINTERACTIVESYMBOL_H
#include "string"

class BoardInteractiveSymbol {
public:
    BoardInteractiveSymbol(int x, int y, char symbol);
    virtual ~BoardInteractiveSymbol() = default;

    bool ComparePositions(BoardInteractiveSymbol *other) const;
    int GetX() const;
    int GetY() const;
    void SetX(int x);
    void SetY(int y);
    char GetSymbol() const;
    void SetSymbol(char symbol);
    std::string ToString() const;

private:
    int _x, _y;
    char _elementSymbol;
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_BOARDINTERACTIVESYMBOL_H
