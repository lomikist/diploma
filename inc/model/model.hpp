#ifndef MODEL_HPP
#define MODEL_HPP
#include <iostream>
#include <vector>
#include "rect.hpp"

class Model
{
private:
    std::vector<Rect> _shapes;    
public:
    Model();
    ~Model();
    void add_rect(int x, int y, int h, int w);
    const std::vector<Rect>& get_shapes() const {
        return _shapes;
    }
};

#endif // MODEL_HPP

