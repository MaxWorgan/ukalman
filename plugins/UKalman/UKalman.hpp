// PluginUKalman.hpp
// Max Worgan (max.worgan@gmail.com)

#pragma once

#include "SC_PlugIn.hpp"

namespace UKalman {

class UKalman : public SCUnit {
public:
    UKalman();

    // Destructor
    // ~UKalman();

private:
    // Calc function
    void next(int nSamples);

    // Member variables
};

} // namespace UKalman
