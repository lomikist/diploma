#include "guilogger.hpp"
#include "qtextbrowser.h"

using namespace core;

GuiLogger::GuiLogger(QTextBrowser* device)
{
    m_device = device;
};

GuiLogger::~GuiLogger()
{
}

void GuiLogger::write(const std::string& message)
{
    m_device->append(QString::fromStdString(message));
}

