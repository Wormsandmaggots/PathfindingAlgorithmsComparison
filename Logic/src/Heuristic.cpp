//
// Created by 48782 on 02.08.2023.
//

#include "Logic/include/Heuristic.h"
#include "cmath"

float Heuristic::EuclideanDistance(const BoardInteractiveSymbol& currentPlayer, const BoardInteractiveSymbol& endPoint) {
    return sqrt(pow(currentPlayer.GetX() - endPoint.GetX(),2) +
                pow(currentPlayer.GetY() - endPoint.GetY(),2));
}

float Heuristic::ManhattanDistance(const BoardInteractiveSymbol& currentPlayer, const BoardInteractiveSymbol& endPoint) {
    return abs(currentPlayer.GetX() - endPoint.GetX()) + abs(currentPlayer.GetY() - endPoint.GetY());
}

float Heuristic::ChebyshevDistance(const BoardInteractiveSymbol& currentPlayer, const BoardInteractiveSymbol& endPoint) {
    float dx = abs(currentPlayer.GetX() - endPoint.GetX());
    float dy = abs(currentPlayer.GetY() - endPoint.GetY());
    return std::max(dx, dy);
}

float Heuristic::InverseHeuristic(const BoardInteractiveSymbol& currentPlayer, const BoardInteractiveSymbol& endPoint) {
    int dx = currentPlayer.GetX() + endPoint.GetX();
    int dy = currentPlayer.GetY() + endPoint.GetY();
    return 1.0f / std::sqrt(dx * dx + dy * dy);
}




