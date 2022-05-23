#pragma once//表示只定义一次，如果main包含了这个头文件两次，也只编译一次
#ifndef COLOR_H
#define COLOR_H
#include "vec3.h"
#include <iostream>
void write_color(std::ostream& out, color pixel_color, int samples_per_pixel) 
{
	auto r = pixel_color.x();
	auto g = pixel_color.y();
	auto b = pixel_color.z();
	
	auto scale = 1.0 / samples_per_pixel;
	r = sqrt(scale * r);
	g = sqrt(scale * g);
	b = sqrt(scale * b);
	
	out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
		<< static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
		<< static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';


}
#endif