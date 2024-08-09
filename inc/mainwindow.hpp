#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "../inc/board.hpp"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void change_position();

private:
    Ui::MainWindow *ui;
    Board *_my_board;
};
#endif // MAINWINDOW_HPP
