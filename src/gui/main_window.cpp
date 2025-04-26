#include "main_window.hpp"
#include "paint_area.hpp"
#include "file_selector.hpp"
#include <QLabel>
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
#include <qlabel.h>
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
     
    m_main_layout->addLayout(m_parea_layout);
    m_main_layout->addLayout(m_tools_layout);
     
    m_central_widget->setLayout(m_main_layout);
}

void gui::MainWindow::setup_widgets()
{
    m_group_mutate      = new QGroupBox("Mutation Rate ");
    m_group_fitness     = new QGroupBox("Fitness Function");
    m_group_select      = new QGroupBox("Selecting Strategy");
    m_group_crossover   = new QGroupBox("Crossover Type");

    m_combobox_fitness      = new QComboBox();
    m_combobox_select       = new QComboBox();
    m_combobox_crossover    = new QComboBox();
    m_spinbox_mutate        = new QSpinBox();
    m_spinbox_generation    = new QSpinBox();

    m_combobox_fitness->addItems({"Wire Length", "Congestion", "Hybrid"});
    m_combobox_select->addItems({"To Half"});
    m_combobox_crossover->addItems({"One Point", "Two Point", "Uniform"});

    
    QVBoxLayout* crossover_layout   = new QVBoxLayout(m_group_crossover);
    QVBoxLayout* select_layout      = new QVBoxLayout(m_group_select);
    QVBoxLayout* fitness_layout     = new QVBoxLayout(m_group_fitness);
    QVBoxLayout* mutation_layout    = new QVBoxLayout(m_group_mutate);

    crossover_layout->addWidget(m_combobox_crossover);
    select_layout->addWidget(m_combobox_select);
    fitness_layout->addWidget(m_combobox_fitness);

    mutation_layout->addWidget(new QLabel("Mutation Rate (%)):"), 0);
    m_spinbox_mutate->setRange(1, 40);
    m_spinbox_mutate->setValue(5);
    mutation_layout->addWidget(m_spinbox_mutate);

    mutation_layout->addWidget(new QLabel("Population Size:"), 0);
    m_spinbox_generation->setRange(20, 1000);
    m_spinbox_generation->setValue(100);
    mutation_layout->addWidget(m_spinbox_generation);

    m_paint_area    = new PaintArea();
    m_cmd_browser   = new QTextBrowser(this);
    m_btn_start     = new QPushButton("Start");
    m_file_selector = new FileSelector();
    m_cmd_browser->setFixedHeight(100);

    m_tools_layout->addWidget(m_file_selector);
    m_tools_layout->addWidget(m_group_fitness);
    m_tools_layout->addWidget(m_group_crossover);
    m_tools_layout->addWidget(m_group_mutate);
    m_tools_layout->addWidget(m_group_select);
    m_tools_layout->addWidget(m_btn_start);
    // m_tools_layout->addWidget(m_cmd_browser);
    m_tools_layout->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));

    m_parea_layout->addWidget(m_paint_area);
    m_parea_layout->addWidget(m_cmd_browser);
};

QComboBox* gui::MainWindow::get_combobox_fitness() const { return m_combobox_fitness; }

QComboBox* gui::MainWindow::get_combobox_select() const { return m_combobox_select; }

QSpinBox* gui::MainWindow::get_spinbox_mutate() const { return m_spinbox_mutate; }

QSpinBox* gui::MainWindow::get_spinbox_generation() const { return m_spinbox_generation; }

QComboBox* gui::MainWindow::get_combobox_crossover() const { return m_combobox_crossover; }

QHBoxLayout* gui::MainWindow::get_main_layout() const { return m_main_layout; }

QVBoxLayout* gui::MainWindow::get_tools_layout() const { return m_tools_layout; }

QVBoxLayout* gui::MainWindow::get_parea_layout() const { return m_parea_layout; }

QWidget* gui::MainWindow::get_central_widget() const { return m_central_widget; }

QPushButton* gui::MainWindow::get_btn_start() const { return m_btn_start; }

gui::PaintArea* gui::MainWindow::get_paint_area() const { return m_paint_area; }

gui::FileSelector* gui::MainWindow::get_file_selector() const { return m_file_selector; }

QTextBrowser* gui::MainWindow::get_text_browser() const { return m_cmd_browser;}

