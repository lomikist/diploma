#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include <memory>
#include "model.hpp"
#include "view.hpp"
#include "observer.hpp"

class Controller : public QObject, public Observer, public std::enable_shared_from_this<Controller>
{
    Q_OBJECT
public:
    std::unique_ptr<Model> _model;
    std::unique_ptr<MyView> _view;

public:
    Controller(std::unique_ptr<Model> model, std::unique_ptr<MyView> view);
    ~Controller();
    void update() override;
    void start();
    void start_connect();
private slots:
    void handleAddShape(const std::tuple<int, int, int, int> &rect_inf);
};

#endif // CONTROLLER_HPP
