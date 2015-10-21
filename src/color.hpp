#ifndef COLOR_H
#define COLOR_H

#define min(a,b) ((a > b) ? (b : a))
#define max(a,b) ((a > b) ? (a : b))
typedef unsigned char byte;

class RGBColor
{
private:
	byte p_red;
	byte p_green;
	byte p_blue;

public:
	RGBColor(int r, int g, int b) : p_red(r), p_green(g), p_blue(b) { }
	~RGBColor() { };

	int getRed() 	{ 	return p_red; 	}
	int getGreen() 	{ 	return p_green; }
	int getBlue() 	{ 	return p_blue; 	}

	RGBColor operator+(const RGBColor& lhs)
	{
		return new RGBColor(p_red + lhs.getRed(),p_green + lhs.getGreen(), p_blue + lhs.getBlue());
	}

	RGBColor operator-(const RGBColor& lhs)
	{
		return new RGBColor(p_red - lhs.getRed(),p_green - lhs.getGreen(), p_blue - lhs.getBlue());
	}

	RGBColor operator*(const int& lhs)
	{
		return new RGBColor(p_red * lhs,p_green * lhs, p_blue * lhs);
	}

	RGBColor operator/(const int& lhs)
	{
		return new RGBColor(p_red / lhs,p_green / lhs, p_blue / lhs);
	}

};

#endif