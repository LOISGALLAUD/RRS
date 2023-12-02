#include "nr3.h"
#include "Deformation.h"
#include "Transformation.h"
#include "Interpolation.h"

void Deformation::getDeformation(const NRmatrix<double> &I, const double *theta, NRmatrix<bool> &Ibin, NRmatrix<double> &Idef, Interpolation *interp)
{
	NRmatrix<double> copyImage(I);
	Transformation transf;
	double x, y;
	for (unsigned int i = 0; i < copyImage.nrows(); i++)
	{
		for (unsigned int j = 0; j < copyImage.ncols(); j++)
		{
			transf.getNewpixels(i, j, theta, x, y);
			if (interp == 0)
			{
				InterpolationDefault interp;
				Ibin[i][j] = interp.getInterpolation(x, y, I, Idef[i][j]);
			}
			else
				Ibin[i][j] = interp->getInterpolation(x, y, I, Idef[i][j]);
		}
	}
}
