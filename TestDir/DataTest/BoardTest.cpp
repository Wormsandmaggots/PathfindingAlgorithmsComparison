//
// Created by 48782 on 25.07.2023.
//

#include "gtest/gtest.h"
#include "include/Board.h"

class BoardFixture : public ::testing::Test
{
protected:
    std::vector<std::string>* boardTemplate = new std::vector<std::string> {
        "xxxxxxxx",
        "x  P   x",
        "x      x",
        "x      x",
        "x    E x",
        "xxxxxxxx"
    };
    Board* board;

    void SetUp() override {
        board = new Board(*boardTemplate);
    }

    void TearDown() override {
        free(board);
        free(boardTemplate);
    }
};

TEST_F(BoardFixture, BoardInitializeTest)
{
    ASSERT_TRUE(board != nullptr);
    ASSERT_EQ(board->GetBoard(), *boardTemplate);
    ASSERT_TRUE(board->ToString() == "xxxxxxxx\n"
                                     "x  P   x\n"
                                     "x      x\n"
                                     "x      x\n"
                                     "x    E x\n"
                                     "xxxxxxxx\n");
}

TEST_F(BoardFixture, FindElementTest)
{
    std::pair<int, int> p(3, 1);

    ASSERT_EQ(board->GetElementPosition('P'), p);
}