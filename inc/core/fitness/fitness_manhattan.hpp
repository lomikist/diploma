#pragma once
#include "cell.hpp"
#include "ifitness.hpp"

namespace core
{
class FitnessManhattan : public core::Ifitness
{
public:
    virtual int calc_fitness(const tp::Graph& graph, const model::Chromosome& matrix);
private:
    std::size_t distance(const model::Cell& one, const model::Cell& two);
};
}
