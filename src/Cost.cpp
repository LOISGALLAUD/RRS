#include "Cost.h"
#include "nr3.h"
#include "Similarity.h"

Cost::Cost(NRmatrix<double> referenceImage, NRmatrix<double> I, Similarity *sim, Interpolation *interp)
{
	this->referenceImage = referenceImage;
	this->imageToScale = I;
	this->similarity = sim;
	this->interpolation = interp;
}

double Cost::getCost(const double *theta) const
{
	// Return the cost of the transformation for the given parameters (theta)
	Deformation deformation;
	NRmatrix<double> deformedImage(imageToScale.nrows(), imageToScale.ncols());
	NRmatrix<bool> binaryImage(imageToScale.nrows(), imageToScale.ncols());
	deformation.getDeformation(imageToScale, theta, binaryImage, deformedImage, interpolation);
	return similarity->getSimilarity(referenceImage, deformedImage, binaryImage);
}