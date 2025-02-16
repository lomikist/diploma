#include "model.hpp"
#include "types.hpp"

model::Model::Model(const tp::Graph& graph) 
    : m_adj_graph(graph), m_population(graph, tp::POPULATION_SIZE, tp::CHROMOSOME_WIDTH, tp::CHROMOSOME_HEIGHT)
{}
const tp::Graph& model::Model::get_adj_graph()
{
    return m_adj_graph;
};

void model::Model::set_adj_graph(const tp::Graph& rhs)
{
    m_adj_graph = rhs; 
};

const model::Population& model::Model::get_population() const
{
    return m_population;
};

