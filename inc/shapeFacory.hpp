#ifndef SHAPE_FACTORY_HPP
#define SHAPE_FACTORY_HPP
#include "absShape.hpp"
#include "Rshape.hpp"
// Abstract ShapeFactory class
struct ShapeFactory {
    ~ShapeFactory() = default;
    static Shape *createShape(const QString &);
};

#endif /* SHAPE_FACTORY_HPP */
