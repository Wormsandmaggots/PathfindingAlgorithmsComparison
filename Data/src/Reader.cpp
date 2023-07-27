//
// Created by 48782 on 24.07.2023.
//

#include "Data/include/Reader.h"

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

void Reader::SetPlayerSymbol(char playerSymbol) {
    _playerSymbol = playerSymbol;
}

void Reader::SetExitSymbol(char exitSymbol) {
    _exitSymbol = exitSymbol;
}

const std::string &Reader::GetOrder() const {
    return _moveOrder;
}

void Reader::SetOrder(const std::string& order) {
    _moveOrder = order;
}

void Reader::SetBlockingSymbols(std::string blockingSymbols) {
    _blockingSymbols = blockingSymbols;
}

const std::string &Reader::GetBlockingSymbols() const {
    return _blockingSymbols;
}

void Reader::SetVisitedReplacement(char visitedReplacement) {
    _visitedReplacement = visitedReplacement;
}

char Reader::GetVisitedReplacement() const {
    return _visitedReplacement;
}

char Reader::GetStartPointReplacement() const {
    return _startPointReplacement;
}

void Reader::SetStartPointReplacement(char startPointReplacement) {
    _startPointReplacement = startPointReplacement;
}

