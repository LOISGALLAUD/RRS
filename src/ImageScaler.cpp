#include "ImageScaler.h"
#include "Similarity.h"
#include "Interpolation.h"
#include "amoeba.h"
#include "Cost.h"

ImageScaler::ImageScaler(std::string imageToScalePath, std::string referenceImagePath)
{
	this->imageToScale = this->readImageFromPGM(imageToScalePath);
	this->referenceImage = this->readImageFromPGM(referenceImagePath);
}

NRmatrix<double> ImageScaler::readImageFromPGM(const string &path) const
{
	// Read an image from a PGM file
	std::ifstream file(path);
	if (!file.fail())
	{
		unsigned int maxValueOfPixels;
		char p2[2];
		unsigned int w, h;
		file >> p2;				  // P2 character
		file >> w;				  // width of the image
		file >> h;				  // height of the image
		file >> maxValueOfPixels; // max value of the pixels

		NRmatrix<double> image(w, h);
		for (size_t k = 0; k < w; k++)
			for (size_t l = 0; l < h; l++)
			{
				file >> image[k][l];
			}
		return image;
	}
	else
	{
		std::cout << "Error while opening the file " << path << std::endl;
		std::cout << "Error code : " << strerror(errno) << "\n";
		exit(1);
	}
}

VecDoub ImageScaler::getThetaMax(Similarity *similarity, Interpolation *interpolation)
{
	Cost cost(imageToScale, referenceImage, similarity, interpolation);
	Amoeba amoeba(0.01);

	VecDoub ystart(3); // Starting point for the minimization
	ystart[0] = 0;
	ystart[1] = 0;
	ystart[2] = 0;

	// Amoeba method to find the parameters of transformation minimizing cost
	VecDoub Thetamax(3);
	Thetamax = amoeba.minimize(ystart, 2., cost);

	for (size_t i = 0; i < Thetamax.size(); i++)
	{
		std::cout << Thetamax[i] << " ";
	}
	std::cout << endl;

	/*
	 * Transformation parameters conversion to a double vector
	 * to use it in the Deformation class
	 * and to apply the transformation to the image
	 */
	double *theta = new double[3];
	theta[0] = Thetamax[0];
	theta[1] = Thetamax[1];
	theta[2] = Thetamax[2];

	// Recalculating the image I from Iref and theta
	Deformation def;

	// Deformed image
	NRmatrix<double> deformedImage(imageToScale.ncols(), imageToScale.nrows());
	NRmatrix<bool> binaryImage(imageToScale.ncols(), imageToScale.nrows());
	def.getDeformation(imageToScale, theta, binaryImage, deformedImage, interpolation);
	if (similarity = 0)
		std::cout << "Similarity for this Thetamax : " << similarity->getSimilarity(imageToScale, deformedImage, binaryImage) << endl;
	else
	{
		DefaultSimilarity defaultSimilarity;
		std::cout << "Similarity for this Thetamax : " << defaultSimilarity.getSimilarity(imageToScale, deformedImage, binaryImage) << endl;
	}
	this->writeFileFromMatrix(SAVING_PATH, deformedImage);
	return Thetamax;
}
