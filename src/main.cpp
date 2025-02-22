#include "app.hpp"
#include "editor.hpp"
#include "model.hpp"
#include <fstream>
#include "parser.hpp"

int main()
{
    std::ifstream file("../data/graph_6.txt");
    core::App::instance().start(file);
    file.close();
    return 0;
}
