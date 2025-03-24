#pragma once
#include "types.hpp"

namespace model
{
class Population
{
public:
    Population(const tp::Graph& graph, int pop_size, int width, int height);
    const tp::VectorPairChromPtr&               get_chromosomes() const;
    const std::pair<tp::ChromosomePtr, int>&    get_chromosome(int index) const;

    void set_chromosomes(const tp::VectorPairChromPtr&);
    void set_chromosome(int index, const tp::ChromosomePtr& chrom, int fitness_val);
    void set_chromosome(int index, const tp::ChromosomePtr& chrom);
    void set_fitness(int index, int fitness_val);
    void print() const;
private:
    tp::VectorPairChromPtr m_chroms;
};
};
