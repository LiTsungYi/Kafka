#pragma once

namespace Kafka
{

struct Noncopyable
{
    Noncopyable(const Noncopyable&) = delete;
    Noncopyable& operator=(Noncopyable& ) = delete;
};

}  // namespace Kafka
