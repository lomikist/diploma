#pragma once
#include "icanvas.hpp"
#include "iobserver.hpp"
#include "main_window.hpp"
#include <memory>
namespace gui 
{
constexpr int PAREA_HEIGHT = 900;
constexpr int PAREA_WIDTH = 900;
constexpr int MARGINE = 20;
constexpr int CELL_SPACE = 5; 

class GuiController : public QObject, public core::IObserver
{
    Q_OBJECT
public: 
    GuiController();
    void update() override;
    void setup_connections();
    std::shared_ptr<gui::MainWindow> get_main_window() const;
private:
    void draw_cells(int screenWidth, 
                    int screenHeight, 
                    int chromosomeWidth,  
                    int chromosomeHeight
    );
    void draw_grid( int screenWidth,
                    int screenHeight, 
                    int chromosomeWidth,
                    int chromosomeHeight,
                    tp::RGB gridLineColor = {0, 214, 211}
    );

    void draw_weight_line();

    void on_canvas_clicked(QPoint pos);
    std::shared_ptr<gui::MainWindow> m_screen = nullptr;
    std::shared_ptr<core::ICanvas> m_canvas = nullptr;

    // vizualization
    int m_selectedRow = -1;
    int m_selectedCol = -1;
};
}

