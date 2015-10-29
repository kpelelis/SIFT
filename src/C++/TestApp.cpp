/* 
* @Author: plkost
* @Date:   2015-10-27 16:51:33
* @Last Modified by:   plkost
* @Last Modified time: 2015-10-29 03:39:31
*/

#include <iostream>
#include "ImageFileManager.h"
#include "Filter.h"
#include <math.h>

using namespace imaging;

double * Build_Gauss_Table(int width, double sigma)
{
	int mid = width * 0.5f;
	double sigma_sq = sigma * sigma;
	double factor = 1.f/(2 * 3.14f * sigma_sq);
	double * ret = new double[width * width];
	int x = 0, y = 0;
	for(double j = mid; j >= -mid; --j)
	{
		x = 0;
		for (double i = -mid; i <= mid; ++i)
		{
			double exponent = (i*i + j*j)/(2.f * sigma_sq);
			double val = factor * exp(-exponent);
			ret[y * width + x++] = val;
			std::cout << val << ' ';
		}
		y++;
		std::cout << std::endl;
	}
	return ret;
}

int main(){
	BitmapReader bmr = BitmapReader();
    Image * img = bmr.read("src/SharedData/main_pipe");

	Filter f1 = Filter(Build_Gauss_Table(5, 1.f), 5, 5, 0.f, "Blur");
	Filter f2 = Filter(Build_Gauss_Table(5, 1.4f), 5, 5, 0.f, "Blur");

	Image a = (f2 >> *img) - (f1 >> *img);
	BitmapWriter bmw = BitmapWriter();
	bmw.write("src/SharedData/new_img", a);
    return 0;
}