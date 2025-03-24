#include "main_window.hpp"
#include "paint_area.hpp"
#include "file_selector.hpp"
#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsPolygonItem>
#include <QPen>
#include <QColor>
#include <qboxlayout.h>
#include <qcombobox.h>
#include <qnamespace.h>
#include <QPushButton>
#include <qpushbutton.h>

gui::MainWindow::MainWindow(QWidget *parent) 
    : QMainWindow(parent),
     m_central_widget(new QWidget(this))  
{
    setWindowTitle("Diploma");
    setWindowState(Qt::WindowMaximized);
    setCentralWidget(m_central_widget);

    setup_layout(); 
    setup_widgets();
}

void gui::MainWindow::setup_layout()
{
    m_main_layout   = new QHBoxLayout();
    m_tools_layout  = new QVBoxLayout();
    m_parea_layout  = new QVBoxLayout();
     
    m_main_layout->addLayout(m_tools_layout);
    m_main_layout->addLayout(m_parea_layout);
     
    m_central_widget->setLayout(m_main_layout);
}

void gui::MainWindow::setup_widgets()
{
    m_box_fitness   = new QComboBox();
    m_box_select    = new QComboBox();
    m_box_mutate    = new QComboBox();
    m_box_crossover = new QComboBox();
    m_paint_area    = new PaintArea();
    m_btn_start     = new QPushButton("Start");
    m_file_selector = new FileSelector();

    m_tools_layout->addWidget(m_file_selector);
    m_tools_layout->addWidget(m_box_fitness);
    m_tools_layout->addWidget(m_box_crossover);
    m_tools_layout->addWidget(m_box_mutate);
    m_tools_layout->addWidget(m_box_select);
    m_tools_layout->addWidget(m_btn_start);
    m_parea_layout->addWidget(m_paint_area);
};

QComboBox* gui::MainWindow::get_box_fitness() const { return m_box_fitness; }

QComboBox* gui::MainWindow::get_box_select() const { return m_box_select; }

QComboBox* gui::MainWindow::get_box_mutate() const { return m_box_mutate; }

QComboBox* gui::MainWindow::get_box_crossover() const { return m_box_crossover; }

QHBoxLayout* gui::MainWindow::get_main_layout() const { return m_main_layout; }

QVBoxLayout* gui::MainWindow::get_tools_layout() const { return m_tools_layout; }

QVBoxLayout* gui::MainWindow::get_parea_layout() const { return m_parea_layout; }

QWidget* gui::MainWindow::get_central_widget() const { return m_central_widget; }

QPushButton* gui::MainWindow::get_btn_start() const { return m_btn_start; }

gui::PaintArea* gui::MainWindow::get_paint_area() const { return m_paint_area; }

gui::FileSelector* gui::MainWindow::get_file_selector() const { return m_file_selector; }

