#include "select_to_half.hpp"
#include <algorithm>

tp::VectorPairChromPtr core::SelectToHalf::cross_select(
    std::shared_ptr<Ifitness> fitness, 
    std::shared_ptr<Icrossover> crossover,  
    const tp::Graph& graph, 
    tp::VectorPairChromPtr fitness_vals)
{
    for(auto& [chrom, val] : fitness_vals)
        val = fitness->calc_fitness(graph, chrom) / 2;
//TODO check this function , position related.
    std::sort(fitness_vals.begin(), fitness_vals.end(), [&](auto&& one,auto&& two){ return one.second < two.second; });
    for (
        int i = 0,
        j = fitness_vals.size() / 2,
        k = fitness_vals.size();
        i < fitness_vals.size() / 2;
        i+=2, ++j, --k
    ){
        auto&& first_temp = crossover->crossover(fitness_vals[i].first, fitness_vals[i + 1].first);
        auto&& second_temp = crossover->crossover(fitness_vals[i + 1].first, fitness_vals[i].first);
        // from half to 3/4
        fitness_vals[j] = { first_temp,
                            fitness->calc_fitness(graph, first_temp) / 2 };
        // from end to 3/4
        fitness_vals[k - 1] = { second_temp,
                            fitness->calc_fitness(graph, second_temp) / 2 };
    }
    std::sort(fitness_vals.begin(), fitness_vals.end(), [&](auto&& one,auto&& two){ return one.second < two.second; });

    return fitness_vals;
}
