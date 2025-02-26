#include "app.hpp"
#include "editor.hpp"
#include "types.hpp"
#include <istream>

core::App::App(int &argc, char *argv[]) 
                : QApplication(argc, argv)
{

    /*_parser         = std::make_unique<cli::Parser>();*/
    /*_model          = std::make_shared<model::Model>();*/
    /*_gui_controller = std::make_shared<gui::GuiController>();*/
    /*_editor         = std::make_shared<core::Editor>();*/
    /*_logger         = std::make_shared<core::Logger>();*/
    /*_vizualizer     = std::make_shared<core::Vizualizer>();*/
    /**/
    /*_editor->set_model(_model);*/
    /*_vizualizer->set_model(_model);*/
    /**/
    /*_editor->addObserver(_gui_controller);*/
    /**/
    /*_logger->add_logger(std::make_shared<OsLogger>(&std::cout));*/
    /*_logger->add_logger(std::make_shared<GuiLogger>(_gui_controller->get_screen()->get_text_browser()));*/
    m_parser = std::make_shared<cli::Parser>();
}

void core::App::start(std::istream& stream)//TODO or controller which would be handle
{
    m_model = std::make_shared<model::Model>(m_parser->parseGraph(stream));
    m_editor = std::make_shared<core::Editor>(m_model);

    m_model->get_population().get_chromosome(tp::POPULATION_SIZE - 1)->print();
    m_editor->evaluate(m_model->get_adj_graph(), m_model->get_population());
    std::cout << "\n";
    m_model->get_population().get_chromosome(0)->print();
}

core::App::~App()
{}

std::shared_ptr<cli::Parser>    core::App::get_parser()
{
    return m_parser;
}

std::shared_ptr<model::Model>   core::App::get_model()
{
    return m_model;
}

std::shared_ptr<core::Editor>   core::App::get_editor()
{
    return m_editor;
}

/* std::shared_ptr<core::Logger>       get_logger(); */

