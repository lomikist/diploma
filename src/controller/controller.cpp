#include <QLoggingCategory>
#include <tuple>
#include "controller.hpp"

Controller::Controller(Model *model, MyView *view)
{
    _model.reset(model);
    _view.reset(view);
    connect(view, &MyView::addShapeRequested, this, &Controller::handleAddShape);
}

void Controller::handleAddShape(const std::tuple<int, int, int, int> &rect_inf)
{
    _model->add_rect(
                     std::get<0>(rect_inf),
                     std::get<1>(rect_inf),
                     std::get<2>(rect_inf),
                     std::get<3>(rect_inf)
                     );
    _view->display_shapes(_model->get_shapes());

}

Controller::~Controller()
{
}
