#include "cell.hpp"

model::Cell::Cell(const std::string& name, int width, int height, int x, int y)
        : m_name(name), m_width(width), m_height(height), m_x(x), m_y(y) {}

void model::Cell::set_position(std::pair<int, int> pos)
{
    this->m_x = pos.first;
    this->m_y = pos.second;
}

void model::Cell::set_position(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
}

std::pair<int, int> model::Cell::get_position() const
{
    return {m_x, m_y}; 
}

std::pair<int, int> model::Cell::get_size() const
{
    return {m_width, m_height}; 
}

const std::string& model::Cell::get_name() const {
    return m_name;
};

void model::Cell::print() const
{
    std::cout << "Cell: " << m_name << " at (" << m_x << ", " << m_y << ") sizes - (" << m_width << ", " << m_height << ")\n";
}

bool model::Cell::operator==(const Cell& rhs) const
{
    return (m_name == rhs.m_name && m_width == rhs.m_width && m_height == rhs.m_height);
}
bool model::Cell::operator!=(const Cell& rhs) const
{
    return !(*this == rhs);
};

