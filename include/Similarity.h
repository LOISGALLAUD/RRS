#pragma once

#include "nr3.h"
#include "Deformation.h"

class Similarity
{
public:
	double getSimilarity(const NRmatrix<double> &,
						 const NRmatrix<double> &,
						 const NRmatrix<bool> &);
};
