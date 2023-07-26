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

    virtual std::vector<std::string>& ReadBoardFromLabyrinthPath() = 0;
    const std::string& GetConfigFileName() const;
    const std::string& GetLabyrinthFileName() const;
    const std::string& GetOrder() const;
    const std::string& GetBlockingSymbols() const;
    char GetPlayerSymbol() const;
    char GetExitSymbol() const;
    char GetVisitedReplacement();

protected:
    virtual void ReadConfigContentFromFile() = 0;
    void SetPath(const std::string&);
    void SetOrder(const std::string&);
    void SetPlayerSymbol(char playerSymbol);
    void SetBlockingSymbols(std::string blockingSymbols);
    void SetExitSymbol(char exitSymbol);
    void SetVisitedReplacement(char visitedReplacement);

private:
    std::string _configFile;
    std::string _labyrinthFile;
    std::string _moveOrder;
    std::string _blockingSymbols;
    char _playerSymbol;
    char _exitSymbol;
    char _visitedReplacement;
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_READER_H
