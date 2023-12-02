#include "Cost.h"
#include "nr3.h"
#include "Similarity.h"

Cost::Cost(NRmatrix<double> Iref, NRmatrix<double> I, Similarity *sim, Interpolation *interp)
{
	this->referenceImage = Iref;
	this->imageToScale = I;
	this->sim = sim;
	this->interp = interp;
}

double Cost::getCost(const double *theta) const
{
	Deformation def;
	NRmatrix<double> Idef(imageToScale.nrows(), imageToScale.ncols());
	NRmatrix<bool> Ibin(imageToScale.nrows(), imageToScale.ncols());
	def.getDeformation(imageToScale, theta, Ibin, Idef, interp);
	if (sim == 0)
	{
		DefaultSimilarity simDef;
		return simDef.getSimilarity(referenceImage, Idef, Ibin);
	}
	else
	{
		return sim->getSimilarity(referenceImage, Idef, Ibin);
	}
}