#include "Pch.h"

#include <cassert>
#include "Kafka/Stream/InoutFileStream.h"

namespace Kafka::Stream
{

void InoutFileStream::SeekRead( size_t value )
{
    assert( IsOpened() && "�ɮץ����}��" );

    m_stream.seekg( value, std::ios_base::beg );
}

void InoutFileStream::SeekWrite( size_t value )
{
    assert( IsOpened() && "�ɮץ����}��" );

    m_stream.seekp( value, std::ios_base::beg );
}

void InoutFileStream::SkipRead( size_t value )
{
    assert( IsOpened() && "�ɮץ����}��" );

    m_stream.seekg( value, std::ios_base::cur );
}

void InoutFileStream::SkipWrite( size_t value )
{
    assert( IsOpened() && "�ɮץ����}��" );

    m_stream.seekp( value, std::ios_base::cur );
}

bool InoutFileStream::ReadBool()
{
    assert( IsOpened() && "�ɮץ����}��" );

    char buffer[ sizeof( bool ) ];
    m_stream.read( buffer, sizeof( bool ) );
    return buffer[0] != 0;
}

Int8 InoutFileStream::ReadInt8()
{
    assert( IsOpened() && "�ɮץ����}��" );

    char buffer[ sizeof( char ) ];
    m_stream.read( buffer, sizeof( char ) );
    return buffer[0];
}

Int16 InoutFileStream::ReadInt16()
{
    assert( IsOpened() && "�ɮץ����}��" );

    char buffer[ sizeof( short ) ];
    m_stream.read( buffer, sizeof( short ) );
    return *( ( short* ) buffer );
}

Int32 InoutFileStream::ReadInt32()
{
    assert( IsOpened() && "�ɮץ����}��" );

    char buffer[ sizeof( int ) ];
    m_stream.read( buffer, sizeof( int ) );
    return *( ( int* ) buffer );
}

Uint8 InoutFileStream::ReadUint8()
{
    assert( IsOpened() && "�ɮץ����}��" );

    char buffer[ sizeof( unsigned char ) ];
    m_stream.read( buffer, sizeof( unsigned char ) );
    return *( ( unsigned char* ) buffer );
}

Uint16 InoutFileStream::ReadUint16()
{
    assert( IsOpened() && "�ɮץ����}��" );

    char buffer[ sizeof( unsigned short ) ];
    m_stream.read( buffer, sizeof( unsigned short ) );
    return *( ( unsigned short* ) buffer );
}

Uint32 InoutFileStream::ReadUint32()
{
    assert( IsOpened() && "�ɮץ����}��" );

    char buffer[ sizeof( unsigned int ) ];
    m_stream.read( buffer, sizeof( unsigned int ) );
    return *( ( unsigned int* ) buffer );
}

float InoutFileStream::ReadFloat()
{
    assert( IsOpened() && "�ɮץ����}��" );

    char buffer[ sizeof( float ) ];
    m_stream.read( buffer, sizeof( float ) );
    return *( ( float* ) buffer );
}

double InoutFileStream::ReadDouble()
{
    assert( IsOpened() && "�ɮץ����}��" );

    char buffer[ sizeof( double ) ];
    m_stream.read( buffer, sizeof( double ) );
    return *( ( double* ) buffer );
}

std::shared_ptr< char > InoutFileStream::ReadBytes( size_t length )
{
    std::shared_ptr< char > buffer = std::shared_ptr< char >( new char[ length + 1 ] );
    m_stream.read( buffer.get(), length );
    buffer.get()[ length ] = '\0';
    return buffer;
}

std::string InoutFileStream::ReadString( size_t length )
{
    std::shared_ptr< char > buffer = std::shared_ptr< char >( new char[ length ] );
    m_stream.read( buffer.get(), length );
    return std::string( buffer.get(), length );
}


void InoutFileStream::WriteBool( bool value )
{
    m_stream.write( reinterpret_cast< char* >( &value ), sizeof( bool ) );
}

void InoutFileStream::WriteInt8( Int8 value )
{
    m_stream.write( reinterpret_cast< char* >( &value ), sizeof( Int8 ) );
}

void InoutFileStream::WriteInt16( Int16 value )
{
    m_stream.write( reinterpret_cast< char* >( &value ), sizeof( Int16 ) );
}

void InoutFileStream::WriteInt32( Int32 value )
{
    m_stream.write( reinterpret_cast< char* >( &value ), sizeof( Int32 ) );
}

void InoutFileStream::WriteUint8( Uint8 value )
{
    m_stream.write( reinterpret_cast< char* >( &value ), sizeof( Uint8 ) );
}

void InoutFileStream::WriteUint16( Uint16 value )
{
    m_stream.write( reinterpret_cast< char* >( &value ), sizeof( Uint16 ) );
}

void InoutFileStream::WriteUint32( Uint32 value )
{
    m_stream.write( reinterpret_cast< char* >( &value ), sizeof( Uint32 ) );
}

void InoutFileStream::WriteFloat( float value )
{
    m_stream.write( reinterpret_cast< char* >( &value ), sizeof( float ) );
}

void InoutFileStream::WriteDouble( double value )
{
    m_stream.write( reinterpret_cast< char* >( &value ), sizeof( double ) );
}

void InoutFileStream::WriteBytes( const char* value, size_t length )
{
    m_stream.write( value, length );
}

void InoutFileStream::WriteString( const std::string& value )
{
    m_stream.write( value.c_str(), value.length() );
}

void InoutFileStream::WriteWstring( const std::wstring& value )
{
    m_stream.write( reinterpret_cast<const char*>( value.c_str() ), value.length() * sizeof( wchar_t ) );
}

}  // namespace Kafka::Stream
