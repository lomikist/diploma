#include "mutate_random.hpp"
#include "utilities.hpp"
#include <algorithm>


void core::MutateRandom::mutate(const tp::VectorPairChromPtr& vals)
{
    for (const auto& [chromptr, fitness] : vals) 
    {
        auto& used_positions = chromptr->get_positions();

        for (int i = 0; i < 4; ++i)
        {
            int index = core::Utilities::get_random_number(0, chromptr->get_cells().size() / 2);
            std::pair<int, int> pos;
            model::Cell temp_cell = chromptr->get_cell(index); 

            do {
                pos.first = core::Utilities::get_random_number(0, tp::CHROMOSOME_WIDTH - 1); 
                pos.second = core::Utilities::get_random_number(0, tp::CHROMOSOME_HEIGHT - 1);
            } while (std::any_of(used_positions.begin(), used_positions.end(), [&](auto&& position){
                return pos == position; 
            }));
            temp_cell.set_position(pos);
            chromptr->set_cell(index, temp_cell);
        }
    }
}
