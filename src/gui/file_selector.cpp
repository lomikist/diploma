#include "file_selector.hpp"

gui::FileSelector::FileSelector(QWidget *parent) : QWidget(parent) {
    auto *layout = new QVBoxLayout(this);
    filePathEdit = new QLineEdit(this);
    auto *button = new QPushButton("Select File", this);    

    filePathEdit->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    button->setMaximumWidth(100);
    
    layout->addWidget(filePathEdit);
    layout->addWidget(button);
    layout->setContentsMargins(2, 2, 2, 2);
    layout->setSpacing(2);

    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    setLayout(layout);
    
    connect(button, &QPushButton::clicked, this, &FileSelector::select_file);
}

void gui::FileSelector::select_file() {
    QString filePath = QFileDialog::getOpenFileName(this, "Select File");
    if (!filePath.isEmpty()) {
        filePathEdit->setText(filePath);
    }
}

QString gui::FileSelector::get_file_path() const {
    return filePathEdit->text();
}
