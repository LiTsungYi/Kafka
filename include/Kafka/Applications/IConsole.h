#pragma once

namespace Kafka
{
struct IConsole
{
    IConsole();
    virtual ~IConsole();

    virtual int Run() = 0;
};
} // namespace Kafka
