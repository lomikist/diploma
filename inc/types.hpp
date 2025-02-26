#pragma once 
#include "chromosome.hpp"
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace tp
{

constexpr int POPULATION_SIZE   = 100;
constexpr int CELL_WIDTH        = 20;
constexpr int CELL_HEIGHT       = 20;
constexpr int CHROMOSOME_WIDTH  = 10;
constexpr int CHROMOSOME_HEIGHT = 10;
constexpr int GENERATION_SIZE   = 100; 

using Graph                 = std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>;
using Matrix                = std::vector<std::vector<std::string>>;
using Gene                  = std::pair<int, int>;
using ChromosomePtr         = std::shared_ptr<model::Chromosome>;
using VectorPairChromPtr    = std::vector<std::pair<ChromosomePtr, int>>;
/*using ModelPtr              = std::shared_ptr<model::Model>;     */
/*using IfitnessPtr           = std::shared_ptr<core::Ifitness>;     */
/*using IcrossoverPtr         = std::shared_ptr<core::Icrossover>; */
/*using IselectPtr            = std::shared_ptr<core::Iselect>;      */
}
