// PluginUKalman.cpp
// Max Worgan (max.worgan@gmail.com)

#include "SC_PlugIn.hpp"
#include "UKalman.hpp"

static InterfaceTable* ft;

namespace UKalman {

UKalman::UKalman() {
    mCalcFunc = make_calc_function<UKalman, &UKalman::next>();
    next(1);
}

void UKalman::next(int nSamples) {
    const float* input = in(0);
    const float* gain = in(1);
    float* outbuf = out(0);

    // simple gain function
    for (int i = 0; i < nSamples; ++i) {
        outbuf[i] = input[i] * gain[i];
    }
}

} // namespace UKalman

PluginLoad(UKalmanUGens) {
    // Plugin magic
    ft = inTable;
    registerUnit<UKalman::UKalman>(ft, "UKalman", false);
}
