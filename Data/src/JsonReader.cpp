//
// Created by 48782 on 24.07.2023.
//

#include "include/JsonReader.h"

#include "fstream"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

JsonReader::JsonReader(const char* filename) : Reader(filename) {
    ReadConfigContentFromFile();
}

void JsonReader::ReadConfigContentFromFile() {
    std::ifstream f(GetConfigFileName());

    if (!f.is_open()) {
        throw std::runtime_error("Couldn't open a file: " + GetConfigFileName());
    }

    json data = json::parse(f);

    SetPath(data.at("path"));
    SetExitSymbol(((std::string)data.at("exit_symbol")).at(0));
    SetPlayerSymbol(((std::string)data.at("player_symbol")).at(0));
    SetWallSymbol(((std::string)data.at("wall_symbol")).at(0));

    f.close();
}

std::vector<std::string> JsonReader::ReadBoardFromLabyrinthPath() {
    std::vector<std::string> board;

    std::ifstream f(GetLabyrinthFileName());

    std::string line;
    while(std::getline(f, line)) {
        board.push_back(line);
    }

    f.close();

    return board;
}
