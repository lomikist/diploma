#include "controller.hpp"
#include "app.hpp"
#include "crossover_one_point.hpp"
#include "crossover_two_point.hpp"
#include "crossover_uniform.hpp"
#include "fitness_manhattan.hpp"
#include "model.hpp"
#include "mutate_random.hpp"
#include "parser_netlist.hpp"
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
    select_options();
};

void core::Controller::select_options()
{
    auto main_window    = App::instance()->get_gui_controller()->get_main_window();
    auto fitnes_val     = main_window->get_combobox_fitness()->currentText();
    auto cross_val      = main_window->get_combobox_crossover()->currentText();
    auto select_val     = main_window->get_combobox_select()->currentText();
    auto parser_val     = main_window->get_combobox_parser()->currentText();

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

    // Select
    if (select_val == "To Half")
        m_select = std::make_shared<core::SelectToHalf>();


    //Parser
    if (parser_val == "Simple"){
        m_parser = std::make_shared<cli::Parser>();
    }else {
        m_parser = std::make_shared<cli::ParserNetlist>();
    }
};

void core::Controller::evaluate(std::istream& file)
{
    select_options();
    m_model->set_adj_graph(m_parser->parseGraph(file));
    m_model->get_population().initialize(m_model->get_adj_graph(), tp::POPULATION_SIZE, tp::CHROMOSOME_WIDTH, tp::CHROMOSOME_HEIGHT);

    auto main_window    = App::instance()->get_gui_controller()->get_main_window();
    auto pop_size       = main_window->get_spinbox_generation()->value();
    model::Population population = m_model->get_population(); 

    for (int i = 0; i < pop_size; ++i)
    {
        population.set_chromosomes(m_select->cross_select(m_fitness, m_crossover, m_model->get_adj_graph(), population.get_chromosomes()));
        population.set_chromosomes(m_mutate->mutate(population.get_chromosomes()));

        m_model->set_population(population);
        notify_observers();
        core::App::instance()->get_logger()->notify_loggers(
            "Fitness cost - " + std::to_string(population.get_chromosome(0).second)
        );

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

std::shared_ptr<cli::IParser> core::Controller::get_parser() const
{
    return m_parser;
}

