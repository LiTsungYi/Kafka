#pragma once

namespace Kafca
{
    struct IConsole
    {
    public:
        IConsole();
        virtual ~IConsole();

        virtual int Run() = 0;

    };

} // namespace Kafca
