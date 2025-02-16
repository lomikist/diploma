#include "cell.hpp"

model::Cell::Cell(std::string name, int width, int height, int x, int y)
        : m_name(name), m_width(width), m_height(height), m_x(x), m_y(y) {}

void model::Cell::setPosition(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
}

std::pair<int,int> model::Cell::getPosition() const
{
    return {m_x, m_y}; 
}

std::pair<int,int> model::Cell::getSize() const
{
    return {m_width, m_height}; 
}

void model::Cell::print() const
{
    std::cout << "Cell: " << m_name << " at (" << m_x << ", " << m_y << ") sizes - (" << m_width << ", " << m_height << ")\n";
}

