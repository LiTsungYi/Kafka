#pragma once

#include <string>
#include <fstream>
#include "Kafka\Stream\IFileStream.h"
#include "Kafka\Stream\IOutputStream.h"

namespace Kafka
{
    class OutputFileStream : public IFileStream, public IOutputStream
    {
    public:
        OutputFileStream()
        {
        }

        OutputFileStream( const std::string& fileName, bool binary )
        {
            OpenFile( fileName, binary );
        }

        // Implements IFileStream
        virtual void Seek( size_t value );
        virtual void Skip( size_t value );

        // Implements IInputStream
        virtual bool CanWrite() const
        {
            return IsOpened();
        }

        virtual void WriteBool( bool value );
        virtual void WriteInt8( char value );
        virtual void WriteInt16( short value );
        virtual void WriteInt32( int value );
        virtual void WriteUint8( unsigned char value );
        virtual void WriteUint16( unsigned short value );
        virtual void WriteUint32( unsigned int value );
        virtual void WriteFloat( float value );
        virtual void WriteDouble( double value );
        virtual void WriteBytes( const char* value, size_t length );
        virtual void WriteString( const std::string& value );

    private:
        virtual std::ios_base::openmode GetOpenFileMode()
        {
            return std::ios_base::out;
        }
    };
} // namespace Kafka
