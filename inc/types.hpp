#pragma once 
#include "chromosome.hpp"
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace tp
{

struct RGB
{
    RGB(int r, int g, int b) : _r(r), _g(g), _b(b)
    {};
    int _r;
    int _g;
    int _b;
}; 

constexpr int POPULATION_SIZE   = 100;
constexpr int CELL_WIDTH        = 5;
constexpr int CELL_HEIGHT       = 5;
constexpr int CHROMOSOME_WIDTH  = 20;
constexpr int CHROMOSOME_HEIGHT = 20;
constexpr int GENERATION_SIZE   = 90; 

using Graph                 = std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>;
using Matrix                = std::vector<std::vector<std::string>>;
using Gene                  = std::pair<int, int>;
using ChromosomePtr         = std::shared_ptr<model::Chromosome>;
using VectorPairChromPtr    = std::vector<std::pair<ChromosomePtr, int>>;
}
