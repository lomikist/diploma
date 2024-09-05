#ifndef VIEW_HPP
#define VIEW_HPP

#include "ui_main_form.h"
#include <QMainWindow>
#include <cstddef>
#include <memory>
#include <tuple>

class MyView : public QMainWindow {
    Q_OBJECT

public:
    MyView(QWidget *parent = nullptr);
    MyView(MyView&&) noexcept;
    MyView& operator=(MyView&&);
    MyView(const MyView&) = delete;
    MyView& operator=(const MyView&) = delete;
    ~MyView();
    void display_shapes(std::vector<std::shared_ptr<QGraphicsItem>> &, size_t index = 0);
signals:
    void addRect(const std::tuple<int, int, int, int> &shape);
    void addCircle(const std::tuple<int, int, int> &shape);

private:
    void drawGrid(qreal gridSize);
    void set_connect();
public:
    Ui::MainForm *ui;
    QGraphicsScene *_scene;
};

#endif // VIEW_HPP
