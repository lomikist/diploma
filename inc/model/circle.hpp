#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "qgraphicsitem.h"
#include <QDebug>
#include <QGraphicsRectItem>
#include <QPainter>

class Circle : public QGraphicsEllipseItem
{
public:
    Circle(qreal x, qreal y, qreal r);
    Circle(const Circle& other);
    Circle(Circle&& other);
    Circle& operator=(const Circle& other);
    Circle& operator=(Circle&& other);
    ~Circle();
      
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override; 
};

#endif
