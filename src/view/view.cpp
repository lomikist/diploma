#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <tuple>
#include <iostream>
#include "view.hpp"

MyView::MyView(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->board_view->setScene(scene);

    connect(ui->add_rect, &QPushButton::clicked, [this]() {
        emit addShapeRequested(std::make_tuple(
                                    std::stod(ui->rect_x->text().toStdString()),
                                    std::stod(ui->rect_y->text().toStdString()),
                                    std::stod(ui->rect_h->text().toStdString()),
                                    std::stod(ui->rect_w->text().toStdString())
                                    ));
    });
}

MyView::~MyView() {
    delete scene;
    delete ui;
}

void MyView::display_shapes(const std::vector<Rect>& shapes)
{
    for (auto &&i : shapes)
    {

        QGraphicsRectItem *rectItem = new QGraphicsRectItem(i.getRect());

        rectItem->setBrush(QBrush(Qt::blue));
        rectItem->setPen(QPen(Qt::black));

        scene->addItem(rectItem);
    }
    
}
