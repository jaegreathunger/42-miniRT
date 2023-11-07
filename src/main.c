/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:41:00 by jaeshin           #+#    #+#             */
/*   Updated: 2023/11/07 12:53:09 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/t_mlx.h"

int	main(void) {
	t_mlx	*mlx;

	double	aspect_ratio = 16.0 / 16.0;
	int		image_width = 800;

	int		image_height = (int)image_width / aspect_ratio;
	image_height = (image_height < 1) ? 1 : image_height;

	t_hittable_list	*world;
	world = hittable_list_init();
	t_hittable	*obj = hittable_init(0, 0, -1, 0.5);
	hittable_list_add(world, obj);
	t_hittable	*obj2 = hittable_init(0, -100.5, -1, 100);
	hittable_list_add(world, obj2);

	double	focal_length = 1.0;
	double	viewpomlx_height = 2.0;
	double	viewpomlx_width = viewpomlx_height * (double)image_width / image_height;
	point3	camera_center = (point3){0, 0, 0};

	t_vec3	viewpomlx_u = (t_vec3){viewpomlx_width, 0, 0};
	t_vec3	viewpomlx_v = (t_vec3){0, -viewpomlx_height, 0};

	t_vec3	pixel_delta_u = vec3_divide(viewpomlx_u, image_width);
	t_vec3	pixel_delta_v = vec3_divide(viewpomlx_v, image_height);

	t_vec3	viewpomlx_upper_left = vec3_sub(camera_center, (t_vec3){0, 0, focal_length});
	viewpomlx_upper_left = vec3_sub(viewpomlx_upper_left, vec3_divide(viewpomlx_u, 2));
	viewpomlx_upper_left = vec3_sub(viewpomlx_upper_left, vec3_divide(viewpomlx_v, 2));

	t_vec3	pixel00_loc = vec3_multifly(vec3_add(pixel_delta_u, pixel_delta_v), 0.5);
	pixel00_loc = vec3_add(viewpomlx_upper_left, pixel00_loc);

	mlx = malloc(sizeof(t_mlx));
	init_mlx(mlx);
	mlx_key_hook(mlx->win, key_handler, mlx);
	mlx_mouse_hook(mlx->win, mouse_handler, mlx);
	mlx_hook(mlx->win, 17, 0L, exit_mlx, mlx);

	for (int y = 0; y < image_height; ++y)
	{
		for (int x = 0; x < image_width; ++x)
		{
			point3	pixel_center = vec3_add(pixel00_loc, vec3_multifly(pixel_delta_u, x));
			pixel_center = vec3_add(pixel_center, vec3_multifly(pixel_delta_v, y));
			t_vec3	ray_direction = vec3_sub(pixel_center, camera_center);
			t_ray	r = (t_ray){camera_center, ray_direction};

			color	pixel_color = ray_color(r, world);
			unsigned long	color = (((int)(255.999 * pixel_color.x) & 0xff) << 16) + (((int)(255.999 * pixel_color.y) & 0xff) << 8) + ((int)(255.999 * pixel_color.z) & 0xff);
			put_colour_to_pixel(mlx, x, y, color);
		}
	}

	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_loop(mlx->mlx);
	return 0;
}
