#include "chromosome.hpp"
#include "types.hpp"
#include "utilities.hpp"
#include <algorithm>
#include <random>
#include <string>
#include <utility>

model::Chromosome::Chromosome(std::vector<std::string> cells, int width, int height)
    : m_width(width), m_height(height)
{
    m_used_pos.reserve(cells.size());

    for(auto&& el : cells) 
    {
        std::pair<int, int> pos(
            core::Utilities::get_random_number(0, width),
            core::Utilities::get_random_number(0, height)
        );
        while (std::find(m_used_pos.begin(), m_used_pos.end(), pos) != m_used_pos.end())
        {
            pos.first = core::Utilities::get_random_number(0, width);
            pos.second = core::Utilities::get_random_number(0, height);
        }
        m_used_pos.emplace_back(pos); 
        m_cells.emplace_back(el, tp::CELL_WIDTH, tp::CELL_HEIGHT, pos.first, pos.second); 
    }
}

model::Chromosome::Chromosome(std::vector<model::Cell> cells, int width, int height)
    : m_cells(cells), m_width(width), m_height(height)
{
    m_used_pos.reserve(cells.size());
    for (auto&& cell : cells) 
        m_used_pos.push_back(cell.get_position()); 
}

const std::vector<model::Cell>& model::Chromosome::get_cells() const
{
    return m_cells;
};

const model::Cell& model::Chromosome::get_cell(int index) const
{
    return m_cells[index];
};

const std::vector<std::pair<int, int>>& model::Chromosome::get_positions() const
{
    return m_used_pos;
};

void model::Chromosome::set_cell(int index, Cell cell)
{
    m_used_pos.erase(std::find(m_used_pos.begin(), m_used_pos.end(), m_cells[index].get_position()));
    m_used_pos.push_back(std::move(cell.get_position()));
//
    m_cells[index] = std::move(cell);
}

void model::Chromosome::set_cells(std::vector<Cell> cells)
{
    m_cells = std::move(cells);
}

void model::Chromosome::print() const
{
    std::cout << "Chromosome:\n";
    for (const auto& cell : m_cells) {
        cell.print();
    }
    std::cout << "----------------------\n";
}
