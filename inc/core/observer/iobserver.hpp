#pragma once
namespace core 
{
class IObserver 
{
public:
    virtual ~IObserver(){};
    virtual void update() = 0;
};
}
