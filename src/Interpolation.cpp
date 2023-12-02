#include "nr3.h"
#include "Interpolation.h"

bool InterpolationNN::getInterpolation(double x, double y, const NRmatrix<double> &Image, double &val)
{
    double H = Image.nrows(), L = Image.ncols();
    if ((x < 0) || (x > H - 1) || (y < 0) || (y > L - 1))
    {
        val = 0;
        return false;
    }
    else
    {

        unsigned int i1 = floor(x + 0.5);
        unsigned int j1 = floor(y + 0.5);
        val = Image[i1][j1];
        return true;
    }
}

bool InterpolationDefault::getInterpolation(double x, double y,
                                            const NRmatrix<double> &image, double &val)
{
    double H = image.nrows(), L = image.ncols();
    if ((x < 0) || (x > H - 1) || (y < 0) || (y > L - 1))
    {
        val = 0;
        return false;
    }
    else
    {
        int i1, i2, j1, j2;
        double dx, dy, dfy, dfx, dfxy, res;

        i1 = floor(x);
        j1 = floor(y);
        if (i1 == H - 1)
            i1--;
        if (j1 == L - 1)
            j1--;
        i2 = i1 + 1;
        j2 = j1 + 1;

        dx = x - i1;
        dy = y - j1;
        dfx = image[i2][j1] - image[i1][j1];
        dfy = image[i1][j2] - image[i1][j1];
        dfxy = image[i1][j1] + image[i2][j2] - image[i2][j1] - image[i1][j2];
        res = image[i1][j1] + dfx * dx + dfy * dy + dx * dy * dfxy;
        val = floor(res);
        return true;
    }
}
