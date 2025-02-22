#pragma once
#include "cell.hpp"
#include "ifitness.hpp"
#include "types.hpp"

namespace core
{
class FitnessManhattan : public core::Ifitness
{
public:
    int calc_fitness(const tp::Graph& graph, const tp::ChromosomePtr& matrix) override;
private:
    std::size_t distance(const model::Cell& one, const model::Cell& two);
};
}
