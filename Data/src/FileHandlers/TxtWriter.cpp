//
// Created by 48782 on 26.07.2023.
//

#include <fstream>
#include <iostream>
#include "Data/include/FileHandlers/TxtWriter.h"

TxtWriter::TxtWriter(std::string path) : Writer(path){
    std::ofstream ofs(path, std::ios::out | std::ios::trunc);
    ofs.close();
}

void TxtWriter::ToQueue(std::string info) {
    std::lock_guard<std::mutex> lock(*GetMutex());

    GetQueue()->push(info);

    GetCondition()->notify_one();
}

void TxtWriter::WriteAsync() {
    std::function<void()> action = [this]() {
        SetIsRunning(true);
        while (IsThreadRunning()) {
            std::unique_lock<std::mutex> lock(*GetMutex());

            GetCondition()->wait(lock, [&]() { return !GetQueue()->empty(); });

            if (!IsQueueEmpty()) {
                std::ofstream file(GetPath(), std::ios::app);
                while (!IsQueueEmpty()) {
                    file << GetQueue()->front() << std::endl;
                    GetQueue()->pop();
                }

            }

            lock.unlock();

        }
    };

    std::shared_ptr<std::thread> fileThread = std::make_shared<std::thread>(action);
    fileThread->detach();
    SetThread(fileThread);
}

void TxtWriter::WriteAll() {
    std::ofstream file(GetPath(), std::ios::app);
    while(!IsQueueEmpty())
    {
        file << GetQueue()->front() << std::endl;
        GetQueue()->pop();
    }
}
