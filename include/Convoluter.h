#ifndef __CONV_H__
#define __CONV_H__
#include "color.h"

namespace filtering
{
	class Convoluter
	{

	private:
		RGBColor * p_Input;
		RGBColor * p_Kernel;
		RGBColor * p_Output;

		int p_InputWidht;
		int p_InputHeight;
		int p_Ksize;

	public:
		Convoluter(RGBColor* Input, RGBColor* Kernel, int input_width, int input_height);
		~Convoluter();

		RGBColor* execute();
	};
}	
#endif