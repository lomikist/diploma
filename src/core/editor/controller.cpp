#include "controller.hpp"
#include "app.hpp"
#include "crossover_one_point.hpp"
#include "crossover_two_point.hpp"
#include "crossover_uniform.hpp"
#include "fitness_manhattan.hpp"
#include "model.hpp"
#include "mutate_random.hpp"
#include "select_to_half.hpp"
#include "types.hpp"
#include <memory>
#include <qapplication.h>
#include <qdatetime.h>
#include <qeventloop.h>
#include <qobjectdefs.h>
#include <QTimer>
#include <QDebug>

core::Controller::Controller(std::shared_ptr<model::Model> model) :
    m_model(model),
    m_mutate(std::make_shared<core::MutateRandom>())
{
    auto main_window    = App::instance()->get_gui_controller()->get_main_window();
    auto fitnes_val     = main_window->get_combobox_fitness()->currentText();
    auto cross_val      = main_window->get_combobox_crossover()->currentText();
    auto select_val     = main_window->get_combobox_select()->currentText();

    //for now in TODO make with factory method
    // Fitness
    if (fitnes_val == "Wire Length"){
        m_fitness = std::make_shared<core::FitnessManhattan>();
    }
    // Crossover
    if (cross_val == "One Point")
        m_crossover = std::make_shared<core::CrossoverOnePoint>();
    else if(cross_val == "Two Point")
        m_crossover = std::make_shared<core::CrossoverTwoPoint>();
    else if(cross_val == "Uniform")
        m_crossover = std::make_shared<core::CrossoverUniform>();

    if (select_val == "To Half")
        m_select = std::make_shared<core::SelectToHalf>();


};

void core::Controller::evaluate(const tp::Graph& graph, const model::Population& pop)
{
    auto main_window    = App::instance()->get_gui_controller()->get_main_window();
    auto pop_size       = main_window->get_spinbox_generation()->value();
    model::Population population = pop; 


    for (int i = 0; i < pop_size; ++i)
    {
        population.set_chromosomes(m_select->cross_select(m_fitness, m_crossover, graph, population.get_chromosomes()));
        population.set_chromosomes(m_mutate->mutate(population.get_chromosomes()));

        m_model->set_population(population);
        notify_observers();
        QApplication::processEvents();
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

