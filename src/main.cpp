#include <QApplication>
#include <memory>
#include "controller.hpp"
#include "model/model.hpp"
#include "view.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto controller = std::make_shared<Controller>(std::make_unique<Model>(), std::make_unique<MyView>());
    controller->start();
    controller->start_connect(); 
    controller->_view->show();
    return a.exec();
}
