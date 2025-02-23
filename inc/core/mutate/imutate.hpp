#pragma once
#include "types.hpp"

namespace core
{
class Imutate
{
public:
    virtual void mutate(const tp::VectorPairChromPtr& vals) = 0;
    virtual ~Imutate() = default;
};
}
