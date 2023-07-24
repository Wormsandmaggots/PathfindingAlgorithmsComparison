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
    char GetPlayerSymbol() const;
    char GetExitSymbol() const;
    char GetWallSymbol() const;

protected:
    virtual void ReadConfigContentFromFile() = 0;
    void SetPath(const std::string&);
    void SetPlayerSymbol(char playerSymbol);
    void SetExitSymbol(char exitSymbol);
    void SetWallSymbol(char wallSymbol);

private:
    std::string _configFile;
    std::string _labyrinthFile;
    char _playerSymbol;
    char _exitSymbol;
    char _wallSymbol;
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_READER_H
