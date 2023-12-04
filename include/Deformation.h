#pragma once
#include "nr3.h"
#include "Transformation.h"
#include "Interpolation.h"
#include "Interpolation.h"

class Deformation
{
public:
	void getDeformation(const NRmatrix<double> &,
						const VecDoub &,
						NRmatrix<bool> &,
						NRmatrix<double> &,
						InterpolationMethod *);
	void greyScale(NRmatrix<double> &);
};
