#include "Pch.h"

#include <cassert>
#include "Kafka/Stream/OutputFileStream.h"

namespace Kafka::Stream
{

void OutputFileStream::SeekWrite( size_t value )
{
    assert( IsOpened() && "�ɮץ����}��" );
    if ( !IsOpened() )
    {
        return;
    }

    m_stream.seekp( value, std::ios_base::beg );
}

void OutputFileStream::SkipWrite( size_t value )
{
    assert( IsOpened() && "�ɮץ����}��" );
    if ( !IsOpened() )
    {
        return;
    }

    m_stream.seekp( value, std::ios_base::cur );
}

void OutputFileStream::WriteBool( bool value )
{
    m_stream.write( reinterpret_cast< char* >( &value ), sizeof( bool ) );
}

void OutputFileStream::WriteInt8( Int8 value )
{
    m_stream.write( reinterpret_cast< char* >( &value ), sizeof( Int8 ) );
}

void OutputFileStream::WriteInt16( Int16 value )
{
    m_stream.write( reinterpret_cast< char* >( &value ), sizeof( Int16 ) );
}

void OutputFileStream::WriteInt32( Int32 value )
{
    m_stream.write( reinterpret_cast< char* >( &value ), sizeof( Int32 ) );
}

void OutputFileStream::WriteUint8( Uint8 value )
{
    m_stream.write( reinterpret_cast< char* >( &value ), sizeof( Uint8 ) );
}

void OutputFileStream::WriteUint16( Uint16 value )
{
    m_stream.write( reinterpret_cast< char* >( &value ), sizeof( Uint16 ) );
}

void OutputFileStream::WriteUint32( Uint32 value )
{
    m_stream.write( reinterpret_cast< char* >( &value ), sizeof( Uint32 ) );
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

void OutputFileStream::WriteWstring( const std::wstring& value )
{
    m_stream.write( reinterpret_cast<const char*>( value.c_str() ), value.length() * sizeof( wchar_t ) );
}

}  // namespace Kafka::Stream
