#ifndef __COLOR_H__
#define __COLOR_H__

#define min(a,b) ((a > b) ? (b : a))
#define max(a,b) ((a > b) ? (a : b))
#define array_length(a) (sizeof(a)/sizeof(a[0]))

typedef unsigned char byte;

class RGBColor
{
private:
	byte p_red;
	byte p_green;
	byte p_blue;

public:
	RGBColor(byte r, byte g, byte b) : p_red(r), p_green(g), p_blue(b) { }
	RGBColor() : p_red(0), p_green(0), p_blue(0) { }
	~RGBColor() { };

	byte getRed() 	const   { 	return p_red; 	}
	byte getGreen() const  	{ 	return p_green; }
	byte getBlue() 	const 	{ 	return p_blue; 	}

	RGBColor operator+(const RGBColor& lhs)
	{
		return *(new RGBColor(p_red + lhs.getRed(),p_green + lhs.getGreen(), p_blue + lhs.getBlue()));
	}

	RGBColor operator-(const RGBColor& lhs)
	{
		return *(new RGBColor(p_red - lhs.getRed(),p_green - lhs.getGreen(), p_blue - lhs.getBlue()));
	}

	RGBColor operator*(const int& lhs)
	{
		return *(new RGBColor(p_red * lhs,p_green * lhs, p_blue * lhs));
	}

	RGBColor operator/(const int& lhs)
	{
		return *(new RGBColor(p_red / lhs,p_green / lhs, p_blue / lhs));
	}

	void operator=(const RGBColor& rhs)
	{
		p_red = rhs.getRed();
		p_green = rhs.getGreen();
		p_blue = rhs.getBlue();
	}

	void operator=(const RGBColor * rhs)
	{
		p_red = rhs->getRed();
		p_green = rhs->getGreen();
		p_blue = rhs->getBlue();
	}


};

#endif