#pragma once

#include "nr3.h"
#include "Deformation.h"

class Similarity
{
public:
	virtual double getSimilarity(const NRmatrix<double> &referenceImage,
								 const NRmatrix<double> &de,
								 const NRmatrix<bool> &binaryImage) = 0;
};

class DefaultSimilarity : Similarity
{
public:
	virtual double getSimilarity(const NRmatrix<double> &referenceImage,
								 const NRmatrix<double> &deformedImage,
								 const NRmatrix<bool> &binaryImage);
};