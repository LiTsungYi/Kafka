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
        virtual void Seek( size_t value );
        virtual void Skip( size_t value );

        // Implements IOutputStream
        virtual bool CanRead() const
        {
            return IsOpened();
        }

        virtual bool ReadBool();
        virtual char ReadInt8();
        virtual short ReadInt16();
        virtual int ReadInt32();
        virtual unsigned char ReadUint8();
        virtual unsigned short ReadUint16();
        virtual unsigned int ReadUint32();
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

}