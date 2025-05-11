#include "model.hpp"
#include "types.hpp"

model::Model::Model(const tp::Graph& graph) :
    m_adj_graph(graph),
    m_population(graph, tp::POPULATION_SIZE, tp::CHROMOSOME_WIDTH, tp::CHROMOSOME_HEIGHT)
{};

model::Model::Model()
{};

const tp::Graph& model::Model::get_adj_graph() const
{
    return m_adj_graph;
};

void model::Model::set_adj_graph(const tp::Graph& rhs)
{
    m_adj_graph = rhs; 
};

void model::Model::set_population(const model::Population& pop)
{
    m_population = pop;
};

const model::Population& model::Model::get_population() const
{
    return m_population;
};

model::Population& model::Model::get_population()
{
    return m_population;
};

int model::Model::get_weight(const std::string& key, const std::string& to_search)
{
    auto it = m_adj_graph.find(key);
    if (it == m_adj_graph.end()){
        return -1;
    }

    for (const auto& neighbor : it->second)
    {
        if (neighbor.first == to_search)
            return neighbor.second;
    }
    return -1;
}
