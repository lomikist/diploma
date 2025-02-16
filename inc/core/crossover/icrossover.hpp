#pragma once
#include "chromosome.hpp"
namespace core 
{
class Icrossover
{
public:
    virtual model::Chromosome crossover(const model::Chromosome&, const model::Chromosome&) = 0;
};
}
