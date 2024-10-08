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
#include <memory>
#include <string>
#include <tuple>
#include <iostream>
#include <vector>
#include "my_graphic_view.hpp"
#include "qlogging.h"
#include "qnamespace.h"
#include "view.hpp"

MyView::MyView(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    MyGraphicsView *customView = new MyGraphicsView(this);
    ui->_rect_layout->replaceWidget(ui->_board_view, customView);
    delete ui->_board_view;
    ui->_board_view = customView;
   
    _scene = new QGraphicsScene(this);
    ui->_board_view->resize(1200,700);
    ui->_board_view->move(300, 10);
    ui->_board_view->setScene(_scene);

    drawGrid(1200);
    set_connect();
}

MyView::MyView(MyView&& other) noexcept: 
    QMainWindow(qobject_cast<QWidget*>(other.parent()) ? qobject_cast<QWidget*>(other.parent()) : nullptr),     
    ui(std::move(other.ui)),
    _scene(std::move(other._scene))
{
    other.ui = nullptr;    
    other._scene = nullptr;
}

void MyView::set_connect()
{
    connect(ui->_add_rect, &QPushButton::clicked, [this]()
    {
        int x = 0,
        y = 0,
        w = 0,
        h = 0;
        try
        {
            x = std::stod(ui->_rect_x->text().toStdString());
            y = std::stod(ui->_rect_y->text().toStdString());
            w = std::stod(ui->_rect_w->text().toStdString());
            h = std::stod(ui->_rect_h->text().toStdString());
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        qInfo() << "set_connect afther clicked";     
        emit addRect(std::make_tuple(x, y, w, h));
    });
    connect(ui->_add_circle, &QPushButton::clicked, [this]()
    {
        int x = 0,
        y = 0,
        r = 0;
        try
        {
            x = std::stod(ui->_circle_x->text().toStdString());
            y = std::stod(ui->_circle_y->text().toStdString());
            r = std::stod(ui->_circle_r->text().toStdString());
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        qInfo() << "set_connect afther clicked";     
        emit addCircle(std::make_tuple(x, y, r));
    });
}

void MyView::drawGrid(qreal gridSize){
    ui->_board_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->_board_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

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

void MyView::display_shapes(std::vector<std::shared_ptr<QGraphicsItem>>& shapes, size_t index)
{
    auto items = _scene->items();

    for (const auto& shape : shapes)
    {
        auto it = std::find_if(items.begin(), items.end(), 
        [&](QGraphicsItem* item) {
            return dynamic_cast<QGraphicsItem*>(item) == shape.get();
        });
    
        if (it == items.end())
        {
            _scene->addItem(shape.get());
        }
    }
}







