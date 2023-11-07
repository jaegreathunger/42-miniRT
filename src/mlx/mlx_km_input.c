#include "../../inc/minirt.h"

int	key_handler(int keycode, t_rt *rt)
{
	if (keycode == ESC)
		exit(0);
	(void)rt;
	return (0);
}

int	mouse_handler(int button, t_rt *rt)
{
	(void)button;
	(void)rt;
	return (0);
}
