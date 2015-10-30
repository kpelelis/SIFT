// #ifndef __GAUSSIANF_H__
// #define __GAUSSIANF_H__

// #include "Filter.h"

// namespace imaging
// {
// 	class LaplacianScale
// 	{
// 	public:
// 		Image CalculateLaplaceScale(const Image& src, double sigma);
		
// 		static LaplacianScale Instance()
// 		{
// 			static LaplacianScale _instance;
// 			return _instance;
// 		}

// 	private:
// 		LaplacianScale() {};
// 		LaplacianScale(LaplacianScale const&) = delete;
// 		void operator=(LaplacianScale const&) = delete;

// 		double * Build_Gauss_Table(int width, double sigma);
// 	};
// }

// #endif