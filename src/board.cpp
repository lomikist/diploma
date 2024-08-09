#include "../inc/board.hpp"
#include <iostream>
#include<QDebug>

Board::Board(QGraphicsView *view, QGraphicsScene *scene, QObject *parent)
    : QObject(parent), _scene(scene), _view(view)
{
    _view->setScene(_scene);
}

Board::~Board() {}

void Board::set_width(int width)
{
    _curr_width = width;
}

void Board::set_height(int height)
{
    _curr_height = height;
}

void Board::drawCoordinateAxes(int length = 1000, int thickness = 2)
{
    QPen pen(Qt::black);
    pen.setWidth(thickness);
    _scene->addLine(1, 1, length, 1, pen);
    _scene->addLine(1, 1, 1, length, pen);
    _scene->addLine(length, 1, length, length, pen);
    _scene->addLine(1, length, length, length, pen);

    // _scene->addLine(1, 1, 0, length - 1, pen);
    // _scene->addLine(1, 1, 0, length - 1, pen);

}


void Board::set_opbects()
{
    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(1);

    drawCoordinateAxes(500, 2);
    // _scene->addRect(_x, _y, 10, 10, outlinePen, blueBrush);
}

void Board::add_rect()
{
    QBrush blueBrush(Qt::blue);
    QPen outlinePen(Qt::black);
    _x += _curr_width;
    _y += _curr_height;

    for (auto&& i = _scene->items().begin(); i != _scene->items().end(); ++i)
        qInfo() << i;

    // for (auto &&i : _scene->items())
    // {
    //     qInfo() << *i;
    // }
    

    _scene->addRect(_x, _y, _curr_width, _curr_height, outlinePen, blueBrush);
}
