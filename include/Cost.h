#pragma once

#include "nr3.h"
#include "Interpolation.h"
#include "Similarity.h"
#include "Deformation.h"

class Cost
{
private:
	NRmatrix<double> referenceImage, imageToScale;
	Similarity *sim;
	Interpolation *interp;

public:
	Cost(NRmatrix<double> Iref,
		 NRmatrix<double> I,
		 Similarity *sim,
		 Interpolation *interp);
	double getCost(const double *theta) const;
	double operator()(const VecDoub &u) const
	{
		double *theta = new double[u.size()];
		for (size_t i = 0; i < u.size(); i++)
		{
			theta[i] = u[i];
		}
		return Cost::getCost(theta);
	} // operator() for NR3 class (optimization)
};
