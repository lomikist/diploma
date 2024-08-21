#ifndef VIEW_HPP
#define VIEW_HPP
#include <QMainWindow>
#include <tuple>
#include "ui_main_form.h"  
#include "rect.hpp"


class MyView : public QMainWindow {
    Q_OBJECT

public:
    MyView(QWidget *parent = nullptr);
    ~MyView();
    void display_shapes(const std::vector<Rect> &);

signals:
    void addShapeRequested(const std::tuple<int, int, int, int>& shape);

private:
public:
    Ui::MainForm *ui;
    QGraphicsScene *scene;
};

#endif // VIEW_HPP
