//
// Created by 48782 on 25.07.2023.
//

#include "Data/include/Board/Player.h"
#include "Data/include/Direction.h"

Player::Player(int x, int y, char playerSymbol) : BoardInteractiveSymbol(x, y, playerSymbol) {}

void Player::Move(Direction dir) {
    if(dir == Direction::LEFT || dir == Direction::RIGHT) {
        SetX(GetX() + ConvertDirectionToInt(dir));
    }
    else {
        SetY(GetY() + ConvertDirectionToInt(dir));
    }
}