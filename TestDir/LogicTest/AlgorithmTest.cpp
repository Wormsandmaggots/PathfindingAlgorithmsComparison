//
// Created by 48782 on 25.07.2023.
//

#include "gtest/gtest.h"
#include "Logic/include/Dijkstra.h"
#include "Data/include/DataManager.h"
#include "include/JsonReader.h"

class DijkstraFixture : public ::testing::Test
{
protected:
    DataManager* dm;
    Reader* reader;
    Algorithm* dijkstra;

    void SetUp() override
    {
        reader = new JsonReader("config.json");
        dm = new DataManager(*reader);

        dijkstra = new Dijkstra(dm->GetPlayer(), dm->GetBoard(), dm->GetReader().GetOrder(),
                                dm->GetReader().GetBlockingSymbols(), dm->GetEndPoint());
    }

    void TearDown() override
    {
        free(reader);
        free(dm);
        free(dijkstra);
    }
};

TEST_F(DijkstraFixture, DijkstraInitializeTest)
{
    ASSERT_TRUE(dijkstra != nullptr);
    ASSERT_TRUE(dijkstra->GetPlayer() != nullptr);
    ASSERT_TRUE(dijkstra->GetEndPoint() != nullptr);
    ASSERT_TRUE(dijkstra->GetBlockingSymbols() != nullptr);
    ASSERT_TRUE(dijkstra->GetBoard() != nullptr);
    ASSERT_TRUE(dijkstra->GetOrder() != nullptr);
    ASSERT_TRUE(!dijkstra->GetBlockingSymbols()->empty());
    ASSERT_TRUE(!dijkstra->GetOrder()->empty());
}