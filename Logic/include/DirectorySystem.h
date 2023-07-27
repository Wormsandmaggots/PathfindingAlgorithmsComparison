//
// Created by 48782 on 27.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_DIRECTORYSYSTEM_H
#define PATHFINDINGALGORITHMSCOMPARISON_DIRECTORYSYSTEM_H

#include <string>

class DirectorySystem {
public:
    static void CreateDirectories(std::initializer_list<std::string> paths);
    virtual ~DirectorySystem() = default;
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_DIRECTORYSYSTEM_H
