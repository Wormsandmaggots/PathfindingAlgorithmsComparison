cmake_minimum_required(VERSION 3.25)
project(PathfindingAlgorithmsComparison)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.10.4  # Replace this with the version/tag you want to use
)

FetchContent_MakeAvailable(nlohmann_json)

include_directories(Data)

add_executable(PathfindingAlgorithmsComparison main.cpp Data/include/Board.h Data/src/Board.cpp Data/include/JsonReader.h Data/src/JsonReader.cpp Data/include/Reader.h Data/src/Reader.cpp)
target_link_libraries(PathfindingAlgorithmsComparison PRIVATE nlohmann_json::nlohmann_json)
