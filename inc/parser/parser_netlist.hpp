#pragma once
#include "iparser.hpp"
#include <string>
#include <memory>

namespace cli 
{
class ParserNetlist : public IParser
{
public:
    tp::Graph parseGraph(std::istream& file) override; 
    void generate_output(const tp::ChromosomePtr& output_crom) override;
    int estimateConnectionWeight(const std::string& node1, const std::string& node2);
    ParserNetlist();
    ~ParserNetlist();
private:
    std::string createTempFile(std::istream& input);
    std::string runYosysCommand(const std::string& command);
    tp::Graph parseYosysOutput(const std::string& output);
};
}
