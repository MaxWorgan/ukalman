/*
 https://github.com/micuat/ofxUkf
 
 Naoto Hieda <micuat@gmail.com> 2014
 */

#include "UkfPoint.hpp"

using namespace math;

#define D 1

void UkfPoint1d::init(double smoothness, double rapidness) {
	UKF<double>::n = D * 2;
	UKF<double>::m = D;
	
	matrix<double> In(UKF<double>::n, UKF<double>::n); // nxn Identity Matrix
	for( int i = 0; i < UKF<double>::n; i++ ) {
		In(i, i) = 1;
	}
	matrix<double> Im(UKF<double>::m, UKF<double>::m); // mxm Identity Matrix
	for( int i = 0; i < UKF<double>::m; i++ ) {
		Im(i, i) = 1;
	}
	
	const double q = smoothness; //std of process. "smoothness". lower the value, smoother the curve
	const double r = rapidness; //std of measurement. "tracking". lower the value, faster the track
	UKF<double>::P = In; // state covariance
	UKF<double>::Q = (q * q) * In; // covariance of process	(size must be nxn)
	UKF<double>::R = (r * r) * Im; // covariance of measurement (size must be mxm)
	
	x = math::matrix<double>(UKF<double>::n, 1);
}

void UkfPoint1d::update(const double p) {
	matrix<double> z(1, 1);
	// copy p to z
	z(0, 0) = p;
	UKF<double>::ukf(x, z);
}

double UkfPoint1d::getEstimation()
{
	matrix<double> w = measurement_function(x);
	double p = 0;
	// copy w to p
	p = w(0, 0);
	return p;
}

double UkfPoint1d::getVelocity()
{
	matrix<double> w = measurement_function(x);
	double v = 0;
	// copy w to v
	v = w(0 + 1, 0);
	return v;
}

matrix<double> UkfPoint1d::state_function(matrix<double>& s)
{
	matrix<double> state(UKF<double>::n, 1);
	// position
	for( int i = 0; i < D; i++ ) {
		state(i, 0) = s(i, 0) + s(i + D, 0);
	}
	// velocity
	for( int i = 0; i < D; i++ ) {
		state(i + D, 0) = s(i + D, 0);
	}
	return state;
}

matrix<double> UkfPoint1d::measurement_function(matrix<double>& m)
{
	matrix<double> measurement(1, 1);
	measurement = m;
	return measurement;
}

