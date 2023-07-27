//
// Created by 48782 on 25.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_DATAMANAGER_H
#define PATHFINDINGALGORITHMSCOMPARISON_DATAMANAGER_H

#include "Data/include/Board.h"
#include "Data/include/Reader.h"
#include "Data/include/Player.h"
#include "Writer.h"

class DataManager {
public:
    explicit DataManager(Reader& reader, Writer& writer);
    virtual ~DataManager() = default;

    Board &GetBoard() const;
    Reader &GetReader() const;
    Writer &GetWriter() const;
    BoardInteractiveSymbol &GetPlayer() const;
    BoardInteractiveSymbol &GetEndPoint() const;
    void SetBoard(Board &board);
    void SetReader(Reader &reader);
    void SetPlayer(BoardInteractiveSymbol &player);
    void SetEndPoint(BoardInteractiveSymbol &endPoint);
    void SetWriter(Writer&);

private:
    Board* _board;
    Reader* _reader;
    Writer* _writer;
    BoardInteractiveSymbol* _player;
    BoardInteractiveSymbol* _endPoint;

    void GenerateBoard();
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_DATAMANAGER_H
