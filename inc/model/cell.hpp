#pragma once
#include <iostream>
#include <string>

namespace model
{
class Cell
{
public:
    Cell(const std::string& name, int width, int height, int x, int y);
    Cell() = default;

    std::pair<int, int> get_position() const;
    std::pair<int, int> get_size() const;
    const std::string&  get_name() const;

    void set_position(int x, int y); 
    void set_position(std::pair<int, int>); 
    bool operator==(const Cell& rhs) const;
    bool operator!=(const Cell& rhs) const;

////////////////////////
    void print() const;
private:
    std::string m_name;
    int m_width;
    int m_height;
    int m_x;
    int m_y;
};
}
