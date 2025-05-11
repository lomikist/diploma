#include "parser_netlist.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <boost/json.hpp>
#include <cstdio>
#include <array>
#include <memory>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <random>

namespace cli {

// Helper function to execute a command and get its output
std::string exec(const std::string& cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

ParserNetlist::ParserNetlist() {}

ParserNetlist::~ParserNetlist() {}

std::string ParserNetlist::createTempFile(std::istream& input) {
    // Generate a random filename to avoid collisions
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(10000, 99999);
    std::string temp_filename = "/tmp/temp_verilog_" + std::to_string(distrib(gen)) + ".v";
    
    // Read the input stream and write to the temporary file
    std::ofstream temp_file(temp_filename);
    if (!temp_file) {
        throw std::runtime_error("Failed to create temporary file: " + temp_filename);
    }
    
    temp_file << input.rdbuf();
    temp_file.close();
    
    return temp_filename;
}

std::string ParserNetlist::runYosysCommand(const std::string& command) {
    // Path to your Yosys binary in the third_party folder
    std::string yosys_path = "../third_party/yosys/yosys";
    
    // Create a script file for Yosys to execute
    std::string script_filename = "/tmp/yosys_script_" + std::to_string(std::rand()) + ".ys";
    std::ofstream script_file(script_filename);
    if (!script_file) {
        throw std::runtime_error("Failed to create Yosys script file");
    }
    
    script_file << command << std::endl;
    script_file.close();
    
    // Execute Yosys with the script
    std::string result = exec(yosys_path + " -q -s " + script_filename);
    
    // Clean up the script file
    std::remove(script_filename.c_str());
    
    return result;
}

tp::Graph ParserNetlist::parseYosysOutput(const std::string& output) {
    tp::Graph result;
    
    // Parse the output from Yosys to extract connectivity information
    // This is a simplified example; you'll need to adapt it based on your output format
    std::istringstream iss(output);
    std::string line;
    
    // Parse connectivity information from Yosys output
    // This is just a placeholder - you'll need to implement proper parsing logic
    while (std::getline(iss, line)) {
        // Example parsing logic
        // Parse lines that contain connection information
        if (line.find("Connection: ") != std::string::npos) {
            size_t pos = line.find("Connection: ");
            std::string connection_info = line.substr(pos + 12);
            
            // Extract cell and wire names
            size_t delimiter_pos = connection_info.find(" -> ");
            if (delimiter_pos != std::string::npos) {
                std::string cellName = connection_info.substr(0, delimiter_pos);
                std::string wireName = connection_info.substr(delimiter_pos + 4);
                
                // Calculate weight
                int weight = estimateConnectionWeight(cellName, wireName);
                
                // Add to graph
                result[cellName].emplace_back(wireName, weight);
                result[wireName].emplace_back(cellName, weight);
            }
        }
    }
    
    return result;
}
tp::Graph ParserNetlist::parseGraph(std::istream& file) {
    // Create a temporary file from the input stream
    std::string temp_filename = createTempFile(file);
    
    // Create a Yosys script to analyze the netlist and output connectivity information
    std::string json_output = "/tmp/netlist_" + std::to_string(std::rand()) + ".json";
    std::string command = "read_verilog " + temp_filename + "; ";
    command += "proc; opt; ";
    command += "write_json " + json_output;
    
    // Run Yosys
    try {
        runYosysCommand(command);
    } catch (const std::exception& e) {
        std::cerr << "Error running Yosys command: " << e.what() << std::endl;
        std::remove(temp_filename.c_str());
        return tp::Graph(); // Return empty graph
    }
    
    // Read the JSON output file
    std::ifstream json_file(json_output);
    
    // Check if file opened successfully
    if (!json_file.is_open()) {
        std::cerr << "Error: Failed to open JSON output file: " << json_output << std::endl;
        // Clean up the temporary Verilog file
        std::remove(temp_filename.c_str());
        return tp::Graph(); // Return empty graph
    }
    
    std::string json_content((std::istreambuf_iterator<char>(json_file)),
                            std::istreambuf_iterator<char>());
    json_file.close();
    
    // Check if the JSON content is empty
    if (json_content.empty()) {
        std::cerr << "Error: JSON output file is empty: " << json_output << std::endl;
        // Clean up temporary files
        std::remove(temp_filename.c_str());
        std::remove(json_output.c_str());
        return tp::Graph(); // Return empty graph
    }
    
    // Clean up temporary files
    std::remove(temp_filename.c_str());
    std::remove(json_output.c_str());
    
    // Parse the JSON using Boost.JSON
    tp::Graph result;
    try {
        namespace json = boost::json;
        
        // Parse the JSON string into a value
        json::value parsed_json = json::parse(json_content);
        
        // Get the root object
        json::object const& root = parsed_json.as_object();
        
        // Access the "modules" object
        if (root.contains("modules")) {
            const json::object& modules = root.at("modules").as_object();
            
            // Iterate through each module
            for (const auto& [module_name, module_value] : modules) {
                const json::object& module = module_value.as_object();
                
                // Access the "cells" object if it exists
                if (module.contains("cells")) {
                    const json::object& cells = module.at("cells").as_object();
                    
                    // Iterate through each cell
                    for (const auto& [cell_name, cell_value] : cells) {
                        const json::object& cell = cell_value.as_object();
                        
                        // Access the "connections" object if it exists
                        if (cell.contains("connections")) {
                            try {
                                const json::object& connections = cell.at("connections").as_object();
                                
                                // Iterate through each connection
                                for (const auto& [port_name, connection_value] : connections) {
                                    // Check if the connection value is the expected type (an array)
                                    if (!connection_value.is_array()) {
                                        std::cerr << "Warning: Expected array for connection but got " 
                                                  << connection_value.kind() << " for cell " 
                                                  << cell_name << ", port " << port_name << std::endl;
                                        continue;
                                    }
                                    
                                    const json::array& wire_refs = connection_value.as_array();
                                    
                                    // Process each wire reference in the array
                                    for (const auto& wire_ref : wire_refs) {
                                        try {
                                            // Each wire reference might be an array with two elements
                                            if (wire_ref.is_array()) {
                                                const json::array& wire_data = wire_ref.as_array();
                                                if (wire_data.size() > 0 && wire_data[0].is_string()) {
                                                    std::string wire_name = wire_data[0].as_string().c_str();
                                                    
                                                    // Create a connection with an estimated weight
                                                    int weight = estimateConnectionWeight(cell_name, wire_name);
                                                    result[cell_name].emplace_back(wire_name, weight);
                                                    result[wire_name].emplace_back(cell_name, weight);
                                                }
                                            } else if (wire_ref.is_string()) {
                                                // Handle case where wire reference might be a direct string
                                                std::string wire_name = wire_ref.as_string().c_str();
                                                
                                                int weight = estimateConnectionWeight(cell_name, wire_name);
                                                result[cell_name].emplace_back(wire_name, weight);
                                                result[wire_name].emplace_back(cell_name, weight);
                                            }
                                        } catch (const std::exception& e) {
                                            std::cerr << "Warning: Error processing wire reference: " 
                                                      << e.what() << std::endl;
                                        }
                                    }
                                }
                            } catch (const std::exception& e) {
                                std::cerr << "Warning: Error processing connections for cell " 
                                          << cell_name << ": " << e.what() << std::endl;
                            }
                        }
                    }
                }
                
                // Access the "netnames" object if it exists for additional connectivity
                if (module.contains("netnames")) {
                    const json::object& netnames = module.at("netnames").as_object();
                    
                    // Process netnames if needed for your graph representation
                    // This section depends on how you want to represent nets in your graph
                }
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error parsing JSON: " << e.what() << std::endl;
        // You might want to handle the error differently
    }
    
    return result;
}
int ParserNetlist::estimateConnectionWeight(const std::string& node1, const std::string& node2) {
    //TODO change it to get from another file 
    return 40;
}

void ParserNetlist::generate_output(const tp::ChromosomePtr& output_crom) {
    if (!output_crom) {
        std::cerr << "Error: null ChromosomePtr\n";
        return;
    }
    
    // Create a temporary Verilog file to output the placement
    std::string temp_output = "/tmp/output_" + std::to_string(std::rand()) + ".v";
    std::ofstream output_file(temp_output);
    
    if (!output_file) {
        std::cerr << "Error: Could not create output file\n";
        return;
    }
    
    // Write a Verilog module with the cell placements
    output_file << "module top();\n";
    
    const auto& cells = output_crom->get_cells();
    
    for (const auto& cell : cells) {
        auto pos = cell.get_position();
        std::string cellName = cell.get_name();
        
        // Add placement information as comments or parameters
        output_file << "  // Cell: " << cellName << " at position (" 
                   << pos.first << ", " << pos.second << ")\n";
        output_file << "  cell " << cellName << " ();\n";
    }
    
    output_file << "endmodule\n";
    output_file.close();
    
    // Use Yosys to process the output file
    std::string command = "read_verilog " + temp_output + "; ";
    command += "write_verilog output.netlis";
    
    runYosysCommand(command);
    
    // Clean up temporary file
    std::remove(temp_output.c_str());
}

} // namespace cli
