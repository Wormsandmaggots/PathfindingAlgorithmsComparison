//
// Created by 48782 on 26.07.2023.
//

#include "Data/include/Writer.h"

Writer::Writer(std::string path) : _pathToFile(path) {
    _queue = new std::queue<std::string>();
    _queueMutex = new std::mutex();
    _queueCondition = new std::condition_variable();
}

std::queue<std::string>* Writer::GetQueue() const {
    return _queue;
}

std::mutex* Writer::GetMutex() const {
    return _queueMutex;
}

std::string Writer::GetPath() const {
    return _pathToFile;
}

std::condition_variable *Writer::GetCondition() const {
    return _queueCondition;
}

Writer::~Writer() {
    delete _queue;
    delete _queueMutex;
    delete _queueCondition;
}
