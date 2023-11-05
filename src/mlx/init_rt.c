#include "../../inc/mini_rt.h"

void	init_rt(t_rt *rt)
{
	if (!rt)
	{
		printf("Failed to load rt struct.\n");
		exit(1);
	}
	rt->mlx = mlx_init();
	rt->win = mlx_new_window(rt->mlx, 800, 800, "miniRT");
	rt->img = mlx_new_image(rt->mlx, 800, 800);
	rt->info_img = mlx_get_data_addr(rt->img, &rt->bbp, &rt->size_line, &rt->endian);
}

double	degrees_to_radians(double degrees)
{
	return degrees * PI / 180.0;
}
