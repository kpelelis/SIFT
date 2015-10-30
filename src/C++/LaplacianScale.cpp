// #include "LaplacianScale.h"	
// namespace imaging
// {
// 	Image LaplacianScale::CalculateLaplaceScale(const Image& src,double sigma)
// 	{
// 		Filter gaussian_filter = Filter(Build_Gauss_Table(5, sigma), 5, 5, 0.f, "Gaussian Filter");
// 		return Image(gaussian_filter >> src);
// 	}

// 	double * LaplacianScale::Build_Gauss_Table(int width, double sigma)
// 	{
// 		int mid = width * 0.5f;
// 		double sigma_sq = sigma * sigma;
// 		double factor = 1.f/(2 * 3.14f * sigma_sq);
// 		double * ret = new double[width * width];
// 		int x = 0, y = 0;
// 		for(double j = mid; j >= -mid; --j)
// 		{
// 			x = 0;
// 			for (double i = -mid; i <= mid; ++i)
// 			{
// 				double exponent = (i*i + j*j)/(2.f * sigma_sq);
// 				double val = factor * exp(-exponent);
// 				ret[y * width + x++] = val;
// 			}
// 			y++;
// 		}
// 		return ret;
// 	}
// }