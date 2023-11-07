#include "../../inc/minirt.h"

void	put_colour_to_pixel(t_rt *rt, int x, int y, int color)
{
	int	*info_img;

	info_img = rt->info_img;
	info_img[y * rt->size_line / 4 + x] = color;
}
