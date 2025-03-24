#include "controller.hpp"
#include "crossover_one_point.hpp"
#include "crossover_two_point.hpp"
#include "crossover_uniform.hpp"
#include "fitness_manhattan.hpp"
#include "model.hpp"
#include "mutate_random.hpp"
#include "select_to_half.hpp"
#include "types.hpp"
#include <chrono>
#include <memory>
#include <ostream>
#include <qdatetime.h>
#include <qeventloop.h>
#include <qobjectdefs.h>
#include <QTimer>
#include <thread>

core::Controller::Controller(std::shared_ptr<model::Model> model) :
    m_model(model),
    m_fitness(std::make_shared<core::FitnessManhattan>()),
    m_crossover(std::make_shared<core::CrossoverTwoPoint>()),
    m_select(std::make_shared<core::SelectToHalf>()),
    m_mutate(std::make_shared<core::MutateRandom>())
{};

void core::Controller::evaluate(const tp::Graph& graph, const model::Population& pop)
{
    model::Population population = pop; 

    for (int i = 0; i < tp::GENERATION_SIZE; ++i){
        population.set_chromosomes(m_select->cross_select(m_fitness, m_crossover, graph, population.get_chromosomes()));
        population.set_chromosomes(m_mutate->mutate(population.get_chromosomes()));

        m_model->set_population(population);
        notify_observers();
    }
}

void core::Controller::notify_observers()
{
    for (auto&& observer : _observers) {
        observer->update();
    }
}

void core::Controller::add_observer(std::shared_ptr<IObserver> new_observer) 
{
    _observers.push_back(new_observer); 
} 

void core::Controller::set_model(std::shared_ptr<model::Model> model) 
{
    m_model = model; 
} 

