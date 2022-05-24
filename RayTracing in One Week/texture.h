#ifndef TEXTURE_H
#define TEXTURE_H
#include "rtweekend.h"

class texture
{
public:
	virtual color value(double u, double v, const point3& p) const = 0;
};

class solid_color : public texture
{
public:
	solid_color(){}
	solid_color(color c) : color_value(c){}
	solid_color(double r, double g, double b) : solid_color(color(r, g, b)){}

	color value(double u, double v, const point3& p) const override { return color(color_value); }
public:
	color color_value;
};

class checker_texture : public texture
{
public:
	checker_texture(){}
	checker_texture(shared_ptr<texture> _odd, shared_ptr<texture> _even) : odd(_odd), even(_even){}
	checker_texture(color c1, color c2) : even(make_shared<solid_color>(c1)), odd(make_shared<solid_color> (c2)) {}

	virtual color value(double u, double v, const point3& p) const override
	{
		auto sines = sin(p.x() * 10) * sin(p.y() * 10) * sin(p.z()*10);

		if (sines < 0)	return odd->value(u, v, p);
		else
		{
			return even->value(u, v, p);
		}
	}
public:
	shared_ptr<texture> odd;
	shared_ptr<texture> even;
};
#endif
