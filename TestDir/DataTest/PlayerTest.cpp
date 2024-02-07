//
// Created by 48782 on 25.07.2023.
//

#include <gtest/gtest.h>
#include "Data/include/Direction.h"
#include "Data/include/Board/Player.h"

class PlayerTest : public ::testing::Test {
protected:
    int x = 24;
    int y = 14;
    char c = 'P';
    Player* player;

    // Set up the fixture before running each test case
    void SetUp() override {
        player = new Player(x, y, c);
    }

    // Clean up the fixture after running each test case
    void TearDown() override {
        delete player;
    }
};

TEST_F(PlayerTest, PlayerInitialization)
{
    ASSERT_TRUE(player != nullptr);
    ASSERT_EQ(player->GetX(), x);
    ASSERT_EQ(player->GetY(), y);
    ASSERT_EQ(player->GetSymbol(), c);
}

TEST_F(PlayerTest, PlayerMove)
{
    player->Move(Direction::LEFT);
    ASSERT_EQ(player->GetX(), x - 1);

    player->Move(Direction::RIGHT);
    ASSERT_EQ(player->GetX(), x);

    player->Move(Direction::DOWN);
    ASSERT_EQ(player->GetY(), y + 1);

    player->Move(Direction::UP);
    ASSERT_EQ(player->GetY(), y);
}

