#include "app.hpp"
#include "gui_controller.hpp"
#include "logger/guilogger.hpp"
#include "logger/oslogger.hpp"
#include "parser_netlist.hpp"
#include <fstream>
#include <istream>
#include <qapplication.h>


core::App* core::App::instance()
{
    return static_cast<App*>(QApplication::instance());
}

core::App::App(int &argc, char *argv[])
            : QApplication(argc, argv)
{
    m_model     = std::make_shared<model::Model>();
    m_gui       = std::make_shared<gui::GuiController>();
    m_editor    = std::make_shared<core::Controller>(m_model);
    m_logger    = std::make_shared<core::Logger>();

    m_logger->add_logger(std::make_shared<core::OsLogger>(&std::cout));
    m_logger->add_logger(std::make_shared<core::GuiLogger>(m_gui->get_main_window()->get_text_browser()));

    m_editor->add_observer(m_gui);
    m_editor->set_model(m_model);
}

void core::App::start()
{
    auto path = m_gui->get_main_window()->get_file_selector()->get_file_path().toStdString();
    std::ifstream file(path);

    m_editor->evaluate(file);
}

void core::App::output()
{
    m_editor->get_parser()->generate_output(m_model->get_population().get_chromosome(0).first);
};

core::App::~App()
{}


std::shared_ptr<model::Model>   core::App::get_model() const
{
    return m_model;
}

std::shared_ptr<core::Controller>   core::App::get_editor() const
{
    return m_editor;
}
std::shared_ptr<gui::GuiController>  core::App::get_gui_controller() const
{
    return m_gui;
}

std::shared_ptr<core::Logger>   core::App::get_logger()
{  
    return m_logger;
};
