#pragma once

#include "ilogger.hpp"
#include <ostream>

namespace core
{
class OsLogger : public ILogger
{
public:
    OsLogger(std::ostream* stream);
    ~OsLogger();
    void write(const std::string& log) override;
private:
    std::ostream* m_device = nullptr;
};
}
