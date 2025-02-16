#pragma once
#include "icrossover.hpp"
#include "ifitness.hpp"
namespace core 
{
class Editor 
{
public:
    Editor();
    void evaluate();
private:
    // it's should be linked not with indexes but with pointer change it later 
    std::vector<int>                    m_fitness_vals; 
    std::unique_ptr<core::Ifitness>     m_fitness;
    std::unique_ptr<core::Icrossover>   m_crossover;
};
}
