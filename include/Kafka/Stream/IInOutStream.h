#include "IInputStream.h"
#include "IOutputStream.h"

namespace Kafka
{
    struct IInOutStream : public IInputStream, public IOutputStream
    {
    };
} // namespace Kafka
