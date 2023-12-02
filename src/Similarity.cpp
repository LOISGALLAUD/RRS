#include "Similarity.h"
#include "nr3.h"
#include "Deformation.h"

double Similarity::getSimilarity(const NRmatrix<double> &referenceImage,
								 const NRmatrix<double> &deformedImage,
								 const NRmatrix<bool> &binaryImage)
{
	double sum = 0;
	for (int i = 0; i < deformedImage.nrows(); i++)
	{
		for (int j = 0; j < deformedImage.ncols(); j++)
		{
			if (binaryImage[i][j])
			{
				sum += (deformedImage[i][j] - referenceImage[i][j]) * (deformedImage[i][j] - referenceImage[i][j]);
			}
		}
	}
	return sum / (deformedImage.nrows() + deformedImage.ncols());
}