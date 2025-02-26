#include "editor.hpp"
#include "crossover_two_point.hpp"
#include "fitness_manhattan.hpp"
#include "model.hpp"
#include "mutate_random.hpp"
#include "select_to_half.hpp"
#include "types.hpp"
#include <memory>
#include <ostream>

core::Editor::Editor(std::shared_ptr<model::Model> model) :
    m_model(model),
    m_fitness(std::make_shared<core::FitnessManhattan>()),
    m_crossover(std::make_shared<core::CrossoverTwoPoint>()),
    m_select(std::make_shared<core::SelectToHalf>()),
    m_mutate(std::make_shared<core::MutateRandom>())
{};

void core::Editor::evaluate(const tp::Graph& graph, const model::Population& pop)
{
    model::Population population = pop; 
    for (auto&& chrom : population.get_chromosomes())
        m_fitness_vals.emplace_back(chrom, m_fitness->calc_fitness(graph, chrom) / 2);

    for (int i = 0; i < tp::GENERATION_SIZE; ++i){
        m_fitness_vals = m_select->evaluate(m_fitness, m_crossover, graph, m_fitness_vals);
        m_mutate->mutate(m_fitness_vals);
        int index = 0;
        /*for (auto&& [chrom, fit_val] : m_fitness_vals) {*/
        population.set_chromosome(0, m_fitness_vals[index].first);
            /*population.get_chromosome(index)->print();*/
            std::cout << m_fitness_vals[0].second << std::endl; 
        /*} */
    }
    m_model->set_population(pop);
}

