#pragma once

#include "nr3.h"
#include "Interpolation.h"
#include "Similarity.h"
#include "Deformation.h"

class Cost
{
private:
	NRmatrix<double> referenceImage, imageToScale;
	Similarity *similarity;
	InterpolationMethod *interpolation;

public:
	Cost(NRmatrix<double>,
		 NRmatrix<double>,
		 Similarity *,
		 InterpolationMethod *);
	double getCost(const VecDoub &) const;
	Doub operator()(const VecDoub &u) const
	{
		return getCost(u);
	}
};
