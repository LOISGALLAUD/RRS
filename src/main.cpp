#include <stdio.h>
#include <string>
#include "ImageScaler.h"
#include "Deformation.h"
#include "Interpolation.h"

int main()
{

	ImageScaler imageScaler;
	std::string imageToScale = "floating.pgm", referenceImage = "reference.pgm", fppv = "imageDefPpv.pgm";
	InterpolationNN interp;

	// string f, fRef;
	// cout << "Entrez le nom du fichier a recaler : ";
	// cin >> f;
	// cout << "Entrez le nom du fichier de reference : ";
	// cin >> fRef;

	std::cout << "Interpolation aux plus proches voisins:" << std::endl;

	VecDoub u = imageScaler.getThetaMax(imageToScale, referenceImage, fppv, 0, &interp);

	std::cout << "Interpolation" << std::endl;

	u = imageScaler.getThetaMax(imageToScale, referenceImage);

	return 0;
}