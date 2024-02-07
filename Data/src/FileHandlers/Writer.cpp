//
// Created by 48782 on 26.07.2023.
//

#include <fstream>
#include <iostream>
#include "Data/include/FileHandlers/Writer.h"

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

bool Writer::IsQueueEmpty() const {
    return _queue->empty();
}

void Writer::SetThread(std::shared_ptr<std::thread> thread) {
    if (_fileThread && _fileThread->joinable())
        _fileThread->join();
    
    _fileThread = thread;
}

std::shared_ptr<std::thread> Writer::GetThread() const {
    return _fileThread;
}

void Writer::StopWriting() {
    if (_fileThread && _fileThread->joinable()) {
        SetIsRunning(false);
        GetCondition()->notify_one();
        _fileThread->join();
    }
}

bool Writer::IsThreadRunning() const {
    return _isRunning;
}

void Writer::SetIsRunning(bool val) {
    _isRunning = val;
}

void Writer::ChangeToWriteFile(std::string newFile) {
    _pathToFile = newFile;
    std::ofstream ofs(_pathToFile, std::ios::out | std::ios::trunc);
    ofs.close();
}
