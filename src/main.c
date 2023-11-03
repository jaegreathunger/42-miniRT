/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:41:00 by jaeshin           #+#    #+#             */
/*   Updated: 2023/11/03 17:06:07 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libmlx/mlx.h"
#include "../inc/mini_rt.h"
#include "../inc/vec3.h"
#include "../inc/color.h"
#include <stdio.h>
#include <stdlib.h>

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

void	put_colour_to_pixel(t_rt *rt, int x, int y, int color)
{
	int	*info_img;

	info_img = rt->info_img;
	info_img[y * rt->size_line / 4 + x] = color;
}

int	exit_rt(t_rt *rt)
{
	mlx_destroy_image(rt->mlx, rt->img);
	mlx_destroy_window(rt->mlx, rt->win);
	free(rt->mlx);
	free(rt);
	exit(0);
}

int	main(void) {
	t_rt	*rt;

	rt = malloc(sizeof(t_rt));
	init_rt(rt);
	mlx_key_hook(rt->win, key_handler, rt);
	mlx_mouse_hook(rt->win, mouse_handler, rt);
	mlx_hook(rt->win, 17, 0L, exit_rt, rt);
	int	i = 2;
	for (int y = 0; y < 800; ++y)
	{
		for (int x = 0; x < 800; ++x)
		{
			i += 3;
			put_colour_to_pixel(rt, x, y, 0xFF0000 * i);
		}
	}
	mlx_put_image_to_window(rt->mlx, rt->win, rt->img, 0, 0);
	mlx_loop(rt->mlx);
	return 0;
}
