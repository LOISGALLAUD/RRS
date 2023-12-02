#include "Cost.h"
#include "nr3.h"
#include "Similarity.h"

Cost::Cost(NRmatrix<double> referenceImage,
		   NRmatrix<double> imageToScale,
		   Similarity *sim,
		   Interpolation *interp)
{
	this->referenceImage = referenceImage;
	this->imageToScale = imageToScale;
	this->similarity = similarity;
	this->interpolation = interpolation;
}

double Cost::getCost(const double *theta) const
{
	Deformation def;
	NRmatrix<double> deformedImage(imageToScale.nrows(), imageToScale.ncols());
	NRmatrix<bool> binaryImage(imageToScale.nrows(), imageToScale.ncols());
	def.getDeformation(imageToScale, theta, binaryImage, deformedImage, interpolation);

	if (similarity == 0)
	{
		DefaultSimilarity simDef;
		return simDef.getSimilarity(referenceImage, deformedImage, binaryImage);
	}
	else
	{
		return similarity->getSimilarity(referenceImage, deformedImage, binaryImage);
	}
}
