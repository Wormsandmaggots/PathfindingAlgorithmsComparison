//
// Created by 48782 on 25.07.2023.
//

#include "include/Player.h"

#include "include/Direction.h"

Player::Player(int x, int y, char playerSymbol) : BoardInteractiveSymbol(x, y, playerSymbol) {}

void Player::Move(Direction dir) {
    if(dir == Direction::LEFT || dir == Direction::RIGHT) {
        SetX(GetX() + (int)dir);
    }
    else {
        SetY(GetY() + (int)dir);
    }
}