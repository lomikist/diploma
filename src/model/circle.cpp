#include "circle.hpp"
#include "qgraphicsitem.h"
#include "qlogging.h"
#include "qnamespace.h"
#include <utility>

Circle::Circle(qreal x, qreal y, qreal r)
        : QGraphicsEllipseItem(x, y, r, r, nullptr)
{}

Circle::Circle(const Circle& other)
: QGraphicsEllipseItem(other.rect(), nullptr)
{}

Circle::Circle(Circle&& other)
: QGraphicsEllipseItem(std::move(other.rect()), nullptr)
{}

Circle::~Circle()
{
}

Circle& Circle::operator=(const Circle& other)
{
    if (this != &other) {
        this->setRect(other.rect());
    }
    return *this;
}

Circle& Circle::operator=(Circle&& other)
{
    if (this != &other) {
        this->setRect(std::move(other.rect()));
    }
    return *this;
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setBrush(QBrush(Qt::blue));
    painter->drawEllipse(rect());
}

QRectF Circle::boundingRect() const 
{
    return rect();
}

QPainterPath Circle::shape() const
{
    QPainterPath path;
    path.addEllipse(rect());
    return path;
}

