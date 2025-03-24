#pragma once
#include "icrossover.hpp"
#include "types.hpp"

namespace core
{
class CrossoverUniform : public Icrossover
{
public:
    tp::ChromosomePtr crossover(const tp::ChromosomePtr&, const tp::ChromosomePtr&) override;
};
}
