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
    const std::vector<Cell>& get_cells() const;
    void print() const;
private:
    std::vector<Cell> m_cells;
    int m_width;
    int m_height;
};
}
