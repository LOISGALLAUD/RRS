#pragma once

#include "nr3.h"

class Interpolation
{
public:
	virtual bool getInterpolation(double x,
								  double y,
								  const NRmatrix<double> &Image,
								  double &val) = 0;
};

class InterpolationDefault : public Interpolation
{
public:
	bool getInterpolation(double x,
						  double y,
						  const NRmatrix<double> &Image,
						  double &val);
};

class InterpolationNN : public Interpolation // Nearest Neighbor
{
public:
	bool getInterpolation(double x,
						  double y,
						  const NRmatrix<double> &Image,
						  double &val);
};
