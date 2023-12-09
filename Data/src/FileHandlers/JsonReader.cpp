//
// Created by 48782 on 24.07.2023.
//

#include "Data/include/FileHandlers/JsonReader.h"
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
    SetBlockingSymbols(((std::string)data.at("blocking_symbols")));
    SetOrder((std::string)data.at("order"));
    SetStartPointReplacement(((std::string)data.at("start_point_replacement")).at(0));

    std::string replacement = data.at("visited_replacement");

    if(!replacement.empty()) {
        SetVisitedReplacement(((std::string)data.at("visited_replacement")).at(0));
    }
    else {
        SetVisitedReplacement(0);
    }

    f.close();
}

std::vector<std::string>& JsonReader::ReadBoardFromLabyrinthPath() {
    std::vector<std::string>* board = new std::vector<std::string>;

    std::ifstream f(GetLabyrinthFileName());

    std::string line;
    while(std::getline(f, line)) {
        board->push_back(line);
    }

    f.close();

    return *board;
}
