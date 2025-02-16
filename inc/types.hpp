#pragma once 
#include <string>
#include <unordered_map>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>
#include <utility>
#include <vector>

namespace tp
{

constexpr int POPULATION_SIZE   = 200;
constexpr int CELL_WIDTH        = 20;
constexpr int CELL_HEIGHT       = 20;
constexpr int CHROMOSOME_WIDTH  = 20;
constexpr int CHROMOSOME_HEIGHT = 20;

using Graph         = std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>;
using Matrix        = std::vector<std::vector<std::string>>;
using Gene          = std::pair<int, int>;

}
