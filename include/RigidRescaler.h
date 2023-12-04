#pragma once
#include "Interpolation.h"
#include "Similarity.h"
#include "Similarity.h"
#include "Interpolation.h"
#include "nr3.h"
#include "amoeba.h"
#include "Cost.h"

class RigidRescaler
{
private:
	NRmatrix<double> imageToScale;
	NRmatrix<double> referenceImage;
	Transformation *transformation;

public:
	RigidRescaler(std::string, std::string);
	VecDoub getThetaMax(InterpolationMethod *, std::string);
	void applyDeformation(const VecDoub &,
						  InterpolationMethod *,
						  const std::string &);
	NRmatrix<double> readImageFromPGM(const string &) const;
	template <typename T>
	void writeFileFromMatrix(const std::string &path, const NRmatrix<T> image) const
	{
		std::ofstream file(path);
		if (file.fail())
		{
			std::cout << "Error while opening the file " << path << std::endl;
		}
		else
		{
			int w = image.nrows();
			int h = image.ncols();
			file << "P2 " << w << " " << h << " 255" << std::endl;
			for (int k = 0; k < w; k++)
			{
				for (int l = 0; l < h; l++)
				{
					if constexpr (std::is_same_v<T, bool>)
					{
						file << image[k][l] * 255 << " ";
					}
					else
					{
						file << image[k][l] << " ";
					}
				}
				file << std::endl;
			}
		}
	}
};
