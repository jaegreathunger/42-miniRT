#include "../inc/color.h"

double	write_color(color pixel_color)
{
	double	color;

	color = pixel_color.x * pixel_color.y;
	return color;
}
