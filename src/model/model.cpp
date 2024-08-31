#include "model.hpp"
#include "observer.hpp"
#include <cstddef>
#include <memory>
#include <vector>
#include <algorithm>
Model::Model()
{
}

Model::~Model()
{
}

void Model::add_rect(int x, int y, int w, int h)
{
    _shapes.push_back(Rect(x, y, w, h));
}

void Model::move_rect(size_t index, int x, int y)
{
  
}

const std::vector<Rect>& Model::get_shapes() const 
{
    return _shapes;
}

void Model::addObserver(std::shared_ptr<Observer> observer)
{
    _observers.push_back(observer);
}
void Model::removeObserver(std::shared_ptr<Observer> observer)
{
    _observers.erase(
        std::remove_if(
            _observers.begin(), _observers.end(),
            [&observer](const std::shared_ptr<Observer> & elem){return elem == observer;}
        ),
        _observers.end()
    );
}
void Model::notifyObservers()
{
    for (auto&& observer : _observers)
    {
        if (observer)
        {
            observer->update();
        }
    }
}

