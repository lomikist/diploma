#include "my_graphic_view.hpp"
#include <QDebug>

MyGraphicsView::MyGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
}

void MyGraphicsView::wheelEvent(QWheelEvent *event)
{
    QPointF viewPos = event->position();

    QPointF scenePos = mapToScene(viewPos.toPoint());
    if (event->angleDelta().y() > 0) {
        zoomOut(scenePos);
    } else {
        zoomIn(scenePos);
    }
    event->accept();
}

void MyGraphicsView::zoomIn(QPointF scenePos) {

    QTransform transform = this->transform();

    qreal scaleX = transform.m11();
    qreal scaleY = transform.m22();

    qInfo()<< scaleX << "-" << scaleY;
    if (scaleX > 0.4 || scaleY > 0.4)
    {
        scale(0.9, 0.9);
        centerOn(scenePos);
    }
}

void MyGraphicsView::zoomOut(QPointF scenePos) {
    QTransform transform = this->transform();

    qreal scaleX = transform.m11();
    qreal scaleY = transform.m22();
    qInfo()<< scaleX << "-" << scaleY;
    if (scaleX < 2 || scaleY < 2)
    {
        scale(1.0 / 0.9, 1.0 / 0.9);
        centerOn(scenePos);
    }
}

























