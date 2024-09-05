#ifndef MODEL_HPP
#define MODEL_HPP
#include <cstddef>
#include <memory>
#include <vector>
#include "observer.hpp"
#include "rect.hpp"
#include "subject.hpp"

class Model : public Subject
{
private:
    std::vector<std::shared_ptr<QGraphicsItem>> _shapes;
    std::vector<std::weak_ptr<Observer>> _observers;
public:
    Model();
    Model(Model&& other) noexcept;
    Model& operator=(Model && other) noexcept;
    Model(const Model&) = delete;
    Model& operator=(const Model&) = delete;
    ~Model();
    //   
    void add_rect(int x, int y, int h, int w);
    void add_circle(int x, int y, int h);
    void move_rect(size_t index, int x, int y);
    
    void remove_rect(size_t index);
    std::vector<std::shared_ptr<QGraphicsItem>>& get_shapes();
    
    // observer part 
    void addObserver(const std::shared_ptr<Observer>& observer) override;
    void removeObserver(Observer* observer) override;
    void notifyObservers() override; 
};
#endif // MODEL_HPP

