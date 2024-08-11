#ifndef BOARD_HPP
#define BOARD_HPP
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>

class Board : public QObject {
    Q_OBJECT

private:
    QGraphicsScene *_scene;
    QGraphicsView *_view;
    int _x = 10;
    int _y = 10;
    int _curr_height = 100;
    int _curr_width = 100;
public slots:
    void add_rect();

public:
    Board(QGraphicsView *view, QObject *parent = nullptr);
    ~Board();
    void set_width(int width);
    void set_height(int height);
    void drawCoordinateAxes(int length, int thickness);
    void set_opbects();
};

#endif // BOARD_HPP
