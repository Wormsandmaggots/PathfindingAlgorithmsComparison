//
// Created by 48782 on 25.07.2023.
//

#include "gtest/gtest.h"
#include "Logic/include/Algorithms/Dijkstra.h"
#include "Data/include/DataManager.h"
#include "Data/include/FileHandlers/JsonReader.h"
#include "Data/include/FileHandlers/TxtWriter.h"

class DijkstraFixture : public ::testing::Test
{
protected:
    DataManager* dm;
    Reader* reader;
    Writer* writer;
    Algorithm* dijkstra;

    void SetUp() override
    {
        reader = new JsonReader("res/config.json");
        writer = new TxtWriter("Stats/test");
        dm = new DataManager(*reader, *writer);

        std::function<void(std::string)> doNothing;

        dijkstra = new Dijkstra(dm->GetPlayer(), dm->GetBoard(), dm->GetEndPoint(),
                                *reader, doNothing);
    }

    void TearDown() override
    {
        delete dm;
        delete dijkstra;
    }
};

TEST_F(DijkstraFixture, DijkstraInitializeTest)
{
    ASSERT_TRUE(dijkstra != nullptr);
    ASSERT_TRUE(dijkstra->GetPlayer() != nullptr);
    ASSERT_TRUE(dijkstra->GetEndPoint() != nullptr);
    ASSERT_TRUE(dijkstra->GetBlockingSymbols() != nullptr);
    ASSERT_TRUE(dijkstra->GetInitialBoard() != nullptr);
    ASSERT_TRUE(dijkstra->GetOrder() != nullptr);
    ASSERT_TRUE(!dijkstra->GetBlockingSymbols()->empty());
    ASSERT_TRUE(!dijkstra->GetOrder()->empty());
}