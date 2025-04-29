#include <fstream>
#include <iostream>
#include <istream>
#include <sstream>
#include <string>
#include "parser.hpp"

tp::Graph cli::Parser::parseGraph(std::istream& file) {
    tp::Graph result;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string node1, node2;
        int weight;

        iss >> node1 >> node2 >> weight;
        result[node1].emplace_back(node2, weight);
        result[node2].emplace_back(node1, weight);
    }
    return result;
}

void cli::Parser::generate_output(const tp::ChromosomePtr& output_crom)
{
    if (!output_crom) {
        std::cerr << "Error: null ChromosomePtr\n";
        return;
    }

    std::ofstream out_file("output.txt");
    if (!out_file.is_open()) {
        std::cerr << "Error: could not open output file\n";
        return;
    }

    const auto& cells = output_crom->get_cells();
    // const auto& used_positions = output_crom->get_used_positions();

    for (const auto& cell : cells) {
        auto pos = cell.get_position();
        out_file << "(" << pos.first << "," << pos.second << "): " 
                 << cell.get_name() << "\n";
    }
    out_file.close();
}

