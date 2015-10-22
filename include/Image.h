#include "color.h"
#include <string>

class Image
{
private:
	int p_width;
	int p_height;
	char * p_filename;
	RGBColor * p_pixel_map;

public:
	Image(char * filename);
	~Image();
	void LoadImage();
	void UnloadImage();
	RGBColor * getPixels();
};