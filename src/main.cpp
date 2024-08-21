#include "controller.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model *model = new Model();
    MyView *view = new MyView();
    Controller controller(model, view);
    controller._view->show();
    return a.exec();
}
