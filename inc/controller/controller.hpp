#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include <memory>
#include "model.hpp"
#include "view.hpp"
#include "observer.hpp"

class Controller : public QObject, public Observer 
{
    Q_OBJECT
public:
    std::unique_ptr<Model> _model;
    std::unique_ptr<MyView> _view;

public:
    Controller(Model *model, MyView* view);
    ~Controller();
    void update() override;
private slots:
    void handleAddShape(const std::tuple<int, int, int, int> &rect_inf);
};

#endif // CONTROLLER_HPP
