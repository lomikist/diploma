#include "chromosome.hpp"
#include "types.hpp"
#include <algorithm>
#include <random>
#include <string>
#include <utility>

int getRandomNumber(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

model::Chromosome::Chromosome(std::vector<std::string> cells, int width, int height)
    : m_width(width), m_height(height)
{
    std::vector<std::pair<int, int>> used_indexes;
    used_indexes.reserve(cells.size());

    for(auto&& el : cells) 
    {
        std::pair<int, int> pos(getRandomNumber(0, width), getRandomNumber(0, height));
        while (std::find(used_indexes.begin(), used_indexes.end(), pos) != used_indexes.end())
        {
            pos.first = getRandomNumber(0, width);
            pos.second = getRandomNumber(0, height);
        }
        used_indexes.emplace_back(pos); 
        m_cells.emplace_back(el, tp::CELL_WIDTH, tp::CELL_HEIGHT, pos.first, pos.second); 
    }
}

model::Chromosome::Chromosome(std::vector<model::Cell> cells, int width, int height)
    : m_cells(cells), m_width(width), m_height(height)
{}

const std::vector<model::Cell>& model::Chromosome::get_cells() const
{
    return m_cells;
};

void model::Chromosome::print() const
{
    std::cout << "Chromosome:\n";
    for (const auto& cell : m_cells) {
        cell.print();
    }
    std::cout << "----------------------\n";
}
