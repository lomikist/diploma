#pragma once
#include <iostream>
#include <string>

namespace model
{
class Cell
{
public:
    Cell(std::string name, int width, int height, int x, int y);
    void setPosition(int x, int y); 
    std::pair<int,int> getPosition() const;
    std::pair<int,int> getSize() const;
    void print() const;
private:
    std::string m_name;
    int m_width;
    int m_height;
    int m_x;
    int m_y;
};
}
