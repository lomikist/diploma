#pragma once
#include "iparser.hpp"
namespace cli 
{
class ParserNetlist : public IParser
{
public:
    tp::Graph parseGraph(std::istream& file) override; 
    void generate_output(const tp::ChromosomePtr& output_crom) override;
    ParserNetlist();
private:
    Yosys::RTLIL::Design* design;
};
}

