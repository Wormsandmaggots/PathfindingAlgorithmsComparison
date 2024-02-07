//
// Created by 48782 on 25.07.2023.
//

#include "gtest/gtest.h"
#include "Data/include/Direction.h"

TEST(DirectionTest, DirectionConversionTest)
{
    ASSERT_EQ(ConvertDirectionToInt(Direction::LEFT), -1);
    ASSERT_EQ(ConvertDirectionToInt(Direction::RIGHT), 1);
    ASSERT_EQ(ConvertDirectionToInt(Direction::UP), -1);
    ASSERT_EQ(ConvertDirectionToInt(Direction::DOWN), 1);
}