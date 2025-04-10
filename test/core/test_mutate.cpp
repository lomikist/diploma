#include "cell.hpp"
#include "chromosome.hpp"
#include "fitness_manhattan.hpp"
#include "mutate_random.hpp"
#include "types.hpp"
#include <cassert>
#include <set>

// Assuming you have these namespaces
using ChromosomePtr = std::shared_ptr<model::Chromosome>;
using VectorPairChromPtr = std::vector<std::pair<ChromosomePtr, int>>;

int main()
{
    const int width = 7;
    const int height = 7;

    // Create initial cells
    std::vector<model::Cell> cells = {
        model::Cell("A", 10, 10, 0, 5),
        model::Cell("B", 10, 10, 5, 3),
        model::Cell("C", 10, 10, 4, 2),
        model::Cell("D", 10, 10, 2, 2),
        model::Cell("E", 10, 10, 5, 6)
    };

    // Create a shared pointer to a chromosome
    ChromosomePtr chrom = std::make_shared<model::Chromosome>(cells, width, height);
    
    // Store initial positions before mutation
    std::set<std::pair<int, int>> initial_positions;
    for (const auto& cell : chrom->get_cells()) {
        initial_positions.insert(cell.get_position());
    }

    VectorPairChromPtr population = { {chrom, 100} };

    core::MutateRandom mutator;

    VectorPairChromPtr mutated_population = mutator.mutate(population);

    ChromosomePtr mutated_chrom = mutated_population[0].first;

    // Store positions after mutation
    std::set<std::pair<int, int>> mutated_positions;
    for (const auto& cell : mutated_chrom->get_cells()) {
        mutated_positions.insert(cell.get_position());
    }

    // Print the results
    std::cout << "Before Mutation:\n";
    for (const auto& pos : initial_positions) {
        std::cout << "(" << pos.first << ", " << pos.second << ") ";
    }
    std::cout << "\nAfter Mutation:\n";
    for (const auto& pos : mutated_positions) {
        std::cout << "(" << pos.first << ", " << pos.second << ") ";
    }
    std::cout << std::endl;

    // **ASSERT: At least one position should have changed**
    assert(initial_positions != mutated_positions && "Mutation failed: No change in positions");

    std::cout << "Mutation test passed!\n";
    return 0;
}

