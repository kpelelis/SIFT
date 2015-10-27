#include "GaussianFilter.h"
#include <iostream>
#include <string>

std::string img_file = "src/SharedData/main_pipe";
std::string out_file = "src/SharedData/new_img";

int main(int argc, char const *argv[] )
{
	std::cout << "Running ... \n";
	Image img = *(new Image());
	img.LoadImage((char *) img_file.c_str());
	GaussianFilter f = *(new GaussianFilter(3,3.f));
	Image r = f >> img;
	img.WriteToFile((char *) out_file.c_str());
	return 0;
}
