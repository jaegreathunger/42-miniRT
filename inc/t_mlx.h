/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:48:39 by jaeshin           #+#    #+#             */
/*   Updated: 2023/11/06 15:24:31 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MLX_H
# define T_MLX_H

#include "../lib/libmlx/mlx.h"

#include "vec3.h"
#include "ray_color.h"
#include "ray.h"

#include <stdio.h>
#include <stdlib.h>

// Keycodes
# define ESC 53
# define SPACE 49
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126

# define INFINITY DBL_MAX
# define PI 3.1415926535897932385

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*info_img;
	int		bbp;
	int		size_line;
	int		endian;
}	t_mlx;

void	init_mlx(t_mlx *mlx);
int		exit_mlx(t_mlx *mlx);

int		key_handler(int keycode, t_mlx *mlx);
int		mouse_handler(int button, t_mlx *mlx);

void	put_colour_to_pixel(t_mlx *mlx, int x, int y, int color);

double	degrees_to_radians(double degrees);

#endif
