#include "population.hpp"
#include "chromosome.hpp"
#include "types.hpp"

model::Population::Population(const tp::Graph& graph, int pop_size, int width, int height)
{
    initialize(graph, pop_size, width, height);
};

void model::Population::initialize(const tp::Graph& graph, int pop_size, int width, int height)
{
    std::vector<std::string> graph_members;
    graph_members.reserve(graph.size());
    m_chroms.reserve(pop_size);

    for(auto&& elem : graph) {
        graph_members.push_back(elem.first);
    }
    for (int i = 0; i < pop_size; ++i) {
        m_chroms.emplace_back(std::make_shared<Chromosome>(graph_members, width, height), 0);
    }
};


model::Population::Population(){}

void model::Population::print() const
{
    std::cout << "Population:\n";
    for (size_t i = 0; i < m_chroms.size(); ++i)
    {
        std::cout << "Chromosome " << i + 1 << ":\n";
        m_chroms[i].first->print();
    }
}

const tp::VectorPairChromPtr& model::Population::get_chromosomes() const
{
    return m_chroms;
};

const std::pair<tp::ChromosomePtr, int>& model::Population::get_chromosome(int index) const
{
    return m_chroms.at(index);
};

void model::Population::set_chromosome(int index, const tp::ChromosomePtr& chrom, int fitness_val)
{
    m_chroms[index] = {chrom, fitness_val};
}

void model::Population::set_chromosome(int index, const tp::ChromosomePtr& chrom)
{
    m_chroms[index].first = chrom;
};

void model::Population::set_fitness(int index, int fitness_val)
{
    m_chroms[index].second = fitness_val;
};

void model::Population::set_chromosomes(const tp::VectorPairChromPtr& chroms)
{
    m_chroms = chroms; 
};

