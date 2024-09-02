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
   _model->addObserver(shared_from_this());
}
void Controller::start_connect()
{
    connect(_view.get(), &MyView::addShapeRequested, this, &Controller::handleAddShape);
}
void Controller::handleAddShape(const std::tuple<int, int, int, int> &rect_inf)
{
    qInfo() << "handleaddshape";
    _model->add_rect(
                     std::get<0>(rect_inf),
                     std::get<1>(rect_inf),
                     std::get<2>(rect_inf),
                     std::get<3>(rect_inf)
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
