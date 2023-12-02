#pragma once
#include "nr3.h"
#include "Transformation.h"
#include "Interpolation.h"
#include "Interpolation.h"

class Deformation
{
public:
	void getDeformation(const NRmatrix<double> &,
						const double *,
						NRmatrix<bool> &,
						NRmatrix<double> &,
						Interpolation *);
};
