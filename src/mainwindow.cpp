#include "../inc/mainwindow.hpp"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene* scene = new QGraphicsScene(this);
    _my_board = new Board(ui->board_view, scene);

    _my_board->set_opbects();

    connect(ui->add_rect, &QPushButton::clicked, this, &MainWindow::change_position);
    connect(ui->add_rect, &QPushButton::clicked, _my_board, &Board::add_rect);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::change_position()
{
    _my_board->set_height(ui->y_spin_box->value());
    _my_board->set_width(ui->x_spin_box->value());
}