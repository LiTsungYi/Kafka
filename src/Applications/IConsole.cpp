#include "Pch.h"

#ifdef DEBUG
#include <crtdbg.h>
#endif
#include "Kafka\Applications\IConsole.h"

namespace Kafka
{

IConsole::IConsole()
{
#ifdef DEBUG
    _CrtSetDbgFlag( _CRTDBG_REPORT_FLAG | _CRTDBG_LEAK_CHECK_DF );
    //_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif
}

IConsole::~IConsole()
{
#ifdef DEBUG
    _CrtDumpMemoryLeaks();
#endif
}

} // namespace Kafka
