#include "Convoluter.h"

filtering::Convoluter::Convoluter(RGBColor* Input, RGBColor* Kernel, int input_width, int input_height)
{
	p_Input 		= Input;
	p_Kernel 		= Kernel;
	p_InputWidht	= input_width;
	p_InputHeight	= input_height;
	p_Ksize			= array_length(Kernel);
}

RGBColor* filtering::Convoluter::execute()
{
	return p_Input;
}