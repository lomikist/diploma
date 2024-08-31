#ifndef VIEW_HPP
#define VIEW_HPP

#include "rect.hpp"
#include "ui_main_form.h"
#include <QMainWindow>
#include <cstddef>
#include <tuple>

class MyView : public QMainWindow {
  Q_OBJECT

public:
  MyView(QWidget *parent = nullptr);
  ~MyView();
  void display_shapes(const std::vector<Rect> &, size_t index = 0);
signals:
  void addShapeRequested(const std::tuple<int, int, int, int> &shape);

private:
  void drawGrid(qreal gridSize);

public:
  Ui::MainForm *ui;
  QGraphicsScene *scene;
};

#endif // VIEW_HPP
