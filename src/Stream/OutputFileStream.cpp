#include "Pch.h"

#include <cassert>
#include "Kafka\Stream\OutputFileStream.h"

namespace Kafka
{
    void OutputFileStream::Seek( size_t value )
    {
        assert( IsOpened() && "檔案必須開啟" );

        m_stream.seekp( value, std::ios_base::beg );
    }

    void OutputFileStream::Skip( size_t value )
    {
        assert( IsOpened() && "檔案必須開啟" );

        m_stream.seekp( value, std::ios_base::cur );
    }

    void OutputFileStream::WriteBool( bool value )
    {
        m_stream.write( reinterpret_cast< char* >( &value ), sizeof( bool ) );
    }

    void OutputFileStream::WriteInt8( char value )
    {
        m_stream.write( reinterpret_cast< char* >( &value ), sizeof( char ) );
    }

    void OutputFileStream::WriteInt16( short value )
    {
        m_stream.write( reinterpret_cast< char* >( &value ), sizeof( short ) );
    }

    void OutputFileStream::WriteInt32( int value )
    {
        m_stream.write( reinterpret_cast< char* >( &value ), sizeof( int ) );
    }

    void OutputFileStream::WriteUint8( unsigned char value )
    {
        m_stream.write( reinterpret_cast< char* >( &value ), sizeof( unsigned char ) );
    }

    void OutputFileStream::WriteUint16( unsigned short value )
    {
        m_stream.write( reinterpret_cast< char* >( &value ), sizeof( unsigned short ) );
    }

    void OutputFileStream::WriteUint32( unsigned int value )
    {
        m_stream.write( reinterpret_cast< char* >( &value ), sizeof( unsigned int ) );
    }

    void OutputFileStream::WriteFloat( float value )
    {
        m_stream.write( reinterpret_cast< char* >( &value ), sizeof( float ) );
    }

    void OutputFileStream::WriteDouble( double value )
    {
        m_stream.write( reinterpret_cast< char* >( &value ), sizeof( double ) );
    }

    void OutputFileStream::WriteBytes( const char* value, size_t length )
    {
        m_stream.write( value, length );
    }

    void OutputFileStream::WriteString( const std::string& value )
    {
        m_stream.write( value.c_str(), value.length() );
    }
} // namespace Kafka
