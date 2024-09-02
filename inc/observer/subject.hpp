// subject.hpp
#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include "observer.hpp"
#include <algorithm>
#include <memory>

class Subject {
public:
    virtual void addObserver(std::weak_ptr<Observer> observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject() = default;
};

#endif // SUBJECT_HPP
