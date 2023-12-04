#include "RigidRescaler.h"
#include "Similarity.h"
#include "Interpolation.h"
#include "amoeba.h"
#include "Cost.h"

#define EPSILON 0.01

RigidRescaler::RigidRescaler(std::string imageToScalePath, std::string referenceImagePath)
{
	this->imageToScale = this->readImageFromPGM(imageToScalePath);
	this->referenceImage = this->readImageFromPGM(referenceImagePath);
}

NRmatrix<double> RigidRescaler::readImageFromPGM(const string &path) const
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

VecDoub RigidRescaler::getThetaMax(InterpolationMethod *interpolation, std::string saving_path)
{
	Similarity *similarity = new Similarity();
	Cost cost(imageToScale, referenceImage, similarity, interpolation);
	Amoeba amoeba(EPSILON);

	VecDoub ystart(3); // Starting point for the minimization
	ystart[0] = 0;
	ystart[1] = 0;
	ystart[2] = 0;

	// Amoeba method to find the parameters of transformation minimizing cost
	VecDoub thetatMax(3);
	thetatMax = amoeba.minimize(ystart, 15., cost);

	delete similarity;

	return thetatMax;
}

void RigidRescaler::applyDeformation(const VecDoub &thetatMax,
									 InterpolationMethod *interpolation,
									 const std::string &savingPath)
{
	Deformation def;
	Similarity sim;

	// Deformed image
	NRmatrix<double> deformedImage(imageToScale.ncols(), imageToScale.nrows());
	NRmatrix<bool> binaryImage(imageToScale.ncols(), imageToScale.nrows());
	def.getDeformation(imageToScale, thetatMax, binaryImage, deformedImage, interpolation);

	// Calculate similarity
	double similarityValue = sim.getSimilarity(deformedImage, referenceImage, binaryImage);
	std::cout << "Similarity for this thetatMax : " << similarityValue << std::endl;

	// Write deformed image to file
	this->writeFileFromMatrix(savingPath, deformedImage);
}
