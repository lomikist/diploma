#include "gui_controller.hpp"
#include "app.hpp"
#include "gui_wrapper.hpp"
#include "types.hpp"
#include <algorithm>
#include <memory>
#include <QObject>
#include <string>

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
    draw_weight_line();
    m_screen->get_paint_area()->update();
}

//vizualization
void gui::GuiController::draw_cells(
            int screenWidth, 
            int screenHeight, 
            int chromosomeWidth,  
            int chromosomeHeight
)
{
    auto data = core::App::instance()->get_model(); 
    auto chrom = data->get_population().get_chromosome(0);
    auto cells = chrom.first->get_cells();
    tp::RGB color{0, 0, 0};

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
        
        if (pos.first == m_selectedCol && pos.second == m_selectedRow)
        {
            color = {255, 0, 0};
        } else{ 
            color = {198,198,198};
        }
        m_canvas->draw_rect(
                            x, 
                            y,
                            cellWidth,
                            cellHeight, 
                            color, 
                            color 
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
    connect(m_screen->get_paint_area(), &gui::PaintArea::clicked, this, &gui::GuiController::on_canvas_clicked);
}

std::shared_ptr<gui::MainWindow> gui::GuiController::get_main_window() const
{
    return m_screen;
};

// vizualization
void gui::GuiController::on_canvas_clicked( QPoint pos )
{
    int availableWidth = PAREA_WIDTH - 2 * gui::MARGINE;
    int availableHeight = PAREA_HEIGHT - 2 * gui::MARGINE;
    int cellWidth = (availableWidth - (tp::CHROMOSOME_WIDTH - 1) * gui::CELL_SPACE) / tp::CHROMOSOME_WIDTH;
    int cellHeight = (availableHeight - (tp::CHROMOSOME_HEIGHT - 1) * gui::CELL_SPACE) / tp::CHROMOSOME_HEIGHT;

    auto data = core::App::instance()->get_model(); 
    auto chrom = data->get_population().get_chromosome(0);
    auto cells = chrom.first->get_cells();

    int initial_x = m_selectedCol; 
    int initial_y = m_selectedRow; 
    
    m_selectedCol = (pos.x() - gui::MARGINE) / (gui::CELL_SPACE + cellWidth);
    m_selectedRow = (pos.y() - gui::MARGINE) / (gui::CELL_SPACE + cellHeight);
    
    bool flag = false;
    for (auto cell : cells) {
        if (m_selectedCol == cell.get_position().first &&  m_selectedRow == cell.get_position().second) {
            flag = true;
        }
    }
    if (!flag){
        m_selectedCol = initial_x;
        m_selectedRow = initial_y;
    }
    
    update();
}

// vizualization
void gui::GuiController::draw_weight_line()
{
    int availableWidth = PAREA_WIDTH - 2 * gui::MARGINE;
    int availableHeight = PAREA_HEIGHT - 2 * gui::MARGINE;
    int cellWidth = (availableWidth - (tp::CHROMOSOME_WIDTH - 1) * gui::CELL_SPACE) / tp::CHROMOSOME_WIDTH;
    int cellHeight = (availableHeight - (tp::CHROMOSOME_HEIGHT - 1) * gui::CELL_SPACE) / tp::CHROMOSOME_HEIGHT;

    auto data = core::App::instance()->get_model(); 
    auto chrom = data->get_population().get_chromosome(0);
    auto cells = chrom.first->get_cells();
    
    int midX = 0;
    int midY = 0;
    int weight = 0;
        
    auto selected_name = chrom.first->get_cell_by_pos({m_selectedCol, m_selectedRow}).get_name();
    for (auto cell : cells) {
        auto pos = cell.get_position();
        if ( pos.first != m_selectedCol || pos.second != m_selectedRow ){
            m_canvas->draw_line(
                    (pos.first + 1) * (gui::CELL_SPACE + cellWidth),
                    (pos.second + 1)* (gui::CELL_SPACE + cellHeight),
                    (m_selectedCol + 1) * (gui::CELL_SPACE + cellWidth),
                    (m_selectedRow + 1)* (gui::CELL_SPACE + cellHeight),
                    {255,0,0}, 
                    {255,0,0}
            );
            int midX = (
                (pos.first + 1) * (gui::CELL_SPACE + cellWidth) +
                (m_selectedCol + 1) * (gui::CELL_SPACE + cellWidth)
            ) / 2;
            int midY = (
                (pos.second + 1)* (gui::CELL_SPACE + cellHeight) + 
                (m_selectedRow + 1)* (gui::CELL_SPACE + cellHeight)
            ) / 2;
            
            m_canvas->draw_text(
                midX, 
                midY,
                0, 
                0, 
                {255, 0, 0}, 
                {255, 0, 0},
                std::to_string(data->get_weight(cell.get_name(), selected_name))  
            );
        }
    } 
}

