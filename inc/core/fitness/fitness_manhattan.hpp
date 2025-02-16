#pragma once
#include "cell.hpp"
#include "ifitness.hpp"

namespace core
{
class FitnessManhattan : public core::Ifitness
{
public:
    virtual int calc_fitness(const tp::Graph& graph, const model::Chromosome& matrix)
    {
        auto& cells = matrix.get_cells();
        cells.at(1).print();
        return 0;
    };
private:
    int distance(const model::Cell& one, const model::Cell& two);
};
}
