#pragma once

#include <memory>
#include <vector>
#include <deque>
#include <thread>
#include "Kafka/Threads/ThreadInfo.h"
#include "Kafka/Threads/Schedulable.h"
#include "Kafka/Threads/internals/JobInfo.h"

namespace Kafka::Threads
{

class ThreadPool
{
public:
    explicit ThreadPool(const size_t size);

    void Stop();
    bool Execute();
    void Submit(const std::string& name, const Action& action);
    void Submit(const std::string& name, const Action& action, const Schedulable& barrior);

private:
    void ExecuteThread(ThreadInfo& threadInfo);

private:
    std::mutex threadMutex;
    size_t size;
    bool stopping;
    std::vector<std::thread> threads;
    std::vector<ThreadInfo> threadInfos;
    std::deque<Internal::JobInfo> jobQueue;

};

}  // namespace Kafka::Threads
