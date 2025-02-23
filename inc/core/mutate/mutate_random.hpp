#pragma once 
#include "imutate.hpp"
#include "types.hpp"

namespace core
{
class MutateRandom : public Imutate
{
public:
    void mutate(const tp::VectorPairChromPtr& vals);
};
}
