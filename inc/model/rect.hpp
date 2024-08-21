#ifndef RECT_HPP
#define RECT_HPP
#include <QDebug>
#include <QGraphicsRectItem>
class Rect
{
private:
    int _x = 0;
    int _y = 0;
    int _h = 0;
    int _w = 0;
public:
    Rect(int x, int y, int h, int w);
    ~Rect();

    // if you want to change ui framework you need override this function. 
    QRect getRect() const {
        return QRect(_x, _y, _w, _h);
    } 

    friend QDebug operator<<(QDebug debug, const Rect &rect) {
        QDebugStateSaver saver(debug);
        debug.nospace() << "Rect(" << rect._x << ", " << rect._y << ", "
                        << rect._w << ", " << rect._h << ")";
        return debug;
    }
};

#endif