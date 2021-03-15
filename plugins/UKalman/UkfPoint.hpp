#pragma once

#include "UKF.h"

class UkfPoint1d : public UKF<double> {
	math::matrix<double> x;
public:
	void init(double smoothness = 0.1, double rapidness = 0.1); // smaller is more smooth/rapid
	void update(const double);
	double getEstimation();
	double getVelocity();

	math::matrix<double> state_function(math::matrix<double>&);
	math::matrix<double> measurement_function(math::matrix<double>&);
};
