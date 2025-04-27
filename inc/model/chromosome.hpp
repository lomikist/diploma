#pragma once 
#include "cell.hpp"
#include <set>
#include <vector>

namespace model 
{
class Chromosome
{
public:
    Chromosome(std::vector<std::string> cells, int width, int height);
    Chromosome(std::vector<Cell> cells, int width, int height);
    Chromosome() = default;
    
    const std::vector<Cell>&                get_cells() const;
    const model::Cell&                      get_cell(int) const;
    const model::Cell&                      get_cell_by_pos(const std::pair<int, int>& pos) const;
    const std::set<std::pair<int, int>>&    get_used_positions() const;

    void erase_from_used_position(std::pair<int, int> pos_to_remove);
    void set_cells(std::vector<Cell> cells);
    void set_cell(int index, Cell cell);
    void print();
private:

    std::vector<Cell>               m_cells;
    std::set<std::pair<int, int>>   m_used_pos;
    int m_width;
    int m_height;
};
}
