#include "logger.hpp"

using namespace core; 

Logger::Logger()
{};

Logger::~Logger()
{};

void Logger::add_logger(std::shared_ptr<ILogger> new_logger)
{
    m_loggers.push_back(new_logger);
};

void Logger::notify_loggers(const std::string& message)
{
    for (auto&& logger : m_loggers)
    {
        logger->write(message);
    }
};
