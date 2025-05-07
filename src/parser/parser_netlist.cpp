#include "parser_netlist.hpp"
        
cli::ParserNetlist::ParserNetlist() {
    // Initialize Yosys
    Yosys::log_quiet = true;
    Yosys::log_hdlname = true;
    Yosys::yosys_setup();
    design = new Yosys::RTLIL::Design;
}
        
cli::ParserNetlist::~ParserNetlist() {
    delete design;
    Yosys::yosys_shutdown();
}
        
tp::Graph cli::ParserNetlist::parseNetlist(const std::string& filename) {
    tp::Graph result;
    
    Yosys::run_pass(stringf("read_verilog %s", filename.c_str()), design);
    
    for (auto module : design->modules()) {
        for (auto cell : module->cells()) {
            std::string cellName = Yosys::RTLIL::id2cstr(cell->name);
            for (auto &conn : cell->connections()) {
                std::string portName = Yosys::RTLIL::id2cstr(conn.first);
                Yosys::RTLIL::SigSpec sig = conn.second;
                for (auto bit : sig.bits()) {
                    if (bit.wire == nullptr) continue;
                    std::string wireName = Yosys::RTLIL::id2cstr(bit.wire->name);
                    int weight = estimateConnectionWeight(cellName, wireName);
                    result[cellName].emplace_back(wireName, weight);
                    result[wireName].emplace_back(cellName, weight);
                }
            }
        }
    }
    return result;
}
        
int cli::ParserNetlist::estimateConnectionWeight(const std::string& node1, const std::string& node2) {
    // You can implement various heuristics here
    // For now, returning a placeholder value
    return 40;
}
        
void cli::ParserNetlist::generate_output(const tp::ChromosomePtr& output_crom) {
    if (!output_crom) {
       std::cerr << "Error: null ChromosomePtr\n";
       return;
    }

    Yosys::RTLIL::Design* outDesign = new Yosys::RTLIL::Design;
    Yosys::RTLIL::Module* module = outDesign->addModule("\\top");
    
    const auto& cells = output_crom->get_cells();
    
    for (const auto& cell : cells) {
        auto pos = cell.get_position();
        std::string cellName = cell.get_name();

        Yosys::RTLIL::Cell* newCell = module->addCell(
            Yosys::RTLIL::IdString(cellName), Yosys::RTLIL::IdString("\\cell"));
        
        newCell->setParam(Yosys::RTLIL::IdString("\\X"), Yosys::RTLIL::Const(pos.first));
        newCell->setParam(Yosys::RTLIL::IdString("\\Y"), Yosys::RTLIL::Const(pos.second));
    }
    Yosys::run_pass(stringf("write_verilog %s", filename.c_str()), outDesign);
    delete outDesign;
}
