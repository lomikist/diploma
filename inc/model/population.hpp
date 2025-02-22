#pragma once
#include "chromosome.hpp"
#include "types.hpp"
#include <memory>

namespace model
{
class Population
{
public:
    Population(const tp::Graph& graph, int pop_size, int width, int height);
    void init_pop();
    const std::vector<std::shared_ptr<model::Chromosome>>& get_chromosomes() const;
    void print() const;
private:
    std::vector<std::shared_ptr<model::Chromosome>> m_chroms;
};
};
