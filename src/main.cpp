#include <stdio.h>
#include <string>
#include "ImageScaler.h"
#include "Deformation.h"
#include "Interpolation.h"

int main()
{

	ImageScaler imageScaler;
	std::string imageToScale = "floating.pgm", referenceImage = "reference.pgm", NNdeformed = "NNdeformed.pgm";
	InterpolationNN interp;

	std::cout << "Interpolation aux plus proches voisins:" << std::endl;

	VecDoub u = imageScaler.getThetaMax(imageToScale, referenceImage, NNdeformed, 0, &interp);

	std::cout << "Interpolation" << std::endl;

	u = imageScaler.getThetaMax(imageToScale, referenceImage);

	return 0;
}