#pragma once
#include "chromosome.hpp"
#include "types.hpp"

namespace model
{

class Population
{
public:
    Population(const tp::Graph& graph, int pop_size, int width, int height);
    void print() const;
private:
    std::vector<model::Chromosome>      m_chroms;
};
};
