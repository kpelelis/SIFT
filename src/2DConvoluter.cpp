#include "2DConvoluter.hpp"

filtering::2DConvoluter::2DConvoluter(RGBColor[][] Input, RGBColor[][] Kernel)
{
	p_Input 		= Input;
	p_Kernel 		= Kernel;
	p_InputHeight	= Input.size();
	p_InputWidht	= Input[0].size();
	p_Ksize			= Kernel.size();
}

void filtering::2DConvoluter::execute()
{
	p_Output = new RGBColor[p_Isize][p_Isize];
	
}