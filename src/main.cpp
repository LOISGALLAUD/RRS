#include "ImageScaler.h"
#include "Deformation.h"
#include "Interpolation.h"

#define IMAGE_TO_SCALE "floating.pgm"
#define REFERENCE_IMAGE "reference.pgm"
#define NN_DEFORMED "NNdeformed.pgm"

int main()
{
	ImageScaler imageScaler;
	std::string imageToScale = IMAGE_TO_SCALE;
	std::string referenceImage = REFERENCE_IMAGE;
	std::string NNdeformed = NN_DEFORMED;
	InterpolationNN interp;
	VecDoub theta_max;

	std::cout << "Result with basic bilinear interpolation method:" << std::endl;
	theta_max = imageScaler.getThetaMax(imageToScale, referenceImage);

	std::cout << "Result with nearest neighbor method:" << std::endl;
	theta_max = imageScaler.getThetaMax(imageToScale, referenceImage, NNdeformed, 0, &interp);

	return 0;
}