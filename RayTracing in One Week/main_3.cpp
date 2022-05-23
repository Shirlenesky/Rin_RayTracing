#include "vec3.h"
#include "color.h"
#include<iostream>

using namespace std;
int main()
{
	const int image_width = 200;
	const int image_height = 100;

	cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = image_height - 1; j >= 0; --j)
	{
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < image_width; ++i)
		{
			color pixel_color(double(i) / (double(image_width) - 1), double(j) / (double(image_height) - 1), 0.25);
			write_color(cout, pixel_color);
		}
	}
	std::cerr << "\nDone.\n";
}