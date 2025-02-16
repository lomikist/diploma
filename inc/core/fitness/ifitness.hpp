#pragma once
#include "chromosome.hpp"
#include "types.hpp"

namespace core {
class Ifitness 
{
public:
    virtual int calc_fitness(const tp::Graph& graph, const model::Chromosome& matrix) = 0; 
};
}
