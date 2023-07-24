//
// Created by 48782 on 24.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_READER_H
#define PATHFINDINGALGORITHMSCOMPARISON_READER_H
#include "iostream"
#include "vector"

class Reader {
public:
    explicit Reader(const char*);
    virtual ~Reader() = default;

    virtual std::vector<std::string> ReadBoardFromLabyrinthPath() = 0;
    const std::string& GetConfigFileName() const;
    const std::string& GetLabyrinthFileName() const;
    void SetPath(const std::string&);

protected:
    virtual void ReadPathFromFile() = 0;

private:
    std::string _configFile;
    std::string _labyrinthFile;
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_READER_H
