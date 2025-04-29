#pragma once
#include "types.hpp"
namespace cli 
{
class Parser 
{
public:
    tp::Graph parseGraph(std::istream& file); 
    void generate_output(const tp::ChromosomePtr& output_crom);
private:

};
}
