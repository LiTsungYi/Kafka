#pragma once

namespace Kafka
{
    struct IStream
    {
        virtual void Seek( size_t value ) = 0;
        virtual void Skip( size_t value ) = 0;
    };
} // namespace Kafka
