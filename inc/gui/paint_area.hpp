#pragma once
#include <memory>
#include <qimage.h>
#include <qwidget.h>
#include "qimage.h"
#include "qpainter.h"
#include "qpoint.h"
#include "qwidget.h"

namespace gui
{
class PaintArea : public QWidget
{
    Q_OBJECT
public:
    PaintArea(QWidget* parent = nullptr);
    std::shared_ptr<QPainter> get_painter();
    void clear();
protected:
    QImage                      m_image;
    std::shared_ptr<QPainter>   m_painter;
    QPoint                      m_image_position;
    double                      m_image_scale = 1.0;

    void paintEvent(QPaintEvent* event) override;

};
}
