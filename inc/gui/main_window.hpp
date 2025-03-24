#pragma once
#include "paint_area.hpp"
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <qboxlayout.h>
#include <qcombobox.h>
#include <qgraphicsitem.h>
#include <QTextBrowser>
#include <QComboBox>
#include <qpushbutton.h>
#include "file_selector.hpp"

namespace gui
{
class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);
    PaintArea*      get_paint_area() const;
    QComboBox*      get_box_fitness() const;
    QComboBox*      get_box_select() const;
    QComboBox*      get_box_mutate() const;
    QComboBox*      get_box_crossover() const;
    QHBoxLayout*    get_main_layout() const;
    QVBoxLayout*    get_tools_layout() const;
    QVBoxLayout*    get_parea_layout() const;
    QWidget*        get_central_widget() const;
    QPushButton*    get_btn_start() const;
    FileSelector*   get_file_selector() const;
private:
    void setup_layout();
    void setup_widgets();

    PaintArea*      m_paint_area;
    QComboBox*      m_box_fitness;
    QComboBox*      m_box_select;
    QComboBox*      m_box_mutate;
    QComboBox*      m_box_crossover;

    QHBoxLayout*    m_main_layout;
    QVBoxLayout*    m_tools_layout;
    QVBoxLayout*    m_parea_layout;

    QWidget*        m_central_widget;
    QPushButton*    m_btn_start;
    FileSelector*   m_file_selector;
};
}

