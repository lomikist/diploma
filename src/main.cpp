#include "editor.hpp"
#include "model.hpp"
#include <fstream>
#include "parser.hpp"

int main() {
    std::ifstream file("../data/graph_6.txt");
    cli::Parser parser; 
    core::Editor editor;   

    model::Model model(parser.parseGraph(file));
    editor.evaluate(model.get_adj_graph(), model.get_population());
    /*model.get_population().print();*/
    return 0;
}
