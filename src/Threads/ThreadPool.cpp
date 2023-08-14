#include <iostream>
#include "Kafka/Threads/ThreadPool.h"
#include "Kafka/Threads/ThreadInfo.h"

namespace Kafka::Threads
{

ThreadPool::ThreadPool(const size_t size)
    : size {size}
    , stopping(false)
    , threads(std::vector<std::thread>(size))
    , threadInfos(std::vector<ThreadInfo>(size))
{
    for (auto i = 0; i < size; ++i)
    {
        threadInfos.push_back(ThreadInfo());
        threads.push_back(std::thread(std::bind(&ThreadPool::ExecuteThread, this, std::ref(threadInfos[i]))));
    }
}

void ThreadPool::Stop()
{
    const std::lock_guard<std::mutex> lock(threadMutex);
    for (auto& threadInfo : threadInfos)
    {
        stopping = true;
        jobQueue.clear();
    }
}

bool ThreadPool::Execute()
{
    const std::lock_guard<std::mutex> lock(threadMutex);
    for (auto& threadInfo : threadInfos)
    {
        if (threadInfo.IsIdle() && !jobQueue.empty())
        {
            const auto& job = jobQueue.front();
            jobQueue.pop_front();
            threadInfo.Run(job);
        }
    }

    if (stopping)
    {
        for (auto& thread : threads)
        {
            if (thread.joinable())
            {
                thread.join();
            }
        }

        return false;
    }
    else
    {
        return true;
    }
}

void ThreadPool::Submit(const std::string& name, const Action& action)
{
    std::lock_guard<std::mutex> lock(threadMutex);
    jobQueue.push_back(Internal::JobInfo { name, action } );
}

void ThreadPool::Submit(const std::string& name, const Action& action, const Schedulable& schedulable)
{
    std::lock_guard<std::mutex> lock(threadMutex);
    jobQueue.push_back(Internal::JobInfo { name, action, schedulable } );
}

void ThreadPool::ExecuteThread(ThreadInfo& threadInfo)
{
    while(!stopping)
    {
        threadInfo.Execute();
    }
}

}  // namespace Kafka::Threads
