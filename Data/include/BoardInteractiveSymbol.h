//
// Created by 48782 on 25.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_BOARDINTERACTIVESYMBOL_H
#define PATHFINDINGALGORITHMSCOMPARISON_BOARDINTERACTIVESYMBOL_H


class BoardInteractiveSymbol {
public:
    BoardInteractiveSymbol(int x, int y, char symbol);
    virtual ~BoardInteractiveSymbol() = default;

    int GetX() const;
    int GetY() const;
    void SetX(int x);
    void SetY(int y);
    char GetSymbol() const;
    void SetSymbol(char symbol);

private:
    int _x, _y;
    char _elementSymbol;
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_BOARDINTERACTIVESYMBOL_H
