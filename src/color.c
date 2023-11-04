#include "../inc/color.h"

double	write_color(color pixel_color)
{
	double	color;

	color = pixel_color.x * pixel_color.y;
	return color;
}

color	ray_color(t_ray r)
{
	t_vec3	unit_direction = unit_vector(r.dir);
	double	a = 0.5 * (unit_direction.y + 1.0);
	printf("a - %f\n", a);
	color	lhs = vec3_multifly((color){1.0, 1.0, 1.0}, (1.0 - a));
	color	rhs = vec3_multifly((color){0.5, 0.7, 1.0}, a);
	//printf("lhs x - %f, y - %f, z - %f\n", lhs.x, lhs.y, lhs.z);
	//printf("rhs x - %f, y - %f, z - %f\n", rhs.x, rhs.y, rhs.z);
	color	r_value = vec3_add(lhs, rhs);
	//printf("return x - %f, y - %f, z - %f\n", r_value.x, r_value.y, r_value.z);
	return (r_value);
}
