#pragma once
#include "population.hpp"
#include "types.hpp"

namespace model
{
class Model
{
public:
    Model(const tp::Graph&);

    const model::Population&    get_population() const;
    const tp::Graph&            get_adj_graph() const;
    void set_population(const model::Population& pop);
    void set_adj_graph(const tp::Graph&);
private:
    tp::Graph m_adj_graph;
    model::Population m_population;
};
}
