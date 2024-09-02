#include <QPushButton>
#include <QGraphicsScene>
#include <QWheelEvent>
#include <QGraphicsTextItem>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWheelEvent>
#include <QWidget>
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>
#include <string>
#include <tuple>
#include <iostream>
#include <vector>
#include "my_graphic_view.hpp"
#include "qlogging.h"
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

    _scene = new QGraphicsScene(this);
    ui->board_view->resize(1200,700);
    ui->board_view->move(300, 10);
    ui->board_view->setScene(_scene);

    drawGrid(1200);
    set_connect();
}

MyView::MyView(MyView&& other) noexcept: 
    QMainWindow(nullptr),     
    ui(other.ui),
    _scene(other._scene)
{    
    other.ui = nullptr;    
    other._scene = nullptr;
}

void MyView::set_connect()
{
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
        qInfo() << "set_connect afther clicked";     
        emit addShapeRequested(std::make_tuple(x, y, w, h));
    });
}

void MyView::drawGrid(qreal gridSize){
    ui->board_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->board_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QPen pen(Qt::lightGray, 1);
    for (size_t i = 0; i <= 1180; i += 20)
        _scene->addLine(i, 0, i, 680, pen);
    for (size_t i = 0; i <= 680; i += 20)
       _scene->addLine(0, i, 1180, i, pen);
}

MyView::~MyView()
{
    
    qInfo("view destructur");
}

void MyView::display_shapes(std::vector<std::shared_ptr<Rect>>& shapes, size_t index)
{
    auto items = _scene->items();

    for (const auto& shape : shapes)  // Iterating over shared_ptr<Rect>
    {
        auto it = std::find_if(items.begin(), items.end(), 
        [&](QGraphicsItem* item) {
            return dynamic_cast<Rect*>(item) == shape.get();  // Compare with the raw pointer from shared_ptr
        });
    
        if (it == items.end())
        {
            _scene->addItem(shape.get());  // Add the raw pointer to the scene
        }
    }
}







