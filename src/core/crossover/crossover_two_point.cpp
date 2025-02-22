#include "crossover_two_point.hpp"
#include "cell.hpp"
#include "types.hpp"
#include <algorithm>


tp::ChromosomePtr core::CrossoverTwoPoint::crossover(const tp::ChromosomePtr& first, const tp::ChromosomePtr& second)
{
    int divider = first->get_cells().size() / 3;
    int remider = first->get_cells().size() % 3;

    std::vector<model::Cell> new_cells_vec(std::max(first->get_cells().size(), second->get_cells().size()));

    std::copy(first->get_cells().begin(), first->get_cells().begin() + divider, new_cells_vec.begin());
    std::copy(second->get_cells().begin() + divider, second->get_cells().begin() + (divider * 2), new_cells_vec.begin() + divider);
    std::copy(first->get_cells().begin() + (divider * 2), first->get_cells().begin() + (divider * 3) + remider, new_cells_vec.begin() + (divider * 2));

    tp::ChromosomePtr result = std::make_shared<model::Chromosome>(new_cells_vec, tp::CHROMOSOME_WIDTH, tp::CHROMOSOME_HEIGHT);

    return result;
};

