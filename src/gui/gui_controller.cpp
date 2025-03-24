#include "gui_controller.hpp"
#include "app.hpp"
#include "gui_wrapper.hpp"
#include "types.hpp"
#include <memory>
#include <QObject>

gui::GuiController::GuiController()
{
    m_screen = std::make_shared<gui::MainWindow>(nullptr);
    m_canvas = std::make_shared<core::GuiPainterWrapper>(m_screen->get_paint_area()->get_painter());

    setup_connections();
    m_screen->show();
}

void gui::GuiController::update()
{
    auto data = core::App::instance()->get_model(); 
    auto chrom = data->get_population().get_chromosome(0);
    auto cells = chrom.first->get_cells();

    m_screen->get_paint_area()->clear();

    for (auto&& cell : cells)
    {
        auto pos = cell.get_position();
        auto size = cell.get_size();

        m_canvas->draw_rect(pos.first * size.first * 10, 
                            pos.second * size.second * 10, 
                            size.first * 10, 
                            size.second * 10, 
                            {198,198,198}, 
                            {198,198,198}
        );
        m_canvas->draw_text(pos.first * size.first * 10 + (size.first * 10/ 2),
                            pos.second * size.second * 10 + (size.second * 10/ 2), 
                            size.first * 10, 
                            size.second * 10, 
                            {10, 10, 10}, 
                            {10, 10, 10},
                            cell.get_name() 
        ); 
    }

    m_screen->get_paint_area()->update();
}

void gui::GuiController::setup_connections()
{
    connect(m_screen->get_btn_start(), &QPushButton::clicked, core::App::instance(), &core::App::start);
}

std::shared_ptr<gui::MainWindow> gui::GuiController::get_main_window()
{
    return m_screen;
};


