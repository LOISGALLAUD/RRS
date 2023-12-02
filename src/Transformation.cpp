#include "Transformation.h"

#define DEG_TO_RAD(degrees) ((degrees) * M_PI / 180.0)

void Transformation::getNewpixels(double x, double y, const double *theta, double &xp, double &yp)
{
	xp = cos(DEG_TO_RAD(theta[2])) * x - sin(DEG_TO_RAD(theta[2])) * y + theta[0];
	yp = sin(DEG_TO_RAD(theta[2])) * x + cos(DEG_TO_RAD(theta[2])) * y + theta[1];
}
