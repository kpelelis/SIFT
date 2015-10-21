#ifndef 2DCONV_H
#define 2DCONV_H
#include "color.hpp";

namespace filtering
{
	class 2DConvoluter
	{

	private:
		RGBColor[][] p_Input;
		RGBColor[][] p_Kernel;
		RGBColor[][] p_Output;

		int p_InputWidht;
		int p_InputHeight;
		int p_Ksize;

	public:
		2DConvoluter(RGBColor[][] Input, RGBColor[][] Kernel);
		~2DConvoluter();

		RGBColor[][] execute();
	};
}	
#endif