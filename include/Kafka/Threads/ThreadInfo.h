#pragma once

#include <thread>
#include <functional>
#include "Kafka/Threads/internals/JobInfo.h"

namespace Kafka::Threads
{

using Action = std::function<void ()>;

class ThreadInfo
{
public:
    enum class State
    {
        IDLE,
        READY,
        RUNNING,
    };

    ThreadInfo();

    bool IsIdle() const
    {
        return state == State::IDLE;
    }

    void Run(const Internal::JobInfo& job);
    void Execute();

private:
    void Idle();

private:
    State state;
    std::string name;
    Action action;

};

}  // namespace Kafka::Threads
