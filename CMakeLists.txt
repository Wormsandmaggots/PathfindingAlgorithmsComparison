cmake_minimum_required(VERSION 3.25)
project(PathfindingAlgorithmsComparison)

set(CMAKE_CXX_STANDARD 23)


include(FetchContent)


FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.10.4  # Replace this with the version/tag you want to use
)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/master.zip
)


FetchContent_MakeAvailable(nlohmann_json googletest)


add_library(PathfindingAlgorithmsComparisonLib STATIC
        Data/include/Board.h Data/src/Board.cpp
        Data/include/JsonReader.h Data/src/JsonReader.cpp
        Data/include/Reader.h Data/src/Reader.cpp
        Data/include/Player.h Data/src/Player.cpp
        Data/include/Direction.h
        Logic/src/Algorithm.cpp Logic/include/Algorithm.h
        Data/src/BoardInteractiveSymbol.cpp Data/include/BoardInteractiveSymbol.h
        Data/src/DataManager.cpp Data/include/DataManager.h
        Logic/src/Node.cpp Logic/include/Node.h
        Logic/src/Dijkstra.cpp Logic/include/Dijkstra.h
        Data/src/EndPoint.cpp Data/include/EndPoint.h
        Data/src/Writer.cpp Data/include/Writer.h
        Data/src/TxtWriter.cpp Data/include/TxtWriter.h Logic/src/LogicManager.cpp Logic/include/LogicManager.h Logic/src/DirectorySystem.cpp Logic/include/DirectorySystem.h Logic/src/BFS.cpp Logic/include/BFS.h Logic/src/DFS.cpp Logic/include/DFS.h)


target_link_libraries(PathfindingAlgorithmsComparisonLib PRIVATE nlohmann_json::nlohmann_json)


# Main executable links to the library
add_executable(PathfindingAlgorithmsComparison main.cpp)
target_link_libraries(PathfindingAlgorithmsComparison PRIVATE PathfindingAlgorithmsComparisonLib)


# Add the "test" directory to the include directories to find test headers
include_directories(${CMAKE_SOURCE_DIR})


# Add the test executable and link it with the GTest library and your project's source files
add_executable(RunTests TestDir/DataTest/PlayerTest.cpp TestDir/DataTest/DirectionTest.cpp TestDir/DataTest/JsonReaderTest.cpp TestDir/DataTest/BoardTest.cpp TestDir/LogicTest/AlgorithmTest.cpp)
target_link_libraries(RunTests PRIVATE PathfindingAlgorithmsComparisonLib gtest gtest_main)
