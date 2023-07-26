//
// Created by 48782 on 25.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_DATAMANAGER_H
#define PATHFINDINGALGORITHMSCOMPARISON_DATAMANAGER_H

#include "include/Board.h"
#include "include/Reader.h"
#include "include/Player.h"

class DataManager {
public:
    explicit DataManager(Reader& reader);
    virtual ~DataManager() = default;

    Board &GetBoard() const;
    Reader &GetReader() const;
    BoardInteractiveSymbol &GetPlayer() const;
    BoardInteractiveSymbol &GetEndPoint() const;
    void SetBoard(Board &board);
    void SetReader(Reader &reader);
    void SetPlayer(BoardInteractiveSymbol &player);
    void SetEndPoint(BoardInteractiveSymbol &endPoint);

private:
    Board* _board;
    Reader* _reader;
    BoardInteractiveSymbol* _player;
    BoardInteractiveSymbol* _endPoint;

    void GenerateBoard();
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_DATAMANAGER_H
