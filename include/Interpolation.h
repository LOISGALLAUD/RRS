#pragma once

#include "nr3.h"

class InterpolationMethod
{
public:
	virtual bool getInterpolation(double,
								  double,
								  const NRmatrix<double> &,
								  double &) = 0;
};
class Interpolation : public InterpolationMethod
{
public:
	virtual bool getInterpolation(double,
								  double,
								  const NRmatrix<double> &,
								  double &);
};

class InterpolationNN : public InterpolationMethod // Nearest neighbor interpolation
{
public:
	bool getInterpolation(double,
						  double,
						  const NRmatrix<double> &,
						  double &);
};
