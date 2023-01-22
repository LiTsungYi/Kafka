#include "Pch.h"

#include "Kafka/Stream/InputFileStream.h"
#include "Kafka/Stream/OutputFileStream.h"

namespace Kafka::Stream
{

class InoutFileStream : public IFileStream, public IInputStream, public IOutputStream
{
public:
    InoutFileStream()
    {}

    InoutFileStream( const std::string& fileName, bool binary )
    {
        OpenFile( fileName, binary );
    }

    // Implements IFileStream
    virtual void SeekRead( size_t value );
    virtual void SkipRead( size_t value );

    // Implements IOutputStream
    virtual bool CanRead() const
    {
        return IsOpened();
    }

    // Implements IOutputStream
    virtual bool ReadBool();
    virtual Int8 ReadInt8();
    virtual Int16 ReadInt16();
    virtual Int32 ReadInt32();
    virtual Uint8 ReadUint8();
    virtual Uint16 ReadUint16();
    virtual Uint32 ReadUint32();
    virtual float ReadFloat();
    virtual double ReadDouble();
    virtual std::shared_ptr< char > ReadBytes( size_t length );
    virtual std::string ReadString( size_t length );

    // Implements IFileStream
    virtual void SeekWrite( size_t value );
    virtual void SkipWrite( size_t value );

    // Implements IInputStream
    virtual bool CanWrite() const
    {
        return IsOpened();
    }

    virtual void WriteBool( bool value );
    virtual void WriteInt8( Int8 value );
    virtual void WriteInt16( Int16 value );
    virtual void WriteInt32( Int32 value );
    virtual void WriteUint8( Uint8 value );
    virtual void WriteUint16( Uint16 value );
    virtual void WriteUint32( Uint32 value );
    virtual void WriteFloat( float value );
    virtual void WriteDouble( double value );
    virtual void WriteBytes( const char* value, size_t length );
    virtual void WriteString( const std::string& value );
    virtual void WriteWstring( const std::wstring& value );

private:
    virtual std::ios_base::openmode GetOpenFileMode()
    {
        return std::ios_base::in | std::ios_base::out;
    }
};

}  // namespace Kafka::Stream
