#pragma once

#include <functional>
#include <string>
#include "Kafka/Threads/Schedulable.h"

namespace Kafka::Threads::Internal
{

struct JobInfo
{
    using Action = std::function<void ()>;

    JobInfo(const std::string& name, const Action& action)
        : name(name)
        , action(action)
    {
    }

    JobInfo(const std::string& name, const Action& action, const Schedulable& schedulable)
        : name(name)
        , action(action)
        , schedulable(schedulable)
    {
    }

    std::string name;
    Action action;
    Schedulable schedulable;
};

}  // namespace Kafka::Threads::Internal
