#include <string>

namespace Kafka
{

    struct IStream
    {
        bool ReadBool();
        char ReadInt8();
        short ReadInt16();
        int ReadInt32();
        unsigned char ReadUint8();
        unsigned short ReadUint16();
        unsigned int ReadUint32();
        float ReadFloat();
        double ReadDouble();
        std::string ReadString();

        size_t GetByte( size_t offset, size_t bytes, void* buf, size_t bufSize );
        size_t SetByte( size_t offset, size_t bytes, const void* buf, size_t bufSize );

    };

} // namespace Kafka
