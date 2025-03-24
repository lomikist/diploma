#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFileDialog>

namespace gui
{
class FileSelector : public QWidget {
    Q_OBJECT
public:
    explicit FileSelector(QWidget *parent = nullptr);
    QString get_file_path() const; 
private slots:
    void select_file();

private:
    QLineEdit *filePathEdit;
};

}

