#pragma once
#include "chromosome.hpp"
#include "icrossover.hpp"

namespace core
{
class CrossoverTwoPoint : public Icrossover
{
public:
    model::Chromosome crossover(const model::Chromosome&, const model::Chromosome&) override;
};
}
