#pragma once
#include "icrossover.hpp"
#include "ifitness.hpp"
#include "types.hpp"

namespace core {
class Iselect 
{
public:
    virtual tp::VectorPairChromPtr evaluate(std::shared_ptr<Ifitness>, 
                                            std::shared_ptr<Icrossover>,  
                                            tp::Graph, 
                                            tp::VectorPairChromPtr) = 0;
};
}
