#pragma once
#include "chromosome.hpp"
#include "types.hpp"
namespace core 
{
class Icrossover
{
public:
    virtual tp::ChromosomePtr crossover(const tp::ChromosomePtr&, const tp::ChromosomePtr&) = 0 ;
    virtual ~Icrossover() = default;
};
}
