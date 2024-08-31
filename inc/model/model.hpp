#ifndef MODEL_HPP
#define MODEL_HPP
#include <cstddef>
#include <iostream>
#include <memory>
#include <vector>
#include "observer.hpp"
#include "rect.hpp"
#include "subject.hpp"


class Model : public Subject
{
private:
    std::vector<Rect> _shapes;
    std::vector<std::shared_ptr<Observer>> _observers;
public:
    Model();
    ~Model();
    //   
    void add_rect(int x, int y, int h, int w);
    void move_rect(size_t index, int x, int y);
    
    void remove_rect(size_t index);
    const std::vector<Rect>& get_shapes() const;
    // observer part 
    void addObserver(std::shared_ptr<Observer> observer) override;
    void removeObserver(std::shared_ptr<Observer> observer) override;
    void notifyObservers() override; 
};

#endif // MODEL_HPP

