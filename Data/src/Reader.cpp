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
