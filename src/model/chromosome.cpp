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
    for (auto&& el : cells) 
    {
        std::pair<int, int> pos(
            core::Utilities::get_random_number(0, width - 1),
            core::Utilities::get_random_number(0, height - 1)
        );
        while (m_used_pos.find(pos) != m_used_pos.end()) // O(log N) for std::set
        {
            pos.first = core::Utilities::get_random_number(0, width - 1);
            pos.second = core::Utilities::get_random_number(0, height - 1);
        }
        m_used_pos.insert(pos); // Add to set
        m_cells.emplace_back(el, tp::CELL_WIDTH, tp::CELL_HEIGHT, pos.first, pos.second); 
    }
}

model::Chromosome::Chromosome(std::vector<model::Cell> cells, int width, int height)
    : m_cells(cells), m_width(width), m_height(height)
{
    for (auto&& cell : cells) 
        m_used_pos.insert(cell.get_position()); 
}

const std::vector<model::Cell>& model::Chromosome::get_cells() const
{
    return m_cells;
};

const model::Cell& model::Chromosome::get_cell(int index) const
{
    return m_cells[index];
};
const std::set<std::pair<int, int>>& model::Chromosome::get_used_positions() const
{
    return m_used_pos;
};

const model::Cell& model::Chromosome::get_cell_by_pos(const std::pair<int, int>& pos) const
{
    for (auto&& cell : m_cells)
    {
        if (cell.get_position() == pos)
            return cell;
    }
    // TODO it should not return 0
    return m_cells[0];
};

void model::Chromosome::set_cell(int index, Cell cell)
{
    m_used_pos.erase(m_cells[index].get_position());
    m_used_pos.insert(cell.get_position());

    m_cells[index] = std::move(cell);
}

void model::Chromosome::set_cells(std::vector<Cell> cells)
{
    m_used_pos.clear();
    for(auto&& cell : cells)
        m_used_pos.insert(cell.get_position());

    m_cells = std::move(cells);
}

void model::Chromosome::erase_from_used_position(std::pair<int, int> pos_to_remove)
{
    m_used_pos.erase(pos_to_remove);
}

void model::Chromosome::print()
{
    /*std::vector<std::vector<char>> grid(tp::CHROMOSOME_HEIGHT + 1,*/
    /*                                    std::vector<char>(tp::CHROMOSOME_WIDTH + 1, '0'));*/
    
    for (const auto& cell : m_cells) {
        auto [x, y] = cell.get_position();
        /*grid[y][x] = cell.get_name()[0];*/
        std::cout << cell.get_name() << "(" << x << ", " << y << ")"<< std::endl;
    }
 
    /*for (const auto& row : grid) {*/
    /*    for (char cell : row) {*/
    /*        std::cout << cell << ' ';*/
    /*    }*/
    /*    std::cout << '\n';*/
    /*}*/
}

