#pragma once
#include "cell.hpp"
#include "iselect.hpp"
#include "types.hpp"

namespace core
{
class SelectToHalf : public core::Iselect
{
public:
    virtual tp::VectorPairChromPtr cross_select(    std::shared_ptr<Ifitness>, 
                                                    std::shared_ptr<Icrossover>,  
                                                    const tp::Graph&,
                                                    tp::VectorPairChromPtr) override;
private:
};
}
