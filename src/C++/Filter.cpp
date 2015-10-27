/* 
* @Author: plkost
* @Date:   2015-10-23 16:02:02
* @Last Modified by:   plkost
* @Last Modified time: 2015-10-27 21:17:14
*/

#include "Filter.h"
#include <iostream>
#include <cstring>

namespace imaging
{
	Filter::Filter(float * kernel, int filter_width, int filter_height, std::string name) : _name(name)
	{
		_kernel_buffer 	= new float[filter_width * filter_height];
		std::memcpy(_kernel_buffer, kernel, filter_width * filter_height * sizeof(float));
		_filter_width	= filter_width;
		_filter_height  = filter_height;
	}

	Filter::Filter(const Filter& irhs)
	{
		float * irhs_raw = irhs.getRawFilterPtr();
		_filter_width   = irhs.getWidth(); 
		_filter_height  = irhs.getHeight();
		_kernel_buffer  = new float[_filter_height * _filter_width];
		memcpy(_kernel_buffer, irhs_raw, _filter_height * _filter_width * sizeof(float));
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

	void Filter::setData(const float * & data)
	{
		if(!_kernel_buffer) _kernel_buffer = new float[_filter_width * _filter_height];
		memcpy(_kernel_buffer, data, _filter_width * _filter_height * sizeof(float));
	}

	Image Filter::operator>>(const Image &irhs)
	{
		addLogEntry("Applying filter : " + _name);
		int image_width = irhs.getWidth();
		int image_height = irhs.getHeight();
		int midx = _filter_width * 0.5f;
		int midy = _filter_height * 0.5f;

		Image ret  = Image(irhs);
		for(int y = 0; y < image_height; y++)
		{
			for(int x = 0; x < image_width; x++)
			{
				float r = 0, g = 0, b = 0;
				int y_low  = y >= midy ? 0 : midy - y;
				int x_low  = x >= midx ? 0 : midx - x;
				int y_high = y < image_height - midy ? _filter_height : y - image_height + 1 + midy;
				int x_high = x < image_width  - midx ? _filter_width : x - image_width + 1 + midx;
				std::cout << y_low << " " << y_high << std::endl;
				for(int j = y_low; j < y_high; j++)
				{
					int yoffset = j == midy ? 0 :
								  j >  midy ? j : -j;

					for(int i = x_low; i < x_high ; i++)
					{
						int xoffset = i == midx ? 0 :
									  i >  midx ? i : -i;

						Color c = irhs.getPixel(x + xoffset, y + yoffset);
						r += c.x;
						g += c.y;
						b += c.z;
					}
				}
				r = r/9.f;
				g = g/9.f;
				b = b/9.f;
				ret.setPixel(x,y, Color((Component) r,(Component) g,(Component) b));
			}
		}
		return ret;
	}
};