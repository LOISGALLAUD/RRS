#include "Similarity.h"
#include "nr3.h"
#include "Deformation.h"

double Similarity::getSimilarity(const NRmatrix<double> &deformedImage,
								 const NRmatrix<double> &referenceImage,
								 const NRmatrix<bool> &binaryImage)
{
	// Compute the similarity between the reference image and the deformed image
	// using the binary image as a mask.
	// The similarity is the mean squared error between the two images.
	// If two images are identical, the similarity is 0.
	double sum = 0;
	int count = 0;
	for (int i = 0; i < deformedImage.nrows(); i++)
	{
		for (int j = 0; j < deformedImage.ncols(); j++)
		{
			if (binaryImage[i][j])
			{
				sum += (deformedImage[i][j] - referenceImage[i][j]) * (deformedImage[i][j] - referenceImage[i][j]);
				count++;
			}
		}
	}
	// std::cout << "count = " << count << std::endl;
	double res = (count > 0) ? sum / static_cast<double>(count) : 0.0;
	// std::cout << "Similarity = " << res << std::endl;
	return res;
}