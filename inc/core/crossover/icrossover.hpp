#pragma once
#include "chromosome.hpp"
#include "types.hpp"
namespace core 
{
class Icrossover
{
public:
    // Return a new chromosome
    virtual tp::ChromosomePtr crossover(const tp::ChromosomePtr&, const tp::ChromosomePtr&) = 0 ;
    virtual ~Icrossover() = default;
};
}
