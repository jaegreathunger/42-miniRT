#ifndef CAMERA_H
# define CAMERA_H

#include "ray.h"
#include "ray_color.h"
#include "minirt.h"

typedef struct s_camera
{
	double	aspect_ratio = 1.0;
	int		image_width = 100;
}	t_camera;

void	render(t_hittable_list *world);

void	initialize(void);

color	ray_color(t_ray r, t_hittable_list *world);

#endif
