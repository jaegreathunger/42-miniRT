/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_rt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:48:39 by jaeshin           #+#    #+#             */
/*   Updated: 2023/11/07 18:22:23 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include "../lib/libmlx/mlx.h"

#include "vec3.h"
#include "ray_color.h"
#include "ray.h"
#include "camera.h"

#include <stdio.h>
#include <stdlib.h>

// Keycodes
# define ESC 53
# define SPACE 49
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126

# define DBL_MAX __DBL_MAX__
# define PI 3.1415926535897932385

typedef struct s_rt
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*info_img;
	int		bbp;
	int		size_line;
	int		endian;
}	t_rt;

void	init_rt(t_rt *rt);
int		exit_rt(t_rt *rt);

int		key_handler(int keycode, t_rt *rt);
int		mouse_handler(int button, t_rt *rt);

void	put_colour_to_pixel(t_rt *rt, int x, int y, int color);

double	degrees_to_radians(double degrees);

#endif
