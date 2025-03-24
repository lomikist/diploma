#pragma once
#include "icrossover.hpp"
#include "types.hpp"

namespace core
{
class CrossoverOnePoint : public Icrossover
{
public:
    tp::ChromosomePtr crossover(const tp::ChromosomePtr&, const tp::ChromosomePtr&) override;
};
}
