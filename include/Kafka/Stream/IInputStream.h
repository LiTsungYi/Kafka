#include <string>
#include <memory>
#include "Kafka\Stream\IStream.h"

namespace Kafka
{
    struct IInputStream : public IStream
    {
        virtual bool CanRead() const = 0;

        virtual bool ReadBool() = 0;
        virtual char ReadInt8() = 0;
        virtual short ReadInt16() = 0;
        virtual int ReadInt32() = 0;
        virtual unsigned char ReadUint8() = 0;
        virtual unsigned short ReadUint16() = 0;
        virtual unsigned int ReadUint32() = 0;
        virtual float ReadFloat() = 0;
        virtual double ReadDouble() = 0;
        virtual std::shared_ptr< char > ReadBytes( size_t length ) = 0;
        virtual std::string ReadString( size_t length ) = 0;
    };
} // namespace Kafka
