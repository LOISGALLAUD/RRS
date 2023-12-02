#pragma once
#include "Interpolation.h"
#include "Similarity.h"
#include "Similarity.h"
#include "Interpolation.h"
#include "nr3.h"
#include "amoeba.h"
#include "Cost.h"

class ImageScaler
{
public:
	NRmatrix<double> readImageFromPGM(const string &);
	void writeFileFromMatrix(const string &, const NRmatrix<double>) const;
	void writeFileFromMatrix(const string &, const NRmatrix<bool>) const;

	VecDoub getThetaMax(string imageToScalePath,
						string referenceImagePath,
						string path,
						Similarity *sim = 0,
						Interpolation *interp = 0);

	VecDoub getThetaMax(string imageToScalePath, string referenceImagePath, Similarity *sim = 0, Interpolation *interp = 0);
	VecDoub getThetaMax(string imageToScalePath, string referenceImagePath, Interpolation *interp);
	VecDoub getThetaMax(string imageToScalePath, string referenceImagePath, Similarity *sim);
	VecDoub getThetaMax(string imageToScalePath, string referenceImagePath, string path, Interpolation *interp);
	VecDoub getThetaMax(string imageToScalePath, string referenceImagePath, string path, Similarity *sim);
};