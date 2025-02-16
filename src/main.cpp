#include "model.hpp"
#include <fstream>
#include <iostream>
#include "parser.hpp"
#include "types.hpp"

int main() {
    std::ifstream file("../data/graph_6.txt");
    cli::Parser parser; 

    model::Model model(parser.parseGraph(file));

    /*model.get_population().print();*/
    return 0;
}
