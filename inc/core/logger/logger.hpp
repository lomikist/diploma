#pragma once

#include "ilogger.hpp"
#include <memory>
#include <vector>

namespace core
{
class Logger
{
public: 
    ~Logger();
    Logger();
    void add_logger(std::shared_ptr<ILogger> new_one);
    void notify_loggers(const std::string& message);
private:
    std::vector<std::shared_ptr<ILogger>> m_loggers;
};
}
