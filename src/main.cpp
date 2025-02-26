#include "app.hpp"
#include <fstream>

int main(int argc, char** argv)
{
    std::ifstream file("../data/graph_6.txt");
    auto app = core::App(argc, argv);
    app.start(file);
    file.close();
    return 0;
}
