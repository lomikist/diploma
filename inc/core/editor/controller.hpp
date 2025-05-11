#pragma once
#include "icrossover.hpp"
#include "ifitness.hpp"
#include "iparser.hpp"
#include "model.hpp"
#include "imutate.hpp"
#include "isubject.hpp"
#include "population.hpp"
#include "iselect.hpp"
#include "types.hpp"
#include <istream>

namespace core 
{
class Controller : public ISubject
{
public:
    Controller(std::shared_ptr<model::Model> model = nullptr);
    void evaluate(std::istream& file);
    void notify_observers() override;
    void add_observer(std::shared_ptr<IObserver> new_observer) override; 
    void set_model(std::shared_ptr<model::Model> model);
    std::shared_ptr<cli::IParser>        get_parser() const;
private:
    void select_options();
    std::shared_ptr<model::Model>       m_model;
    std::shared_ptr<core::Ifitness>     m_fitness;
    std::shared_ptr<core::Icrossover>   m_crossover;
    std::shared_ptr<core::Iselect>      m_select;
    std::shared_ptr<core::Imutate>      m_mutate;
    std::shared_ptr<cli::IParser>       m_parser;
};
}
