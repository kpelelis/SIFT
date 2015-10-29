#ifndef __FILTER_H__
#define __FILTER_H__

#include "Image.h"
#include <iostream>

namespace imaging
{
	LOGGED_CLASS( Filter )
	{

	public:
		double * getRawFilterPtr() const { return _kernel_buffer; }
		const int getWidth() const { return _filter_width; }
		const int getHeight() const { return _filter_height; }

		double get_value(int x, int y) const { return _kernel_buffer[y * _filter_width + x]; } ;

		void setData(const double * & data);

		Filter(double * kernel, int filter_width, int filter_height, double bias, std::string name);
		Filter(const Filter& src);
		Filter();

		Image operator >>(const Image &irhs);

		~Filter();

	protected:
		const std::string _name;
		
		bool OutOfBounds(int x, int y, int xm, int ym) { return x < 0 || x >= xm || y < 0 || y >= ym;}

		double * _kernel_buffer;
		int _filter_width;
		int _filter_height;

		double _bias;
	};
}
#endif