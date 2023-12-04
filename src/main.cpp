#include "RigidRescaler.h"
#include "Deformation.h"

#define IMAGE_TO_SCALE "floating.pgm"
#define REFERENCE_IMAGE "reference.pgm"
#define SAVING_PATH "deformed.pgm"

void showThetaMax(VecDoub theta_max)
{
	std::cout << "theta_max = [";
	for (size_t i = 0; i < theta_max.size(); i++)
	{
		std::cout << theta_max[i] << ", ";
	}
	std::cout << "]" << std::endl;
}

int main()
{
	RigidRescaler rigidRescaler(IMAGE_TO_SCALE, REFERENCE_IMAGE);
	VecDoub theta_max;
	InterpolationMethod *interpolation = new Interpolation();
	InterpolationMethod *interpolationNN = new InterpolationNN();

	std::cout << "Result with basic bilinear interpolation method:" << std::endl;
	theta_max = rigidRescaler.getThetaMax(interpolation, SAVING_PATH);
	showThetaMax(theta_max);
	rigidRescaler.applyDeformation(theta_max, interpolation, SAVING_PATH);

	std::cout << "\n---------------------------------------------------\n"
			  << std::endl;

	// std::cout << "Result with nearest neighbor method:" << std::endl;
	// theta_max = rigidRescaler.getThetaMax(interpolationNN, SAVING_PATH);
	// showThetaMax(theta_max);
	// rigidRescaler.applyDeformation(theta_max, interpolationNN, SAVING_PATH);

	delete interpolation;
	delete interpolationNN;

	return 0;
}