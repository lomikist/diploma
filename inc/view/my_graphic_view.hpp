#ifndef MY_GRAPHIC_VIEW_H
#define MY_GRAPHIC_VIEW_H

#include <QGraphicsView>
#include <QWheelEvent>

class MyGraphicsView : public QGraphicsView {
    Q_OBJECT

public:
    explicit MyGraphicsView(QWidget *parent = nullptr);
protected:
    void zoomIn(QPointF scenePos);
    void zoomOut(QPointF scenePos);
    void wheelEvent(QWheelEvent *event) override;
};

#endif // MY_GRAPHIC_VIEW_H
