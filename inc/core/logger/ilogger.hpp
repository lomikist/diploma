#pragma once
#include <string>
namespace core 
{
struct ILogger 
{
    virtual ~ILogger(){};
    virtual void write(const std::string& log) = 0;
};
}
