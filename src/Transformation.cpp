#include "Transformation.h"

#define DEG_TO_RAD(degrees) ((degrees) * M_PI / 180.0)
#define RAD_TO_DEG(radians) ((radians) * 180.0 / M_PI)

void Transformation::getNewpixels(double x, double y, const VecDoub &theta, double &xp, double &yp)
{
	// Compute the new coordinates of the pixel (x, y) after the transformation
	// given by the parameters theta.
	// The new coordinates are stored in xp and yp.
	// The transformation is a rigid transformation.
	// The parameters theta are the following:
	// theta[0] : translation on the x axis
	// theta[1] : translation on the y axis
	// theta[2] : rotation angle in degrees

	double t_x = theta[0];
	double t_y = theta[1];
	double theta_deg = DEG_TO_RAD(theta[2]);

	xp = cos(theta_deg) * x - sin(theta_deg) * y + t_x;
	yp = sin(theta_deg) * x + cos(theta_deg) * y + t_y;
}
