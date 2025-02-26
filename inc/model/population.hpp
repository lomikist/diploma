#pragma once
#include "types.hpp"

namespace model
{
class Population
{
public:
    Population(const tp::Graph& graph, int pop_size, int width, int height);

    const std::vector<tp::ChromosomePtr>&   get_chromosomes() const;
    const tp::ChromosomePtr&                get_chromosome(int index) const;
    void set_chromosome(int index, const tp::ChromosomePtr& chrom);
    void set_chromosomes(const std::vector<tp::ChromosomePtr>&);
    void print() const;
private:
    std::vector<tp::ChromosomePtr> m_chroms;
};
};
