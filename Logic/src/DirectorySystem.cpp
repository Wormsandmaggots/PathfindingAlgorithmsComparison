//
// Created by 48782 on 27.07.2023.
//

#include "Logic/include/DirectorySystem.h"
#include <filesystem>

void ProcessPath(std::string);

void DirectorySystem::CreateDirectories(std::initializer_list<std::string> paths) {
    for (std::string s : paths) {
        ProcessPath(s);
    }
}

void ProcessPath(std::string path) {
    if (!std::filesystem::exists(path)) {
        if (!std::filesystem::create_directory(path)) {
            throw std::exception();
        }
    }
}


