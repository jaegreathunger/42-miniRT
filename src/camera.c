#include "../inc/camera.h"

t_camera	*cam_init(void)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	cam->aspect_ratio = 16.0 / 16.0;
	cam->image_width = 800;
	cam->image_height = (int)(cam->image_width / cam->aspect_ratio);
	cam->image_height = (cam->image_height < 1) ? 1 : cam->image_height;

	cam->center = (point3){0, 0, 0};

	double	focal_length = 1.0;
	double	viewport_height = 2.0;
	double	viewport_width = viewport_height * (double)(cam->image_width / cam->image_height);

	t_vec3	viewport_u = (t_vec3){viewport_width, 0, 0};
	t_vec3	viewport_v = (t_vec3){0, -viewport_height, 0};

	cam->pixel_delta_u = vec3_divide(viewport_u, cam->image_width);
	cam->pixel_delta_v = vec3_divide(viewport_v, cam->image_height);

	t_vec3	viewport_upper_left = vec3_sub(cam->center, (t_vec3){0, 0, focal_length});
	viewport_upper_left = vec3_sub(viewport_upper_left, vec3_divide(viewport_u, 2));
	viewport_upper_left = vec3_sub(viewport_upper_left, vec3_divide(viewport_v, 2));

	cam->pixel00_loc = vec3_multifly(vec3_add(cam->pixel_delta_u, cam->pixel_delta_v), 0.5);
	cam->pixel00_loc = vec3_add(viewport_upper_left, cam->pixel00_loc);

	return (cam);
}

void	render(t_rt *rt, t_hittable_list *world)
{
	t_camera	*cam;

	cam = cam_init();
	for (int y = 0; y < cam->image_height; ++y)
	{
		for (int x = 0; x < cam->image_width; ++x)
		{
			point3	pixel_center = vec3_add(cam->pixel00_loc, vec3_multifly(cam->pixel_delta_u, x));
			pixel_center = vec3_add(pixel_center, vec3_multifly(cam->pixel_delta_v, y));
			t_vec3	ray_direction = vec3_sub(pixel_center, cam->center);
			t_ray	r = (t_ray){cam->center, ray_direction};

			color	pixel_color = ray_color(r, world);
			unsigned long	color = (((int)(255.999 * pixel_color.x) & 0xff) << 16) + (((int)(255.999 * pixel_color.y) & 0xff) << 8) + ((int)(255.999 * pixel_color.z) & 0xff);
			put_colour_to_pixel(rt, x, y, color);
		}
	}
}

color	ray_color(t_ray r, t_hittable_list *world)
{
	t_hit_record	*rec;

	rec = rec_init();
	if (hittable_list_hit(world, r, (t_interval){0.0, INFINITY}, rec))
		return vec3_multifly((vec3_add(rec->normal, (color){1, 1, 1})), 0.5);

	t_vec3	unit_direction = unit_vector(r.dir);
	double	a = 0.5 * (unit_direction.y + 1.0);
	color	lhs = vec3_multifly((color){1.0, 1.0, 1.0}, (1.0 - a));
	color	rhs = vec3_multifly((color){0.5, 0.7, 1.0}, a);

	return (vec3_add(lhs, rhs));
}
