#include "file_selector.hpp"

gui::FileSelector::FileSelector(QWidget *parent) : QWidget(parent)
{
    auto *layout = new QVBoxLayout(this);
    m_path_edit = new QLineEdit(this);
    m_button = new QPushButton("Select File", this);    

    m_path_edit->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    m_button->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    m_button->setMinimumWidth(250);
    
    layout->addWidget(m_path_edit);
    layout->addWidget(m_button);
    layout->setContentsMargins(2, 2, 2, 2);
    layout->setSpacing(5);

    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    setLayout(layout);
    
    connect(m_button, &QPushButton::clicked, this, &FileSelector::select_file);
}

void gui::FileSelector::select_file()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Select File");
    if (!filePath.isEmpty()) {
        m_path_edit->setText(filePath);
    }
}

QString gui::FileSelector::get_file_path() const
{
    return m_path_edit->text();
}

