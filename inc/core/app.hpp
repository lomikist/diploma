#pragma once
#include "controller.hpp"
#include "gui_controller.hpp"
#include "model.hpp"
#include "parser.hpp"
#include <memory>
#include <qapplication.h>

namespace core
{
class App : public QApplication 
{
public:
    static App* instance();

    App(int &argc, char *argv[]);
    ~App();

    App(const App&) = delete;
    App(App&&) = delete;
    App& operator=(const App&) = delete;
    App& operator=(App&&) = delete;

    std::shared_ptr<cli::Parser>        get_parser() const;
    std::shared_ptr<model::Model>       get_model() const;
    std::shared_ptr<core::Controller>   get_editor() const;
    std::shared_ptr<gui::GuiController> get_gui_controller() const;

    void start();
private:
    std::shared_ptr<model::Model>       m_model;
    std::shared_ptr<cli::Parser>        m_parser;
    std::shared_ptr<core::Controller>   m_editor;
    std::shared_ptr<gui::GuiController> m_gui;

};
}
