#pragma once
#include "icanvas.hpp"
#include "iobserver.hpp"
#include "main_window.hpp"
#include <memory>
namespace gui 
{
const int PAREA_HEIGHT      = 800;
const int PAREA_WIDTH       = 800;
/*const int BTN_ICONE_HEIGHT  = 100;*/
/*const int BTN_ICONE_WIDTH   = 100;*/

class GuiController : public QObject, public core::IObserver
{
    Q_OBJECT
public: 
    GuiController();
    void update() override;
    void setup_connections();
    std::shared_ptr<gui::MainWindow> get_main_window();
private:
    std::shared_ptr<gui::MainWindow> m_screen = nullptr;
    std::shared_ptr<core::ICanvas> m_canvas = nullptr;
};
}

