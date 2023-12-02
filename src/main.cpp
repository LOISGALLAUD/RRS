#include "ImageScaler.h"
#include "Deformation.h"

#define IMAGE_TO_SCALE "floating.pgm"
#define REFERENCE_IMAGE "reference.pgm"

int main()
{
	ImageScaler imageScaler(IMAGE_TO_SCALE, REFERENCE_IMAGE);
	VecDoub theta_max;
	InterpolationMethod *interpolation = new Interpolation();
	InterpolationMethod *interpolationNN = new InterpolationNN();

	std::cout << "Result with basic bilinear interpolation method:" << std::endl;
	theta_max = imageScaler.getThetaMax(interpolation);

	std::cout << "\n---------------------------------------------------\n"
			  << std::endl;

	std::cout << "Result with nearest neighbor method:" << std::endl;
	theta_max = imageScaler.getThetaMax(interpolationNN);

	delete interpolation;
	delete interpolationNN;

	return 0;
}