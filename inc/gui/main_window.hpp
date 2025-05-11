#pragma once

#include "paint_area.hpp"
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <qboxlayout.h>
#include <qcombobox.h>
#include <QSpinBox>
#include <qgraphicsitem.h>
#include <QTextBrowser>
#include <QComboBox>
#include <QGroupBox>
#include <qpushbutton.h>
#include <qtextbrowser.h>
#include "file_selector.hpp"

namespace gui
{
class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);
    PaintArea*      get_paint_area() const;

    QComboBox*      get_combobox_fitness() const;
    QComboBox*      get_combobox_select() const;
    QComboBox*      get_combobox_parser() const;
    QComboBox*      get_combobox_crossover() const;
    QSpinBox*       get_spinbox_mutate() const;
    QSpinBox*       get_spinbox_generation() const;
    QTextBrowser*   get_text_browser() const;

    QHBoxLayout*    get_main_layout() const;
    QVBoxLayout*    get_tools_layout() const;
    QVBoxLayout*    get_parea_layout() const;
    QWidget*        get_central_widget() const;
    QPushButton*    get_btn_start() const;
    QPushButton*    get_btn_output() const;
    FileSelector*   get_file_selector() const;
private:
    void setup_layout();
    void setup_widgets();

    PaintArea*      m_paint_area;
    QTextBrowser*   m_cmd_browser;
    QComboBox*      m_combobox_fitness;
    QComboBox*      m_combobox_select;
    QComboBox*      m_combobox_crossover;
    QComboBox*      m_combobox_parser;
    QSpinBox*       m_spinbox_mutate;
    QSpinBox*       m_spinbox_generation;

    QGroupBox*      m_group_fitness;
    QGroupBox*      m_group_select;
    QGroupBox*      m_group_crossover;
    QGroupBox*      m_group_mutate;
    QGroupBox*      m_group_parser;

    QHBoxLayout*    m_main_layout;
    QVBoxLayout*    m_tools_layout;
    QVBoxLayout*    m_parea_layout;

    QWidget*        m_central_widget;
    QPushButton*    m_btn_start;
    QPushButton*    m_btn_output;
    FileSelector*   m_file_selector;
};
}

