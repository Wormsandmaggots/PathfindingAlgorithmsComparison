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
        Data/include/Board/Board.h Data/src/Board/Board.cpp
        Data/include/FileHandlers/JsonReader.h Data/src/FileHandlers/JsonReader.cpp
        Data/include/FileHandlers/Reader.h Data/src/FileHandlers/Reader.cpp
        Data/include/Board/Player.h Data/src/Board/Player.cpp
        Data/include/Direction.h
        Logic/src/Algorithms/Algorithm.cpp Logic/include/Algorithms/Algorithm.h
        Data/src/Board/BoardInteractiveSymbol.cpp Data/include/Board/BoardInteractiveSymbol.h
        Data/src/DataManager.cpp Data/include/DataManager.h
        Logic/src/Node.cpp Logic/include/Node.h
        Logic/src/Algorithms/Dijkstra.cpp Logic/include/Algorithms/Dijkstra.h
        Data/src/Board/EndPoint.cpp Data/include/Board/EndPoint.h
        Data/src/FileHandlers/Writer.cpp Data/include/FileHandlers/Writer.h
        Data/src/FileHandlers/TxtWriter.cpp Data/include/FileHandlers/TxtWriter.h Logic/src/LogicManager.cpp Logic/include/LogicManager.h Logic/src/DirectorySystem.cpp Logic/include/DirectorySystem.h Logic/src/Algorithms/BFS.cpp Logic/include/Algorithms/BFS.h Logic/src/Algorithms/DFS.cpp Logic/include/Algorithms/DFS.h Logic/src/Heuristic.cpp Data/include/DynamicEnum/EnumValue.h Data/include/DynamicEnum/DynamicEnum.h)


target_link_libraries(PathfindingAlgorithmsComparisonLib PRIVATE nlohmann_json::nlohmann_json)


# Main executable links to the library
add_executable(PathfindingAlgorithmsComparison main.cpp Logic/src/Algorithms/AStar.cpp Logic/include/Algorithms/AStar.h Logic/include/Heuristic.h Logic/src/Algorithms/JPS.cpp Logic/include/Algorithms/JPS.h Data/include/DynamicEnum/EnumValue.h Data/include/DynamicEnum/IntDynamicEnum.h)
target_link_libraries(PathfindingAlgorithmsComparison PRIVATE PathfindingAlgorithmsComparisonLib)


# Add the "test" directory to the include directories to find test headers
include_directories(${CMAKE_SOURCE_DIR})


# Add the test executable and link it with the GTest library and your project's source files
add_executable(RunTests TestDir/DataTest/PlayerTest.cpp TestDir/DataTest/DirectionTest.cpp TestDir/DataTest/JsonReaderTest.cpp TestDir/DataTest/BoardTest.cpp TestDir/LogicTest/AlgorithmTest.cpp)
target_link_libraries(RunTests PRIVATE PathfindingAlgorithmsComparisonLib gtest gtest_main)
