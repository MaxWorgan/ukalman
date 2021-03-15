// PluginUKalman.hpp
// Max Worgan (max.worgan@gmail.com)

#pragma once

#include "SC_PlugIn.hpp"
#include "UkfPoint.hpp"

namespace UKalman {

class UKalman : public SCUnit {
public:
    UKalman();
    UkfPoint1d ukf; 

    // Destructor
    // ~UKalman();

private:
    // Calc function
    void next(int nSamples);
    int count;

    // Member variables
};

} // namespace UKalman
