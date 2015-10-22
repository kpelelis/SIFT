#include "color.h"
#include "Image.h"
#include <fstream>
#include "Logger.h"

Image::Image(char * filename)
{
	Logger::Instance()->LOG_MESSAGE("Loading Image... " + std::string(filename));
	p_filename = filename;
}

Image::~Image()
{
	UnloadImage();
}

void Image::LoadImage()
{
	std::ifstream infile;
	infile.open(p_filename);
	if(!infile.is_open())
		Logger::Instance()->LOG_WARNING("File " + std::string(p_filename) + " was not opened");
	infile >> p_width >> p_height;
	p_pixel_map = new RGBColor[p_height*p_width];
	for (int i = 0; i < p_height * p_width; ++i)
	{
		byte r,g,b;
		infile >> r >> g >> b;
		p_pixel_map[i] = new RGBColor(r,g,b);
	}
	for (int i = 0; i < p_height * p_width; ++i)
	{
		Logger::Instance()->LOG_MESSAGE("Image Data");
	}	
}

void Image::UnloadImage()
{
	delete p_pixel_map;
}

RGBColor * Image::getPixels()
{
	return p_pixel_map;
}