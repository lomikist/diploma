#include "app.hpp"
#include <fstream>

int main()
{
    std::ifstream file("../data/graph_6.txt");
    core::App::instance().start(file);
    file.close();
    return 0;
}
