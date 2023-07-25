//
// Created by 48782 on 25.07.2023.
//

#include "include/DataManager.h"

DataManager::DataManager(Reader& reader) : _reader(&reader) {
    GenerateBoard();
}

Board &DataManager::GetBoard() const {
    return *_board;
}

Reader &DataManager::GetReader() const {
    return *_reader;
}

Player &DataManager::GetPlayer() const {
    return *_player;
}

void DataManager::SetBoard(Board& board) {
    _board = &board;
}

void DataManager::SetReader(Reader& reader) {
    _reader = &reader;
}

void DataManager::SetPlayer(Player& player) {
    _player = &player;
}

void DataManager::GenerateBoard() {
    _board = new Board(_reader->ReadBoardFromLabyrinthPath());
    std::pair<int, int> playerPos = _board->GetElementPosition(_reader->GetPlayerSymbol());
    _player = new Player(playerPos.first, playerPos.second, _reader->GetPlayerSymbol());
}