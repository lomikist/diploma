#pragma once
#include "cell.hpp"
#include "iselect.hpp"
#include "types.hpp"

namespace core
{
class SelectToHalf : public core::Iselect
{
public:
    virtual tp::VectorPairChromPtr evaluate(std::shared_ptr<Ifitness>, 
                                            std::shared_ptr<Icrossover>,  
                                            tp::Graph, 
                                            tp::VectorPairChromPtr) override;
private:
};
}
