#include "RigidRescaler.h"
#include "Deformation.h"
#include <cstdlib>

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

int main(int argc, char **argv)
{
	RigidRescaler rigidRescaler(IMAGE_TO_SCALE, REFERENCE_IMAGE);
	VecDoub theta_max;
	InterpolationMethod *interpolation = new Interpolation();
	InterpolationMethod *interpolationNN = new InterpolationNN();

	if (argc < 2)
	{
		std::cout << "Error: Not enough arguments provided" << std::endl;
		return 1;
	}

	int method = std::atoi(argv[1]);

	if (method == 1)
	{
		std::cout << "Result with basic bilinear interpolation method:" << std::endl;
		theta_max = rigidRescaler.getThetaMax(interpolation, SAVING_PATH);
		showThetaMax(theta_max);
		rigidRescaler.applyDeformation(theta_max, interpolation, SAVING_PATH);
	}
	else if (method == 2)
	{
		std::cout << "Result with nearest neighbor method:" << std::endl;
		theta_max = rigidRescaler.getThetaMax(interpolationNN, SAVING_PATH);
		showThetaMax(theta_max);
		rigidRescaler.applyDeformation(theta_max, interpolationNN, SAVING_PATH);
	}
	else
	{
		std::cout << "Error: Invalid argument" << std::endl;
		return 1;
	}

	delete interpolation;
	delete interpolationNN;

	return 0;
}