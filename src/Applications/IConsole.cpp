#include "Pch.h"

#include <crtdbg.h>
#include "Kafka\Applications\IConsole.h"

namespace Kafka
{

    IConsole::IConsole()
    {
        _CrtSetDbgFlag( _CRTDBG_REPORT_FLAG | _CRTDBG_LEAK_CHECK_DF );
        //_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
    }

    IConsole::~IConsole()
    {
        _CrtDumpMemoryLeaks();
    }

} // namespace Kafka
