#pragma once
#include "icrossover.hpp"
#include "ifitness.hpp"
#include "types.hpp"

namespace core {
class Iselect 
{
public:
    virtual tp::VectorPairChromPtr cross_select(std::shared_ptr<Ifitness>, 
                                            std::shared_ptr<Icrossover>,  
                                            const tp::Graph&, 
                                            tp::VectorPairChromPtr) = 0;
    virtual ~Iselect() = default;
};
}
