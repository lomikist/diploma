#include "oslogger.hpp"
#include <iostream>
#include <ostream>

using namespace core;


OsLogger::OsLogger(std::ostream* stream)
{
    m_device = stream;
};

OsLogger::~OsLogger()
{
};

void OsLogger::write(const std::string& log)
{
    *m_device << log << "\n";
    m_device->flush();
}
