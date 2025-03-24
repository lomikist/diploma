#include "crossover_uniform.hpp"
#include "cell.hpp"
#include "types.hpp"
#include <algorithm>


tp::ChromosomePtr core::CrossoverUniform::crossover(const tp::ChromosomePtr& first, const tp::ChromosomePtr& second)
{
    int fir_cell_size = first->get_cells().size();
    int sec_cell_size = first->get_cells().size();
    int divider = fir_cell_size / 2;
    int remider = fir_cell_size % 2;

    std::vector<model::Cell> new_cells_vec(std::max(fir_cell_size, sec_cell_size));

    for (int i = 0; i < fir_cell_size; ++i)
    {
        if (i % 2)
            new_cells_vec[i] = first->get_cell(i);
        else
            new_cells_vec[i] = second->get_cell(i);
    }

    tp::ChromosomePtr result = std::make_shared<model::Chromosome>(new_cells_vec, tp::CHROMOSOME_WIDTH, tp::CHROMOSOME_HEIGHT);

    return result;
};

