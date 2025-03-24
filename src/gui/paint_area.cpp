#include "paint_area.hpp"
#include "gui_controller.hpp"
#include <qobject.h>
#include <qimage.h>
#include <qpixmap.h>
 
gui::PaintArea::PaintArea(QWidget* parent) :
                    QWidget(parent),
                    m_image(QSize(gui::PAREA_WIDTH, gui::PAREA_HEIGHT), QImage::Format_RGB32)
{
    setAttribute(Qt::WA_StaticContents);
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    m_image.fill(Qt::white);

    m_painter = std::make_shared<QPainter>(&m_image);
}

void gui::PaintArea::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.fillRect(rect(), Qt::lightGray);

    m_image_position.setX((width() - m_image.width() * m_image_scale) / 2);
    m_image_position.setY((height() - m_image.height() * m_image_scale) / 2);

    QTransform transform;
    transform.translate(m_image_position.x(), m_image_position.y());
    painter.setTransform(transform);

    painter.drawImage(0, 0, m_image);
    painter.end();
}

std::shared_ptr<QPainter> gui::PaintArea::get_painter()
{
    return m_painter;
}

void gui::PaintArea::clear()
{
    m_image.fill(Qt::white);
};

