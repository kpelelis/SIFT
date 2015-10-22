#include "Image.h"
#include <iostream>
#include <string>

std::string img_file = "../SharedData/main_pipe";

int main(int argc, char const *argv[])
{
	std::cout << "Running ... \n";
	Image * img = new Image((char*)img_file.c_str());
	img->LoadImage();
	return 0;
}