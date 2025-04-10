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

    draw_grid(PAREA_WIDTH, PAREA_HEIGHT, tp::CHROMOSOME_WIDTH, tp::CHROMOSOME_HEIGHT);

    setup_connections();
    m_screen->show();
}


// vizualization
void gui::GuiController::update()
{
    m_screen->get_paint_area()->clear();
    draw_grid(PAREA_WIDTH, PAREA_HEIGHT, tp::CHROMOSOME_WIDTH, tp::CHROMOSOME_HEIGHT);
    draw_cells(PAREA_WIDTH, PAREA_HEIGHT, tp::CHROMOSOME_WIDTH, tp::CHROMOSOME_HEIGHT);
    m_screen->get_paint_area()->update();
}

//vizualization 

void gui::GuiController::draw_cells(
            int screenWidth, 
            int screenHeight, 
            int chromosomeWidth,  
            int chromosomeHeight)
{
    auto data = core::App::instance()->get_model(); 
    auto chrom = data->get_population().get_chromosome(0);
    auto cells = chrom.first->get_cells();

    int availableWidth = screenWidth - 2 * gui::MARGINE;
    int availableHeight = screenHeight - 2 * gui::MARGINE;

    int cellWidth = (availableWidth - (chromosomeWidth - 1) * gui::CELL_SPACE) / chromosomeWidth;
    int cellHeight = (availableHeight - (chromosomeHeight - 1) * gui::CELL_SPACE) / chromosomeHeight;

    for (auto&& cell : cells)
    {
        auto pos = cell.get_position();
        auto size = cell.get_size();

        int x = gui::MARGINE + pos.first * (cellWidth + gui::CELL_SPACE);
        int y = gui::MARGINE + pos.second * (cellHeight + gui::CELL_SPACE);

        m_canvas->draw_rect(
                            x, 
                            y,
                            cellWidth,
                            cellHeight, 
                            {198,198,198}, 
                            {198,198,198}
        );
        m_canvas->draw_text(
                            x + cellWidth / 2,
                            y + cellHeight / 2, 
                            cellWidth, 
                            cellHeight,
                            {10, 10, 10},
                            {10, 10, 10},
                            cell.get_name()
        ); 
    }
}


//vizualization 
void gui::GuiController::draw_grid(
            int screenWidth, 
            int screenHeight, 
            int chromosomeWidth,  
            int chromosomeHeight, 
            tp::RGB gridLineColor)
{
    int availableWidth = screenWidth - 2 * gui::MARGINE;
    int availableHeight = screenHeight - 2 * gui::MARGINE;

    int cellWidth = (availableWidth - (chromosomeWidth - 1) * gui::CELL_SPACE) / chromosomeWidth;
    int cellHeight = (availableHeight - (chromosomeHeight - 1) * gui::CELL_SPACE) / chromosomeHeight;

    for (int row = 0; row < chromosomeHeight; ++row) {
        for (int col = 0; col < chromosomeWidth; ++col) {
            int x = gui::MARGINE + col * (cellWidth + gui::CELL_SPACE);
            int y = gui::MARGINE + row * (cellHeight + gui::CELL_SPACE);
            m_canvas->draw_rect(x, y, cellWidth, cellHeight, gridLineColor, gridLineColor);
        }
    }
}

void gui::GuiController::setup_connections()
{
    connect(m_screen->get_btn_start(), &QPushButton::clicked, core::App::instance(), &core::App::start);
}

std::shared_ptr<gui::MainWindow> gui::GuiController::get_main_window() const
{
    return m_screen;
};


