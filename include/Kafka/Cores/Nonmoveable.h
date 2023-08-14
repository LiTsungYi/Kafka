#pragma once

namespace Kafka
{

struct Nonmoveable
{
    Nonmoveable(const Nonmoveable&&) = delete;
    Nonmoveable& operator=(const Nonmoveable&& ) = delete;
};

}  // namespace Kafka
