#include "Image.h"
#include <iostream>
#include <cstring>

namespace imaging 
{

//-------------------------------- Image class implementation goes here ---------------------------------------------------
	
	Image::Image(unsigned int width, unsigned int height, const Component * data_ptr){
		_width = width;
		_height = height;
		_buffer = new Component[3*width*height];
		std::memcpy(_buffer,data_ptr,3*_width * _height); 
	}

	Image::Image(unsigned int width, unsigned int height){
		_width = width;
		_height = height;
		_buffer = new Component[3*width*height];
	}

	Image::Image( const Image &src){
		_width = src.getWidth();
		_height = src.getHeight();
		_buffer = new Component[3 * _width * _height];
		std::memcpy(_buffer,src.getRawDataPtr(),3*_width * _height); 
	}

	Image::~Image(){
		delete [] _buffer;
	}

	void Image::setPixel(unsigned int x , unsigned int y, Color value){
		Component red 	= value.x;
		Component green = value.y;
		Component blue 	= value.z; 
		_buffer[3*((y * _width) + x)] 	= red;
		_buffer[3*((y * _width) + x) + 1] = green;
		_buffer[3*((y * _width) + x) + 2] = blue;
	}
		
	Color Image::getPixel(unsigned int x, unsigned int y) const 
	{
		Component red 	= _buffer[3*((y * _width) + x)];
		Component green = _buffer[3*((y * _width) + x) + 1];
		Component blue 	= _buffer[3*((y * _width) + x) + 2];
		return Color(red, green, blue);
	}

	void Image::setData(const Component * & data_ptr)
	{
		std::memcpy(_buffer, data_ptr, 3 * _width * _height);
	}
} // namespace imaging