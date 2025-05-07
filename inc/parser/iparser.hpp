#pragma once
#include "types.hpp"
namespace cli 
{
class IParser 
{
public:
    virtual tp::Graph parseGraph(std::istream& file) = 0; 
    virtual void generate_output(const tp::ChromosomePtr& output_crom) = 0;
    virtual ~IParser(){};
};
}
