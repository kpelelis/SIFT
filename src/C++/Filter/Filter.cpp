/* 
* @Author: plkost
* @Date:   2015-10-23 16:02:02
* @Last Modified by:   plkost
* @Last Modified time: 2015-10-29 16:25:24
*/
#include "Filter.h"
#include <iostream>
#include <cstring>
#include <sstream>
#include <string>

namespace imaging
{
	Filter::Filter(double * kernel, int filter_width, int filter_height, double bias ,std::string name) : _name(name)
	{
		_kernel_buffer 	= new double[filter_width * filter_height];
		std::memcpy(_kernel_buffer, kernel, filter_width * filter_height * sizeof(double));
		_filter_width	= filter_width;
		_filter_height  = filter_height;
		_bias = bias;
	}

	Filter::Filter(const Filter& irhs)
	{
		double * irhs_raw = irhs.getRawFilterPtr();
		_filter_width   = irhs.getWidth(); 
		_filter_height  = irhs.getHeight();
		_kernel_buffer  = new double[_filter_height * _filter_width];
		memcpy(_kernel_buffer, irhs_raw, _filter_height * _filter_width * sizeof(double));
	}

	Filter::Filter()
	{
		_kernel_buffer = 0;
	}

	Filter::~Filter()
	{
		addLogEntry("Deleting Filter " + _name);
		if(_kernel_buffer) delete [] _kernel_buffer;
		addLogEntry("Filter Deleted");
	}

	void Filter::setData(const double * & data)
	{
		if(!_kernel_buffer) _kernel_buffer = new double[_filter_width * _filter_height];
		memcpy(_kernel_buffer, data, _filter_width * _filter_height * sizeof(double));
	}

	Image Filter::operator>>(const Image &irhs)
	{
		addLogEntry("Applying filter : " + _name + " " + SSTR(_filter_width) + " " + SSTR(_filter_height));
		int image_width = irhs.getWidth();
		int image_height = irhs.getHeight();
		int midx = _filter_width * 0.5f;
		int midy = _filter_height * 0.5f;
		Image ret  = Image(irhs);

		double _factor = 1.f;
		for(int i = 0; i < _filter_width * _filter_height; i++) _factor += _kernel_buffer[i];
		if(_factor == 0.f) _factor = 1.f;
		_factor = 1.f/_factor;
		
		for(int y = 0; y < image_height; y++)
		{
			for(int x = 0; x < image_width; x++)
			{
				double r = 0.f, g = 0.f, b = 0.f;

				for(int fx = 0; fx < _filter_width ; fx++)
				{

					for(int fy = 0; fy < _filter_height; fy++)
					{
						int xoffset = (x - midx + fx);
						int yoffset = (y - midy + fy);
						if(OutOfBounds(xoffset, yoffset, image_width, image_height)) continue;
						double f = _kernel_buffer[(fy * _filter_width) + fx];
						Color c = irhs.getPixel(xoffset,yoffset);
						r += f*double(c.x);
						g += f*double(c.y);
						b += f*double(c.z);
					}
				}

				r = MIN(MAX(r * _factor + _bias, 0), 255);
				g = MIN(MAX(g * _factor + _bias, 0), 255);
				b = MIN(MAX(b * _factor + _bias, 0), 255);
				ret.setPixel(x,y, Color(round(r), round(g), round(b)));
			}
		}
		return ret;
	}
};