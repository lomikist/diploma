#include "app.hpp"
#include <fstream>

int main(int argc, char** argv)
{
    auto app = core::App(argc, argv);
     
    return app.exec();
}
