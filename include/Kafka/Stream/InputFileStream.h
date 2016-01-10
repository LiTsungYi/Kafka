#pragma once

#include <string>
#include <memory>
#include <fstream>
#include "Kafka\Stream\IFileStream.h"
#include "Kafka\Stream\IInputStream.h"

namespace Kafka
{

class InputFileStream : public IFileStream, public IInputStream
{
public:
    InputFileStream()
    {}

    InputFileStream( const std::string& fileName, bool binary )
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

private:
    virtual std::ios_base::openmode GetOpenFileMode()
    {
        return std::ios_base::in;
    }
};

} // namespace Kafka
