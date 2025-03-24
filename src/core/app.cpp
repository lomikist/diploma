#include "app.hpp"
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
    m_parser    = std::make_shared<cli::Parser>();
    m_gui       = std::make_shared<gui::GuiController>();
    m_editor    = std::make_shared<core::Controller>(m_model);
    m_editor->add_observer(m_gui);
}

/*void core::App::start(std::istream& stream)*/
/*{*/
/*    m_model = std::make_shared<model::Model>(m_parser->parseGraph(stream));*/
/**/
/*    //////////////////////////*/
/*    m_model->get_population().get_chromosome(0).first->print();*/
/*    m_editor->evaluate(m_model->get_adj_graph(), m_model->get_population());*/
/*    std::cout << "\n";*/
/*    m_model->get_population().get_chromosome(0).first->print();*/
/**/
/*}*/

void core::App::start()
{
    auto path = m_gui->get_main_window()->get_file_selector()->get_file_path().toStdString();
    std::ifstream file(path);

    m_model = std::make_shared<model::Model>(m_parser->parseGraph(file));
    //log
    m_model->get_population().get_chromosome(0).first->print();
    //logend

    m_editor->set_model(m_model);
    m_editor->evaluate(m_model->get_adj_graph(), m_model->get_population());

    //log
    m_model->get_population().get_chromosome(0).first->print();
    //logend

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

std::shared_ptr<core::Controller>   core::App::get_editor()
{
    return m_editor;
}

