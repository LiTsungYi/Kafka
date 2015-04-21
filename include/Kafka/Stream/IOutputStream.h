#include <string>

namespace Kafka
{
    struct IOutputStream
    {
        virtual bool CanWrite() const = 0;

        virtual void WriteBool( bool value ) = 0;
        virtual void WriteInt8( char value ) = 0;
        virtual void WriteInt16( short value ) = 0;
        virtual void WriteInt32( int value ) = 0;
        virtual void WriteUint8( unsigned char value ) = 0;
        virtual void WriteUint16( unsigned short value ) = 0;
        virtual void WriteUint32( unsigned int value ) = 0;
        virtual void WriteFloat( float value ) = 0;
        virtual void WriteDouble( double value ) = 0;
        virtual void WriteBytes( const char* value, size_t length ) = 0;
        virtual void WriteString( const std::string& value ) = 0;
    };
} // namespace Kafka
