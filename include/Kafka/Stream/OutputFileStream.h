#pragma once

#include <string>
#include <fstream>
#include "Kafka/Stream/IFileStream.h"
#include "Kafka/Stream/IOutputStream.h"

namespace Kafka::Stream
{

class OutputFileStream : public IFileStream, public IOutputStream
{
public:
    OutputFileStream()
    {}

    OutputFileStream( const std::string& fileName, bool binary )
    {
        OpenFile( fileName, binary );
    }

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
        return std::ios_base::out;
    }
};

}  // namespace Kafka::Stream
