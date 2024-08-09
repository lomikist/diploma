#ifndef SHAPE_FACTORY_HPP
#define SHAPE_FACTORY_HPP

#include <QAbstractGraphicsShapeItem>
#include <QPainter>

// Define Shape class inheriting from QAbstractGraphicsShapeItem
struct Shape : public QAbstractGraphicsShapeItem
{
    virtual ~Shape() = default;
};

class Rshape : public Shape
{
public:
    QRectF boundingRect() const override {
        return QRectF(0, 0, 10, 10);  // Replace with actual dimensions
    };
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override {
        // painter->setBrush(brush());
        // painter->setPen(pen());
        // painter->drawRect(boundingRect());  // Replace with your custom shape
    };

    // Constructor and Destructor
    Rshape() = default;
    ~Rshape() override = default;
};

// Abstract ShapeFactory class
struct ShapeFactory {
    virtual Shape* createShape() = 0;
    virtual ~ShapeFactory() = default;
};

// Concrete RshapeFactory class inheriting from ShapeFactory
struct RshapeFactory : ShapeFactory {
    Shape* createShape() override { return new Rshape(); }
};

#endif /* SHAPE_FACTORY_HPP */
