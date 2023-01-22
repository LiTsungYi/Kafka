#include <string>
#include <memory>
#include "Kafka/Basic/Types.h"
#include "Kafka/Stream/IStream.h"

namespace Kafka::Stream
{

struct IInputStream : public IStream
{
    virtual void SeekRead( size_t value ) = 0;
    virtual void SkipRead( size_t value ) = 0;
    virtual bool CanRead() const = 0;

    virtual bool ReadBool() = 0;
    virtual Int8 ReadInt8() = 0;
    virtual Int16 ReadInt16() = 0;
    virtual Int32 ReadInt32() = 0;
    virtual Uint8 ReadUint8() = 0;
    virtual Uint16 ReadUint16() = 0;
    virtual Uint32 ReadUint32() = 0;
    virtual float ReadFloat() = 0;
    virtual double ReadDouble() = 0;
    virtual std::shared_ptr< char > ReadBytes( size_t length ) = 0;
    virtual std::string ReadString( size_t length ) = 0;
};

}  // namespace Kafka::Stream
