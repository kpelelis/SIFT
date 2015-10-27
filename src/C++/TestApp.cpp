/* 
* @Author: plkost
* @Date:   2015-10-27 16:51:33
* @Last Modified by:   plkost
* @Last Modified time: 2015-10-27 20:55:14
*/

#include <iostream>
#include "ImageFileManager.h"
#include "Filter.h"

using namespace imaging;

float median_kernel[9] =
{
	0.11f, 0.11f, 0.11f,
	0.11f, 0.11f, 0.11f,
	0.11f, 0.11f, 0.11f
};

int main(){
	BitmapReader bmr = BitmapReader();
    Image * img = bmr.read("src/SharedData/main_pipe");
    Filter f = Filter(median_kernel, 3, 3, "Median");
	Image a = (f >> *img);
	BitmapWriter bmw = BitmapWriter();
	bmw.write("src/SharedData/new_img", a);
    return 0;
}