#include "app.hpp"
#include "editor.hpp"
#include <istream>

core::App& core::App::instance(){
    static App instance;
    return instance;
}

core::App::App()
{
    m_parser = std::make_shared<cli::Parser>();
}

void core::App::start(std::istream& stream)// or controller which would be handle
{
    m_model = std::make_shared<model::Model>(m_parser->parseGraph(stream));
    m_editor = std::make_shared<core::Editor>(m_model);

    m_editor->evaluate(m_model->get_adj_graph(), m_model->get_population());
    /*m_model->get_population().print();*/
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

