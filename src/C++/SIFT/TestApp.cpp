/* 
* @Author: plkost
* @Date:   2015-10-27 16:51:33
* @Last Modified by:   plkost
* @Last Modified time: 2015-10-30 10:51:56
*/

#include <iostream>
#include "ImageFileManager.h"
#include "Filter.h"
#include <math.h>

using namespace imaging;


int main(){
	BitmapReader bmr = BitmapReader();
    Image * img = bmr.read("src/SharedData/main_pipe");
	BitmapWriter bmw = BitmapWriter();
	bmw.write("src/SharedData/new_img", *img);
    return 0;
}