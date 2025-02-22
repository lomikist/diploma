#include "crossover_two_point.hpp"
#include <iostream>
#include <cassert>

bool test(tp::ChromosomePtr first, tp::ChromosomePtr sec, tp::ChromosomePtr result)
{
    core::CrossoverTwoPoint cross_test;
    auto cross_result = cross_test.crossover(first, sec);
     
    for (int i = 0; i < cross_result->get_cells().size(); i++)
        if (result->get_cells().at(i) != cross_result->get_cells().at(i) 
            || result->get_cells().at(i).get_position() != cross_result->get_cells().at(i).get_position())
            return false;
    return true; 
}


int main (int argc, char *argv[])
{
    const int width = 15;
    const int height = 15;
    
    const std::vector<model::Cell> cells1 = {
        model::Cell("A", 10, 10, 0, 5),
        model::Cell("B", 10, 10, 5, 3),
        model::Cell("C", 10, 10, 2, 4),
        model::Cell("D", 10, 10, 2, 2),
        model::Cell("E", 10, 10, 5, 6),
        model::Cell("F", 10, 10, 7, 7),
        model::Cell("G", 10, 10, 8, 8),
        model::Cell("H", 10, 10, 10, 10),
        model::Cell("I", 10, 10, 12, 12),
        model::Cell("J", 10, 10, 14, 14)
    };
    
    const std::vector<model::Cell> cells2 = {
        model::Cell("A", 10, 10, 0, 2),
        model::Cell("B", 10, 10, 4, 3),
        model::Cell("C", 10, 10, 4, 2),
        model::Cell("D", 10, 10, 1, 3),
        model::Cell("E", 10, 10, 3, 6),
        model::Cell("F", 10, 10, 6, 1),
        model::Cell("G", 10, 10, 7, 4),
        model::Cell("H", 10, 10, 9, 7),
        model::Cell("I", 10, 10, 11, 9),
        model::Cell("J", 10, 10, 13, 11)
    };    

    const std::vector<model::Cell> result = {
        model::Cell("A", 10, 10, 0, 5),
        model::Cell("B", 10, 10, 5, 3),
        model::Cell("C", 10, 10, 2, 4),
        model::Cell("D", 10, 10, 1, 3),
        model::Cell("E", 10, 10, 3, 6),
        model::Cell("F", 10, 10, 6, 1),
        model::Cell("G", 10, 10, 8, 8),
        model::Cell("H", 10, 10, 10, 10),
        model::Cell("I", 10, 10, 12, 12),
        model::Cell("J", 10, 10, 14, 14)
    };

    tp::ChromosomePtr matrix1 = std::make_shared<model::Chromosome>(cells1, width, height);
    tp::ChromosomePtr matrix2 = std::make_shared<model::Chromosome>(cells2, width, height);
    tp::ChromosomePtr result_matrix = std::make_shared<model::Chromosome>(result, width, height);

    assert(test(matrix1, matrix2, result_matrix));
    return 0;
}
