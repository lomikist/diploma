#ifndef RECT_HPP
#define RECT_HPP
#include "qgraphicsitem.h"
#include <QDebug>
#include <QGraphicsRectItem>
#include <QPainter>

class Rect : public QGraphicsRectItem
{
public:
    Rect(qreal x, qreal y, qreal h, qreal w);
    Rect(const Rect& other);
    Rect(Rect&& other);
    Rect& operator=(const Rect& other);
    Rect& operator=(Rect&& other);
    ~Rect() override;
      
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
};

#endif
