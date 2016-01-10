#pragma once

#include <memory>

namespace Kafka
{

struct IOutputStream;
struct IInputStream;

struct ISerializable
{
    virtual void WriteToStream( std::shared_ptr<IOutputStream> stream ) = 0;
    virtual void ReadFromStream( std::shared_ptr<IInputStream> stream ) = 0;
};

} // namespace Kafka
