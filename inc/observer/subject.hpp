// subject.hpp
#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include "observer.hpp"
#include "qlogging.h"
#include <algorithm>
#include <memory>

class Subject {
public:
    virtual void addObserver(const std::shared_ptr<Observer>& observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject(){qInfo("subject dest");};
};

#endif // SUBJECT_HPP
