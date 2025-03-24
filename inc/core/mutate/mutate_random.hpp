#pragma once 
#include "imutate.hpp"
#include "types.hpp"

namespace core
{
class MutateRandom : public Imutate
{
public:
    tp::VectorPairChromPtr mutate(tp::VectorPairChromPtr vals);
};
}
