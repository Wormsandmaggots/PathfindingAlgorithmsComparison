//
// Created by 48782 on 24.07.2023.
//

#include "include/Reader.h"

Reader::Reader(const char* filename) : _configFile(filename) {}

const std::string& Reader::GetConfigFileName() const {
    return _configFile;
}

const std::string& Reader::GetLabyrinthFileName() const {
    return _labyrinthFile;
}

void Reader::SetPath(const std::string& labyrinthFileName) {
    _labyrinthFile = labyrinthFileName;
}

char Reader::GetPlayerSymbol() const {
    return _playerSymbol;
}

char Reader::GetExitSymbol() const {
    return _exitSymbol;
}

char Reader::GetWallSymbol() const {
    return _wallSymbol;
}

void Reader::SetPlayerSymbol(char playerSymbol) {
    _playerSymbol = playerSymbol;
}

void Reader::SetExitSymbol(char exitSymbol) {
    _exitSymbol = exitSymbol;
}

void Reader::SetWallSymbol(char wallSymbol) {
    _wallSymbol = wallSymbol;
}
