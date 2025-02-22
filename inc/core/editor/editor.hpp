#pragma once
#include "icrossover.hpp"
#include "ifitness.hpp"
#include "model.hpp"
#include "population.hpp"
#include "select/iselect.hpp"
#include "types.hpp"
#include <unordered_map>

namespace core 
{
class Editor 
{
public:
    Editor(std::shared_ptr<model::Model> model);
    void evaluate(const tp::Graph& graph, const model::Population& pop);
private:
    tp::VectorPairChromPtr              m_fitness_vals; 
    std::shared_ptr<model::Model>       m_model;
    std::shared_ptr<core::Ifitness>     m_fitness;
    std::shared_ptr<core::Icrossover>   m_crossover;
    std::shared_ptr<core::Iselect>      m_select;
};
}
