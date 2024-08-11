#ifndef RSHAPE_HPP
#define RSHAPE_HPP
#include "absShape.hpp"

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


#endif /* RSHAPE_HPP */
