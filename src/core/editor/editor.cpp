#include "editor.hpp"
#include "cell.hpp"
#include "crossover_two_point.hpp"
#include "fitness_manhattan.hpp"
#include "model.hpp"
#include "mutate_random.hpp"
#include "select_to_half.hpp"
#include "types.hpp"
#include <memory>

core::Editor::Editor(std::shared_ptr<model::Model> model) :
    m_model(model),
    m_fitness(std::make_shared<core::FitnessManhattan>()),
    m_crossover(std::make_shared<core::CrossoverTwoPoint>()),
    m_select(std::make_shared<core::SelectToHalf>()),
    m_mutate(std::make_shared<core::MutateRandom>())
{};

void core::Editor::evaluate(const tp::Graph& graph, const model::Population& pop)
{
    for (auto&& chrom : pop.get_chromosomes())
        m_fitness_vals.emplace_back(chrom, m_fitness->calc_fitness(graph, chrom) / 2);//TODO
    
    for (int i = 0; i < tp::GENERATION_SIZE; ++i){
        m_fitness_vals = m_select->evaluate(m_fitness, m_crossover, graph, m_fitness_vals);
        m_mutate->mutate(m_fitness_vals);

        /*//LOG*/
        int start_val = m_fitness_vals[0].second;
        /*std::cout << std::endl;*/
        /*std::cout << std::endl; */
        /*for(auto&& elem : m_fitness_vals)*/
        /*    std::cout << elem.second << std::endl;*/
        /*std::cout << std::endl;*/
        /*std::cout << std::endl;*/
        /*//LOGEND*/
        std::cout << start_val << std::endl;
    }
}

