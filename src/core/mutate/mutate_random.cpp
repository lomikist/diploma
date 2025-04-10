#include "mutate_random.hpp"
#include "utilities.hpp"

tp::VectorPairChromPtr core::MutateRandom::mutate(tp::VectorPairChromPtr vals)
{
    for (const auto& [chromptr, fitness] : vals) 
    {
        const auto& used_positions = chromptr->get_used_positions();

        for (int i = 0; i < 1; ++i)
        {
            int index = core::Utilities::get_random_number(0, chromptr->get_cells().size() / 2);
            std::pair<int, int> pos;
            model::Cell temp_cell = chromptr->get_cell(index); 

            do {
                pos.first = core::Utilities::get_random_number(0, tp::CHROMOSOME_WIDTH - 1); 
                pos.second = core::Utilities::get_random_number(0, tp::CHROMOSOME_HEIGHT - 1);
            } while (used_positions.find(pos) != used_positions.end());
            
            temp_cell.set_position(pos);
            chromptr->set_cell(index, temp_cell);
        }
    }
    return vals;
}
