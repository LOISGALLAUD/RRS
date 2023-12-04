#pragma once

#include "nr3.h"
#include "Deformation.h"

class Similarity
{
public:
	double getQuadratic(const NRmatrix<double> &,
						const NRmatrix<double> &,
						const NRmatrix<bool> &);

	double getMutualInformation(const NRmatrix<double> &,
								const NRmatrix<double> &,
								const NRmatrix<bool> &);
};
