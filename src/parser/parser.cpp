#include <iostream>
#include <istream>
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

