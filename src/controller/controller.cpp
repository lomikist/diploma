#include "controller.hpp"
#include "QLittleEndianStorageType"
#include "observer.hpp"
#include "qlogging.h"
#include "view.hpp"
#include <memory>

Controller::Controller(std::unique_ptr<Model> model, std::unique_ptr<MyView> view)
:   _model(std::move(model)),
    _view(std::move(view))
{
    qInfo("controller constructur");
}

void Controller::start()
{
    _view->setWindowState(Qt::WindowMaximized);

    _model->addObserver(shared_from_this());
}
void Controller::start_connect()
{
    connect(_view.get(), &MyView::addRect, this, &Controller::handleRectAdd);
    connect(_view.get(), &MyView::addCircle, this, &Controller::handleCircleAdd);
}

void Controller::handleRectAdd(const std::tuple<int, int, int, int> &rect_inf)
{
    qInfo() << "handleaddshape";
    _model->add_rect(
                     std::get<0>(rect_inf),
                     std::get<1>(rect_inf),
                     std::get<2>(rect_inf),
                     std::get<3>(rect_inf)
                     );
}
void Controller::handleCircleAdd(const std::tuple<int, int, int> &rect_inf)
{
    qInfo() << "handleaddshape";
    _model->add_circle(
                     std::get<0>(rect_inf),
                     std::get<1>(rect_inf),
                     std::get<2>(rect_inf)
                     );
}

void Controller::update()
{
    qInfo() << "udaate";
    _view->display_shapes(_model->get_shapes());
}

Controller::~Controller()
{

    qInfo("controller dest");
}
