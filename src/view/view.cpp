#include <QPushButton>
#include <QGraphicsScene>
#include <QWheelEvent>
#include <QGraphicsTextItem>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWheelEvent>
#include <QWidget>
#include <cstddef>
#include <string>
#include <tuple>
#include <iostream>
#include <vector>
#include "my_graphic_view.hpp"
#include "qnamespace.h"
#include "rect.hpp"
#include "view.hpp"

MyView::MyView(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    
    MyGraphicsView *customView = new MyGraphicsView(this);
    ui->verticalLayout->replaceWidget(ui->board_view, customView);
    delete ui->board_view;

    ui->board_view = customView;

    scene = new QGraphicsScene(this);
    ui->board_view->resize(1200,700);
    ui->board_view->move(300, 10);
    ui->board_view->setScene(scene);

    drawGrid(1200);

    ui->board_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->board_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    connect(ui->add_rect, &QPushButton::clicked, [this]()
    {
        int x = 0,
            y = 0,
            w = 0,
            h = 0;
        try
        {
            x = std::stod(ui->rect_x->text().toStdString());
            y = std::stod(ui->rect_y->text().toStdString());
            w = std::stod(ui->rect_w->text().toStdString());
            h = std::stod(ui->rect_h->text().toStdString());
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        emit addShapeRequested(std::make_tuple(x, y, w, h));

        QGraphicsRectItem *rectItem = new QGraphicsRectItem(x, y, w, h);
        rectItem->setBrush(QBrush(Qt::darkCyan));
        rectItem->setPen(QPen(Qt::black));
        scene->addItem(rectItem);
    });
}

void MyView::drawGrid(qreal gridSize) {
    QPen pen(Qt::lightGray, 1);
    for (size_t i = 0; i <= 1180; i += 20)
        scene->addLine(i, 0, i, 680, pen);
    for (size_t i = 0; i <= 680; i += 20)
       scene->addLine(0, i, 1180, i, pen);
}

MyView::~MyView() {
    delete scene;
    delete ui;
}

void MyView::display_shapes(const std::vector<Rect>& shapes, size_t index)
{
    
}












