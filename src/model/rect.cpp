#include "rect.hpp"
#include "qgraphicsitem.h"
#include "qnamespace.h"
#include <utility>

Rect::Rect(qreal x, qreal y, qreal w, qreal h)
        : QGraphicsRectItem(x, y, w, h)
{}

Rect::Rect(const Rect& other)
: QGraphicsRectItem(other.rect())
{}

Rect::Rect(Rect&& other)
: QGraphicsRectItem(std::move(other.rect()))
{}

Rect& Rect::operator=(const Rect& other)
{
    if (this != &other) {
        this->setRect(other.rect());
    }
    return *this;
}

Rect& Rect::operator=(Rect&& other)
{
    if (this != &other) {
        this->setRect(std::move(other.rect()));
    }
    return *this;
}

void Rect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setBrush(QBrush(Qt::blue));
    painter->drawRect(rect());
}

QRectF Rect::boundingRect() const 
{
    return rect();
}

QPainterPath Rect::shape() const
{
    QPainterPath path;
    path.addRect(rect());
    return path;
}

