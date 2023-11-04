#include "../../inc/mini_rt.h"

int	exit_rt(t_rt *rt)
{
	mlx_destroy_image(rt->mlx, rt->img);
	mlx_destroy_window(rt->mlx, rt->win);
	free(rt->mlx);
	free(rt);
	exit(0);
}
