//
// Created by 48782 on 26.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_WRITER_H
#define PATHFINDINGALGORITHMSCOMPARISON_WRITER_H

#include <string>
#include <queue>
#include <mutex>
#include <condition_variable>

class Writer {
public:
    explicit Writer(std::string path);
    virtual ~Writer();

    virtual void ToQueue(std::string) = 0;
    virtual void ToFile() = 0;
    virtual void StopWriting();
    void ChangeToWriteFile(std::string);
    std::string GetPath() const;
    std::mutex* GetMutex() const;
    std::queue<std::string>* GetQueue() const;
    std::condition_variable* GetCondition() const;
    bool IsQueueEmpty() const;
    bool IsThreadRunning() const;

protected:
    void SetIsQueueEmpty(bool isQueueEmpty);
    void SetThread(std::shared_ptr<std::thread>);
    std::shared_ptr<std::thread> GetThread() const;
    void SetIsRunning(bool);

private:
    std::string _pathToFile;
    std::queue<std::string>* _queue;
    std::mutex* _queueMutex;
    std::condition_variable* _queueCondition;
    std::shared_ptr<std::thread> _fileThread;
    bool _isQueueEmpty = true;
    bool _isRunning;
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_WRITER_H
