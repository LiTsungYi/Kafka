#pragma once

namespace Kafka
{
    struct IConsole
    {
    public:
        IConsole();
        virtual ~IConsole();

        virtual int Run() = 0;

    };

} // namespace Kafka
