#include "Transformation.h"

void Transformation::getNewpixels(double x, double y, const double *theta, double &xp, double &yp)
{
	xp = cos(theta[2] / 180 * M_PI) * x - sin(theta[2] / 180 * M_PI) * y + theta[0];
	yp = sin(theta[2] / 180 * M_PI) * x + cos(theta[2] / 180 * M_PI) * y + theta[1];
}
