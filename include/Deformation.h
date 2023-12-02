#pragma once
#include "nr3.h"
#include "Transformation.h"
#include "Interpolation.h"
#include "Interpolation.h"

class Deformation
{
public:
	void getDeformation(const NRmatrix<double> &image,
						const double *theta,
						NRmatrix<bool> &bonaryImage,
						NRmatrix<double> &deformedImage,
						Interpolation *interpolation);
};
