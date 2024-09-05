#include "model.hpp"
#include "circle.hpp"
#include "observer.hpp"
#include "qlogging.h"
#include <cstddef>
#include <memory>
#include <vector>

Model::Model()
{
    qInfo("model sovorakan constructur");
}

Model::Model(Model&& other) noexcept
{
    qInfo("model move constructur");
    _shapes = std::move(other._shapes);
    _observers = std::move(other._observers);
}

Model& Model::operator=(Model&& other) noexcept
{
    qInfo("model copy constructur");
    if (&other != this) {
        _shapes = std::move(other._shapes);
        _observers = std::move(other._observers);
    }    
    return *this;
}

Model::~Model()
{ 
    qInfo("mode destructur");
}

void Model::add_rect(int x, int y, int w, int h)
{
    qInfo() << "addrect";
    _shapes.push_back(std::make_shared<Rect>(x, y, w, h));
    notifyObservers();
}

void Model::add_circle(int x, int y, int h)
{
    _shapes.push_back(std::make_shared<Circle>(x, y, h));
    notifyObservers();
}

void Model::move_rect(size_t index, int x, int y)
{ 
}

std::vector<std::shared_ptr<QGraphicsItem>>& Model::get_shapes()
{
    return _shapes;
}

void Model::addObserver(const std::shared_ptr<Observer>& observer)
{
    std::weak_ptr<Observer> wp = observer;
    _observers.push_back(std::move(wp));
}

void Model::removeObserver(Observer* observer)
{
}

void Model::notifyObservers()
{
    for (auto&& weak_obser : _observers)
    {
        if (auto shared = weak_obser.lock())
        {
            shared->update();
        }
    }
}

