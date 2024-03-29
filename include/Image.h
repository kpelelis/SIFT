#ifndef _IMAGE
#define _IMAGE

#include "Color.h"
#include "Logger.h"
#include <iostream>

// macro to make a class "logged" to a file (see class Logged)
#define LOGGED_CLASS(a) class a : public Logged

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

//We put every class or function associated with the image storage, compression and manipulation 
// in the "imaging" namespace

namespace imaging
{

//------------------------------------ class Image ------------------------------------------------
// 
// It is the class that represents a generic data container for an image. It holds the actual _buffer
// of the pixel values and provides methods for accessing them either as individual pixels or as
// a memory block.
//    The Image class alone does not provide any functionality for loading and storing an image, as
// it is the product / input to such a procedure. The image I/O classes ImageReader / ImageWriter
// are responsible for this task and therefore provide the interfaces for all subclasses that
// implement support for specific formats.
//    The internal _buffer of an image Object can be configured in either an "interleaved" mode or 
// a non-interleaved "color plane" one. In the interleaved mode, the pixels are stored in RGB, RGB, RGB ... 
// order, meaning that the color components are iterated for all pixels from left to right and top to 
// bottom of the image. In the color plane mode, the R values are stored first for all the pixels, 
// then the G and finally the B channels. Note that the _buffer variable holding these data is the same
// size, regardless of its internal representation (3 X _width X _heigth bytes). The flag "interleaved"
// indicates whether the internal _buffer representation is interleaved or not.
//    You must provide implementations to turn the _buffer form an interleaved representation to a
// color plane mode and vice versa ( convertToInterleavedImage() and convertToColorPlaneImage() ).
// Remember to also switch the value of the "interleaved" flag accordingly.

	class Image
	{
	public:
		enum channel_t {RED=0,GREEN, BLUE};          // now you can use the names RED, GREEN, BLUE instead of 0,1,2
		                                             // to index individual channels
	protected:
		Component * _buffer;                          // Holds the image data
		unsigned int _width, _height;                  // _width and _heigth of the image (in pixels)

	public:
		// metric accessors
		const unsigned int getWidth() const {return _width;}      // returns the _width of the image
		const unsigned int getHeight() const {return _height;}    // returns the _heigth of the image

		// data accessors
		Component * getRawDataPtr() const{return _buffer;};		 // Obtain a pointer to the internal data
		                                                         // This is NOT a copy of the internal image data, but rather 
		                                                         // a pointer to the internally allocated space, so DO NOT
		                                                         // attempt to delete the pointer. 

		Color getPixel(unsigned int x, unsigned int y) const;    // get the color of the image at location (x,y)
		                                                         // Do any necessary bound checking. Also take into account
		                                                         // the "interleaved" flag to fetch the appropriate data
		                                                         // Return a black (0,0,0) color in case of an out-of-bounds
		                                                         // x,y pair

		// data mutators
		void setPixel(unsigned int x, unsigned int y, Color value); // Set the RGB values for an (x,y) pixel. Do all 
		                                                            // necessary bound checks and respect the "interleaved"
		                                                            // flag when updating our data.

		void setData(const Component * & data_ptr);                 // Copy the data from data_ptr to the internal _buffer.
		                                                            // The function ASSUMES a proper size for the incomming data array.

		void desaturate();

		friend Image operator+(Image lhs,Image const &rhs)
		{

			for(unsigned int i = 0; i < 3 * lhs._width * lhs._height; i++)
			{
				Component new_comp = lhs._buffer[i] + rhs._buffer[i];
				if(new_comp > 0xff) new_comp = 0xff;
					lhs._buffer[i] = new_comp;
			}
			return lhs;
		}

		friend Image operator-(Image lhs,Image const &rhs)
		{
			for(unsigned int i = 0; i < 3 * lhs._width * lhs._height; i++)
			{
				Component new_comp = lhs._buffer[i] - rhs._buffer[i];
				if(new_comp < 0) new_comp = 0;
				lhs._buffer[i] = new_comp;
			}
			return lhs;
		}

		void DrawCircle(int x, int y, float radius);
		void DrawSquare(int x, int y, float radius);

		// constructors and destructor
		Image(unsigned int _width, unsigned int _heigth);
		Image(unsigned int _width, unsigned int _heigth, const Component * data_ptr);
		Image( const Image &src);
		~Image();

	};


	//==============================================================================================================
	// 
	// Image I/O classes (or "reader/writer" class interfaces
	// They define the structure of any reader or writer for opening/saving an image (of class Image) from/to a 
	// file of a specific format. All specific format readers and writers MUST inherit from these classes
	// Note: The classes are "logged", i.e. they provide log output functionality for convenience

	LOGGED_CLASS ( ImageReader )
	{
	protected:
		const std::string suffix;
	public:
		ImageReader(std::string suffix_to_use) 
			: suffix(suffix_to_use) {};
		const std::string getFormatSuffix() {return suffix;}
		virtual Image * read(std::string filename) = 0;
	};

	LOGGED_CLASS( ImageWriter )
	{
	protected:
		const std::string suffix;
	public:
		ImageWriter(std::string suffix_to_use)
			: suffix(suffix_to_use) {};
		const std::string getFormatSuffix() {return suffix;}
		virtual void write(std::string filename, const Image & src) = 0;
	};
	
	
	//==============================================================================================================

	
	// helper functions:

	// Returns true if the suffix of the filename (after the last '.') equals the "suffix" parameter.
	// The function returns false in any other case, including the case when no '.' is found. 
	// Caution: the function should be case insensitive. E.g. requesting a "ppm" suffix for a filename
	// named "MyPicture.PPM" should return true. 
	bool isSuffix(std::string & filename, const std::string suffix);

	// Locates the part of a filename trailing the last '.' symbol and replaces it with the given
	// suffix. If no '.' is found, the function does nothing.
	void replaceSuffix(std::string & filename, const std::string suffix);


} //namespace imaging

#endif