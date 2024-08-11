#include "shapeFacory.hpp"

Shape *ShapeFactory::createShape(const QString& shape_type)
{
    if (shape_type == "rect")
        return new Rshape();
    else if(shape_type == "tshape")
        return nullptr;
    else if(shape_type == "lshape")
        return nullptr;
    else if(shape_type == "ushape")
        return nullptr;
    else 
        return nullptr;
}