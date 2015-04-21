#include "Pch.h"

#include <cassert>
#include <memory>
#include "Kafka\Stream\InputFileStream.h"

namespace Kafka
{
    void InputFileStream::Seek( size_t value )
    {
        assert( IsOpened() && "檔案必須開啟" );

        m_stream.seekg( value, std::ios_base::beg );
    }

    void InputFileStream::Skip( size_t value )
    {
        assert( IsOpened() && "檔案必須開啟" );

        m_stream.seekg( value, std::ios_base::cur );
    }

    bool InputFileStream::ReadBool()
    {
        assert( IsOpened() && "檔案必須開啟" );

        char buffer[ sizeof( bool ) ];
        m_stream.read( buffer, sizeof( bool ) );
        return buffer != 0;
    }

    char InputFileStream::ReadInt8()
    {
        assert( IsOpened() && "檔案必須開啟" );

        char buffer[ sizeof( char ) ];
        m_stream.read( buffer, sizeof( char ) );
        return buffer[ 0 ];
    }

    short InputFileStream::ReadInt16()
    {
        assert( IsOpened() && "檔案必須開啟" );

        char buffer[ sizeof( short ) ];
        m_stream.read( buffer, sizeof( short ) );
        return *( ( short* ) buffer );
    }

    int InputFileStream::ReadInt32()
    {
        assert( IsOpened() && "檔案必須開啟" );

        char buffer[ sizeof( int ) ];
        m_stream.read( buffer, sizeof( int ) );
        return *( ( int* ) buffer );
    }

    unsigned char InputFileStream::ReadUint8()
    {
        assert( IsOpened() && "檔案必須開啟" );

        char buffer[ sizeof( unsigned char ) ];
        m_stream.read( buffer, sizeof( unsigned char ) );
        return *( ( unsigned char* ) buffer );
    }

    unsigned short InputFileStream::ReadUint16()
    {
        assert( IsOpened() && "檔案必須開啟" );

        char buffer[ sizeof( unsigned short ) ];
        m_stream.read( buffer, sizeof( unsigned short ) );
        return *( ( unsigned short* ) buffer );
    }

    unsigned int InputFileStream::ReadUint32()
    {
        assert( IsOpened() && "檔案必須開啟" );

        char buffer[ sizeof( unsigned int ) ];
        m_stream.read( buffer, sizeof( unsigned int ) );
        return *( ( unsigned int* ) buffer );
    }

    float InputFileStream::ReadFloat()
    {
        assert( IsOpened() && "檔案必須開啟" );

        char buffer[ sizeof( float ) ];
        m_stream.read( buffer, sizeof( float ) );
        return *( ( float* ) buffer );
    }

    double InputFileStream::ReadDouble()
    {
        assert( IsOpened() && "檔案必須開啟" );

        char buffer[ sizeof( double ) ];
        m_stream.read( buffer, sizeof( double ) );
        return *( ( double* ) buffer );
    }

    std::shared_ptr< char > InputFileStream::ReadBytes( size_t length )
    {
        std::shared_ptr< char > buffer = std::shared_ptr< char >( new char[ length + 1 ] );
        m_stream.read( buffer.get(), length );
        buffer.get()[ length ] = '\0';
        return buffer;
    }

    std::string InputFileStream::ReadString( size_t length )
    {
        std::shared_ptr< char > buffer = std::shared_ptr< char >( new char[ length ] );
        m_stream.read( buffer.get(), length );
        return std::string( buffer.get(), length );
    }
} // namespace Kafka
