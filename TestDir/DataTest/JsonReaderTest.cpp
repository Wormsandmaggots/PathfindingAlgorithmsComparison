//
// Created by 48782 on 25.07.2023.
//
#include "gtest/gtest.h"
#include "string"
#include "Data/include/FileHandlers/JsonReader.h"

std::string path = "res/config.json";
Reader* jsonReader = new JsonReader(path.c_str());

TEST(JsonReaderTest, JsonReaderInitializationTest)
{
    ASSERT_EQ(jsonReader->GetConfigFileName(), path);
    ASSERT_FALSE(jsonReader->GetLabyrinthFileName().empty());
    ASSERT_FALSE(jsonReader->ReadBoardFromLabyrinthPath()[0].empty());
}