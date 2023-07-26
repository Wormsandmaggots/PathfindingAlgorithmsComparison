//
// Created by 48782 on 26.07.2023.
//

#include <fstream>
#include <iostream>
#include "Data/include/TxtWriter.h"

TxtWriter::TxtWriter(std::string path) : Writer(path){
    std::ofstream ofs(path, std::ios::out | std::ios::trunc);
    ofs.close();
}

void TxtWriter::ToQueue(std::string info) {
    std::lock_guard<std::mutex> lock(*GetMutex());

    GetQueue()->push(info);

    GetCondition()->notify_one();
}

void TxtWriter::ToFile() {
    std::function<void()> action = [this]() {
        while (true) {
            std::cout << "dupa" << std::endl;
            std::unique_lock<std::mutex> lock(*GetMutex());

            bool queueNotEmpty = GetCondition()->wait_for(
                    lock, std::chrono::milliseconds(10), [&]() { return !GetQueue()->empty(); }
            );

            if (queueNotEmpty) {
                std::ofstream file(GetPath(), std::ios::app);
                while (!GetQueue()->empty()) {
                    file << GetQueue()->front() << std::endl;
                    GetQueue()->pop();
                }
            }

            lock.unlock();

            //std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    };

    std::thread fileThread(action);
    fileThread.detach();
}