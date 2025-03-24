#pragma once

#include "iobserver.hpp"
#include <memory>
#include <vector>

namespace core 
{
class ISubject
{
public:
    virtual void notify_observers() = 0;
    virtual void add_observer(std::shared_ptr<IObserver> observer) = 0; 
protected:
    std::vector<std::shared_ptr<IObserver>> _observers;
};
}

