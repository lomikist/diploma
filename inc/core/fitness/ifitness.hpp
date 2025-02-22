#pragma once
#include "types.hpp"

namespace core {
class Ifitness 
{
public:
    virtual int calc_fitness(const tp::Graph& graph, const tp::ChromosomePtr& matrix) = 0; 
};
}
