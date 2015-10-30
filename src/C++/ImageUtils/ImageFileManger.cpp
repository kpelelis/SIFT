/* 
* @Author: plkost
* @Date:   2015-10-27 15:59:24
* @Last Modified by:   plkost
* @Last Modified time: 2015-10-27 20:37:33
*/

#include "ImageFileManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>
namespace imaging
{
	Image * BitmapReader::read(std::string filename)
	{
		std::fstream infile;
		createLogger(".logfile");
		infile.open(filename.c_str());
		if(!infile.is_open())
		{
			addLogEntry("Image " + filename + " failed to open!");
			return 0;
		}
		int width, height;
		infile >> width >> height;
		Component * pixel_buffer = new Component[3*height*width];
		for (int i = 0; i < 3 * height * width; i++)
		{
			int r,g,b;
			infile >> r >> g >> b;
			pixel_buffer[i++] 	= r;
			pixel_buffer[i++] 	= g;
			pixel_buffer[i] 	= b; 
		}
		addLogEntry("Image " + filename + "saved succefully!");
		return new Image(width, height, pixel_buffer);
	}

	void BitmapWriter::write(std::string filename, const Image & src)
	{
		std::ofstream outfile;
		outfile.open(filename.c_str());
		createLogger(".logfile");
		if(!outfile.is_open())
		{
			addLogEntry("Image " + filename + " failed to open!");
			return;	
		}
		int w = src.getWidth();
		int h = src.getHeight();
		outfile << w << ' ' << h << '\n';
		Component * pixel_buffer = src.getRawDataPtr();
		for (int i = 0; i <  3 * w * h; ++i)
		{
			int r,g,b;
			r = pixel_buffer[i++];
			g = pixel_buffer[i++];
			b = pixel_buffer[i];
			outfile << r << ' ' << g << ' ' << b << '\n';
		}
	}
};