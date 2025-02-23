#pragma once 
#include "cell.hpp"
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
    const std::vector<std::pair<int, int>>& get_positions() const;

    void set_cells(std::vector<Cell> cells);
    void set_cell(int index, Cell cell);
    void print() const;
private:

    std::vector<Cell>                m_cells;
    std::vector<std::pair<int, int>> m_used_pos;
    int m_width;
    int m_height;
};
}
