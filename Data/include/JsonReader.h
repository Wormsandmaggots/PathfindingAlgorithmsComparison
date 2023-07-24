//
// Created by 48782 on 24.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_JSONREADER_H
#define PATHFINDINGALGORITHMSCOMPARISON_JSONREADER_H
#include "Reader.h"

class JsonReader : public Reader {
public:
    explicit JsonReader(const char* filename);
    virtual ~JsonReader() = default;

    void ReadPathFromFile() override;
    std::vector<std::string> ReadBoardFromLabyrinthPath() override;
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_JSONREADER_H
