#pragma once

#include "nr3.h"

class Interpolation
{
public:
	virtual bool getInterpolation(double,
								  double,
								  const NRmatrix<double> &,
								  double &);
};

class InterpolationNN : public Interpolation // Nearest Neighbor
{
public:
	bool getInterpolation(double,
						  double,
						  const NRmatrix<double> &,
						  double &);
};
