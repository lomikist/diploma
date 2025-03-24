#include "cell.hpp"
#include "chromosome.hpp"
#include "fitness_manhattan.hpp"
#include "types.hpp"
#include <cassert>

int main()
{
    const int width = 7;
    const int height = 7;

    std::vector<model::Cell> cells = {
        model::Cell("A", 10, 10, 0, 5),
        model::Cell("B", 10, 10, 5, 3),
        model::Cell("C", 10, 10, 4, 2),
        model::Cell("D", 10, 10, 2, 2),
        model::Cell("E", 10, 10, 5, 6)
    };

    const tp::Graph graph4 = {
        {"A", {{"B", 14}, {"C", 23}, {"D", 22}, {"E", 36}}},
        {"B", {{"A", 14}, {"C", 13}, {"D", 34}, {"E", 33}}},
        {"C", {{"A", 23}, {"B", 13}, {"D", 41}, {"E", 27}}},
        {"D", {{"A", 22}, {"B", 34}, {"C", 41}, {"E", 35}}},
        {"E", {{"A", 36}, {"B", 33}, {"C", 27}, {"D", 35}}}
    };

    tp::ChromosomePtr matrix= std::make_shared<model::Chromosome>(cells, width, height);

     
    /*assert(fitness_check.calc_fitness(graph4, matrix) == 2616) ;*/
};

