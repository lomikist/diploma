#ifndef ABSSHAPE_HPP
#define ABSSHAPE_HPP

#include <QAbstractGraphicsShapeItem>
#include <QPainter>

// Define Shape class inheriting from QAbstractGraphicsShapeItem
struct Shape : public QAbstractGraphicsShapeItem
{
    virtual ~Shape() = default;
};

#endif /* ABSSHAPE_HPP */
