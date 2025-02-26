#pragma once
#include "editor.hpp"
#include "model.hpp"
#include "parser.hpp"
#include <memory>
#include <qapplication.h>

namespace core
{
class App : public QApplication 
{
public:
    static App& instance();

    App(int &argc, char *argv[]);
    ~App();

    App(const App&) = delete;
    App(App&&) = delete;
    App& operator=(const App&) = delete;
    App& operator=(App&&) = delete;

    std::shared_ptr<cli::Parser>        get_parser();
    std::shared_ptr<model::Model>       get_model();
    std::shared_ptr<core::Editor>       get_editor();

    void start(std::istream& );
private:
    std::shared_ptr<model::Model>       m_model;
    std::shared_ptr<cli::Parser>        m_parser;
    std::shared_ptr<core::Editor>       m_editor;

};
}
