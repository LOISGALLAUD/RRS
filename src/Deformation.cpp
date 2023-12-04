#include "nr3.h"
#include "Deformation.h"
#include "Transformation.h"
#include "Interpolation.h"

void Deformation::getDeformation(const NRmatrix<double> &I,
								 const VecDoub &Theta,
								 NRmatrix<bool> &binaryImage,
								 NRmatrix<double> &deformedImage,
								 InterpolationMethod *interp)
{
	NRmatrix<double> copyImage(I);
	Transformation transf;
	double x, y;
	for (size_t i = 0; i < copyImage.nrows(); i++)
	{
		for (size_t j = 0; j < copyImage.ncols(); j++)
		{

			transf.getNewpixels(i, j, Theta, x, y);
			binaryImage[i][j] = interp->getInterpolation(x, y, I, deformedImage[i][j]);
		}
	}
}
void Deformation::greyScale(NRmatrix<double> &I)
{
	for (size_t i = 0; i < I.nrows(); i++)
	{
		for (size_t j = 0; j < I.ncols(); j++)
		{
			I[i][j] = std::min(2 * std::abs(I[i][j] - 128.0), 255.0);
		}
	}
}
