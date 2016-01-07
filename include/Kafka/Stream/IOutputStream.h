#include <string>
#include "Kafka/Basic/Types.h"
#include "Kafka/Stream/IStream.h"

namespace Kafka
{
struct IOutputStream : public IStream
{
    virtual void SeekWrite( size_t value ) = 0;
    virtual void SkipWrite( size_t value ) = 0;
    virtual bool CanWrite() const = 0;

    virtual void WriteBool( bool value ) = 0;
    virtual void WriteInt8( Int8 value ) = 0;
    virtual void WriteInt16( Int16 value ) = 0;
    virtual void WriteInt32( Int32 value ) = 0;
    virtual void WriteUint8( Uint8 value ) = 0;
    virtual void WriteUint16( Uint16 value ) = 0;
    virtual void WriteUint32( Uint32 value ) = 0;
    virtual void WriteFloat( float value ) = 0;
    virtual void WriteDouble( double value ) = 0;
    virtual void WriteBytes( const char* value, size_t length ) = 0;
    virtual void WriteString( const std::string& value ) = 0;
    virtual void WriteWstring( const std::wstring& value ) = 0;
};
} // namespace Kafka
