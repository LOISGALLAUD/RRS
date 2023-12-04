#include "Cost.h"
#include "nr3.h"
#include "Similarity.h"

Cost::Cost(NRmatrix<double> I, NRmatrix<double> referenceImage, Similarity *sim, InterpolationMethod *interp)
{
	this->referenceImage = referenceImage;
	this->imageToScale = I;
	this->similarity = sim;
	this->interpolation = interp;
}

double Cost::getCost(const VecDoub &theta) const
{
	// Return the cost of the transformation for the given parameters (theta)
	Deformation deformation;
	NRmatrix<double> deformedImage(imageToScale.nrows(), imageToScale.ncols());
	NRmatrix<bool> binaryImage(imageToScale.nrows(), imageToScale.ncols());
	deformation.getDeformation(imageToScale, theta, binaryImage, deformedImage, interpolation);
	return similarity->getSimilarity(deformedImage, referenceImage, binaryImage);
}