#ifndef __IMG_MANAGER_H__
#define __IMG_MANAGER_H__

#include "Image.h"

namespace imaging
{
	class BitmapReader : public ImageReader
	{
		public:
			Image * read(std::string filename);
			BitmapReader() : ImageReader("bitmap") {}
	};

	class BitmapWriter : public ImageWriter
	{
		public:
			void write(std::string filename, const Image & src);
			BitmapWriter() : ImageWriter("bitmap") {}
	};

}
#endif