//
// Created by 48782 on 25.07.2023.
//

#include "Data/include/DataManager.h"
#include "Data/include/Board/EndPoint.h"

DataManager::DataManager(Reader& reader, Writer& writer) : _reader(&reader), _writer(&writer) {
    GenerateBoard();
}

Board &DataManager::GetBoard() const {
    return *_board;
}

Reader &DataManager::GetReader() const {
    return *_reader;
}

BoardInteractiveSymbol &DataManager::GetPlayer() const {
    return *_player;
}

void DataManager::SetBoard(Board& board) {
    delete _board;
    _board = &board;
}

void DataManager::SetReader(Reader& reader) {
    delete _reader;
    _reader = &reader;
}

void DataManager::SetPlayer(BoardInteractiveSymbol& player) {
    delete _player;
    _player = &player;
}

void DataManager::GenerateBoard() {
    _board = new Board(_reader->ReadBoardFromLabyrinthPath());

    std::pair<int, int> playerPos = _board->GetElementPosition(_reader->GetPlayerSymbol());
    _player = new Player(playerPos.first, playerPos.second, _reader->GetPlayerSymbol());

    std::pair<int, int> endPointPos = _board->GetElementPosition(_reader->GetExitSymbol());
    _endPoint = new EndPoint(endPointPos.first, endPointPos.second, _reader->GetExitSymbol());
}

void DataManager::SetEndPoint(BoardInteractiveSymbol &endPoint) {
    delete _endPoint;
    _endPoint = &endPoint;
}

BoardInteractiveSymbol &DataManager::GetEndPoint() const {
    return *_endPoint;
}

Writer &DataManager::GetWriter() const {
    return *_writer;
}

void DataManager::SetWriter(Writer &writer) {
    delete _writer;
    _writer = &writer;
}

void DataManager::WriteAll() const {
    _writer->WriteAll();
}

void DataManager::ToQueue(std::string info) const {
    GetWriter().ToQueue(info);
}

bool DataManager::IsWriting() const {
    return _writer->IsThreadRunning();
}

void DataManager::StopWriting() const {
    _writer->StopWriting();
}

void DataManager::ChangeWritingFile(std::string newFile) {
    _writer->ChangeToWriteFile(newFile);
}

DataManager::~DataManager() {
    delete _board;
    delete _writer;
    delete _reader;
    delete _player;
    delete _endPoint;
}
