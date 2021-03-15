// PluginUKalman.cpp
// Max Worgan (max.worgan@gmail.com)

#include "SC_PlugIn.hpp"
#include "UKalman.hpp"

static InterfaceTable* ft;

namespace UKalman {

	UKalman::UKalman() {
		const double smoothness = in0(1);
		const double rapidness  = in0(2);
		ukf.init(smoothness, rapidness);
		mCalcFunc = make_calc_function<UKalman, &UKalman::next>();
		next(1);
		count = 0;
	}

	void UKalman::next(int nSamples) {
		const float estimate = ukf.getEstimation();
		const float input    = in0(0);
		ukf.update(input);
		out0(0) = estimate;
	}

} // namespace UKalman

PluginLoad(UKalmanUGens) {
    // Plugin magic
    ft = inTable;
    registerUnit<UKalman::UKalman>(ft, "UKalman", false);
}
