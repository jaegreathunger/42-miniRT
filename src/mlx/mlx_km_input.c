#include "../../inc/t_mlx.h"

int	key_handler(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
		exit(0);
	(void)mlx;
	return (0);
}

int	mouse_handler(int button, t_mlx *mlx)
{
	(void)button;
	(void)mlx;
	return (0);
}
