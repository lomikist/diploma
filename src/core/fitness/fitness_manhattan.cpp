#include "fitness_manhattan.hpp"
#include "types.hpp"
#include <cstddef>

int core::FitnessManhattan::calc_fitness(const tp::Graph& graph, const tp::ChromosomePtr& matrix)
{
    int result = 0;
    std::unordered_map<std::string, const model::Cell*> cell_map;
    for (const auto& cell : matrix->get_cells()) {
        cell_map[cell.get_name()] = &cell;
    }

    for (const auto& [node_name, neighbors] : graph)
    {
        auto first = cell_map.find(node_name);
        if (first == cell_map.end()) {
            continue;
        }
        for (const auto& [neighbor_name, weight] : neighbors)
        {
            auto second = cell_map.find(neighbor_name);
            if (second == cell_map.end()) {
                continue;
            }
            result += distance(*first->second, *second->second) * weight;
        }
    }
    return result;
};

std::size_t core::FitnessManhattan::distance(const model::Cell& one, const model::Cell& two)
{
    std::size_t width = std::abs(one.get_position().first - two.get_position().first); 
    std::size_t height = std::abs(one.get_position().second - two.get_position().second); 
    return (width + height);
};

