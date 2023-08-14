#include <iostream>
#include "Kafka/Threads/ThreadInfo.h"

namespace Kafka::Threads
{

ThreadInfo::ThreadInfo()
    : state {State::IDLE}
{
}

void ThreadInfo::Run(const Internal::JobInfo& job)
{
    if (state == State::IDLE)
    {
        name = job.name;
        action = job.action;
        state = State::READY;
    }
}

void ThreadInfo::Execute()
{
    if (state == State::READY)
    {
        state = State::RUNNING;
        action();
        state = State::IDLE;
    }
    else
    {
        Idle();
    }
}

void ThreadInfo::Idle()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

}  // namespace Kafka::Threads
