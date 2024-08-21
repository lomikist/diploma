#include "model.hpp"

Model::Model()
{
}

Model::~Model()
{
}

void Model::add_rect(int x, int y, int h, int w)
{
    _shapes.push_back(Rect(x, y, h, w));
}