#ifndef __IMGSCALE_H__
#define __IMGSCALE_H__

#include "Image.h"

namespace imaging
{
	LOGGED_CLASS( ImageScaler )
	{

	public:
		enum scale_t { INCR, DECR };
		
		Image scale(const Image& src);

		float get_scale() const { return _scale; }
		scale_t get_scale_type() const { return _scale_type; }

		ImageScaler(float scale, scale_t scale_type) : _scale_type(scale_type), _scale(scale) { };
		
		ImageScaler(const ImageScaler& src)
		{
			_scale_type = src.get_scale_type();
			_scale = src.get_scale();
		}

		ImageScaler() { };
		~ImageScaler() { };

	protected:
		scale_t _scale_type;
		float _scale;
	};
}
#endif
