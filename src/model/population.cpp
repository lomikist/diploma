#include "population.hpp"
#include "fitness_manhattan.hpp"
#include "types.hpp"
#include <memory>

model::Population::Population(const tp::Graph& graph, int pop_size, int width, int height)
{
    std::vector<std::string> graph_members;
    graph_members.reserve(graph.size());
    m_chroms.reserve(pop_size);

    for(auto&& elem : graph)
    {
        graph_members.push_back(elem.first);
    }
    for (int i = 0; i < pop_size; ++i) {
        m_chroms.emplace_back(graph_members, width, height);
    }
};

void model::Population::print() const {
    std::cout << "Population:\n";
    for (size_t i = 0; i < m_chroms.size(); ++i) {
        std::cout << "Chromosome " << i + 1 << ":\n";
        m_chroms[i].print();
    }
}

