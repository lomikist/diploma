#pragma once
#include "types.hpp"

namespace core
{
class Imutate
{
public:
    virtual tp::VectorPairChromPtr mutate(tp::VectorPairChromPtr vals) = 0;
    virtual ~Imutate() = default;
};
}
