#include "Similarity.h"
#include "nr3.h"
#include "Deformation.h"

double Similarity::getQuadratic(const NRmatrix<double> &referenceImage,
								const NRmatrix<double> &deformedImage,
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

double Similarity::getMutualInformation(const NRmatrix<double> &referenceImage,
										const NRmatrix<double> &deformedImage,
										const NRmatrix<bool> &binaryImage)
{
	int *refHist = new int[16];
	int *defHist = new int[16];
	NRmatrix<int> joinedHist(16, 16, 0);
	int count = 0;

	// Initialize the histograms
	for (int i = 0; i < 16; i++)
	{
		refHist[i] = 0;
		defHist[i] = 0;
	}

	// Iterate over the totality of the image
	for (int i = 0; i < deformedImage.nrows(); i++)
	{
		for (int j = 0; j < deformedImage.ncols(); j++)
		{
			if (binaryImage[i][j])
			{
				// Compute the index of the bin in which the pixel belongs
				int referenceImageBin = static_cast<int>(referenceImage[i][j] / 16.0);
				int deformedImageBin = static_cast<int>(deformedImage[i][j] / 16.0);

				// Increment the corresponding bin
				refHist[referenceImageBin]++;
				defHist[deformedImageBin]++;
				joinedHist[referenceImageBin][deformedImageBin]++;
				count++;
			}
		}
	}

	// Compute the mutual information
	double mutualInformation = 0.0;

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (binaryImage[i][j])
			{
				double pxy = static_cast<double>(joinedHist[i][j]) / count;
				double px = static_cast<double>(refHist[i]) / count;
				double py = static_cast<double>(defHist[j]) / count;
				if (pxy > 0.0)
				{
					mutualInformation += pxy * (!(px * py) ? 0.0 : log(pxy / (px * py)));
				}
			}
		}
	}

	std::cout << "Mutual information = " << mutualInformation << std::endl;

	delete[] refHist;
	delete[] defHist;

	return -mutualInformation * 10;
}