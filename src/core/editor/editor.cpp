#include "editor.hpp"
#include "crossover_two_point.hpp"
#include "fitness_manhattan.hpp"
#include <iterator>
#include <strstream>

core::Editor::Editor()
:   m_fitness(std::make_unique<FitnessManhattan>()),
    m_crossover(std::make_unique<CrossoverTwoPoint>())
{};

void core::Editor::evaluate(const tp::Graph& graph, const model::Population& pop)
{
    for(auto&& chrom : pop.get_chromosomes())
        m_fitness_vals.push_back(m_fitness->calc_fitness(graph, chrom ) / 2);  
    std::copy(m_fitness_vals.begin(), m_fitness_vals.end(), std::ostream_iterator<int>(std::cout, "\n"));
}
