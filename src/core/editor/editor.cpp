#include "editor.hpp"
#include "crossover_two_point.hpp"
#include "fitness_manhattan.hpp"
#include "model.hpp"
#include "select_to_half.hpp"
#include <algorithm>
#include <memory>
#include <strstream>

core::Editor::Editor(std::shared_ptr<model::Model> model) :
    m_fitness(std::make_shared<core::FitnessManhattan>()),
    m_crossover(std::make_shared<core::CrossoverTwoPoint>()),
    m_select(std::make_shared<core::SelectToHalf>()),
    m_model(model) 
{};

void core::Editor::evaluate(const tp::Graph& graph, const model::Population& pop)
{
    for (auto&& chrom : pop.get_chromosomes())
    {
        m_fitness_vals.emplace_back(chrom, m_fitness->calc_fitness(graph, chrom) / 2);//TODO
    }
    
    for (int i = 0; i < 8; i++){
        m_fitness_vals = m_select->evaluate(m_fitness, m_crossover, graph, m_fitness_vals);
        //LOG
        std::cout << std::endl;
        std::cout << std::endl; 
        for(auto&& elem : m_fitness_vals)
            std::cout << elem.second << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        //LOGEND
    }
}

