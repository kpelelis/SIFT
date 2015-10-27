#ifndef __FILTER_H__
#define __FILTER_H__

#include "Image.h"
#include <iostream>

namespace imaging
{
	LOGGED_CLASS( Filter )
	{

	public:
		float * getRawFilterPtr() const { return _kernel_buffer; }
		const int getWidth() const { return _filter_width; }
		const int getHeight() const { return _filter_height; }

		float get_value(int x, int y) const { return _kernel_buffer[y * _filter_width + x]; } ;

		void setData(const float * & data);

		Filter(float * kernel, int filter_width, int filter_height, std::string name);
		Filter(const Filter& src);
		Filter();

		Image operator >>(const Image &irhs);

		~Filter();

	protected:
		const std::string _name;
		
		float * _kernel_buffer;
		int _filter_width;
		int _filter_height;
	};
}
#endif