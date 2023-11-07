#include "../../inc/t_mlx.h"

void	put_colour_to_pixel(t_mlx *rt, int x, int y, int color)
{
	int	*info_img;

	info_img = rt->info_img;
	info_img[y * rt->size_line / 4 + x] = color;
}
