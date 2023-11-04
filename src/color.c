#include "../inc/color.h"

double	hit_sphere(point3 center, double radius, t_ray r)
{
	t_vec3	oc = vec3_sub(r.orig, center);
	double	a = vec3_dot(r.dir, r.dir);
	double	b = 2.0 * vec3_dot(oc, r.dir);
	double	c = vec3_dot(oc, oc) - radius * radius;
	double	discriminant = b * b - 4 * a * c;

	if (discriminant < 0)
		return -1.0;
	else
		return ((-b - sqrt(discriminant)) / (2.0 * a));
}

color	ray_color(t_ray r)
{
	double	t = hit_sphere((point3){0, 0, -1}, 0.5, r);
	if (t > 0.0)
	{
		t_vec3	N = unit_vector(vec3_sub(at(r, t), (t_vec3){0, 0, -1}));
		return (vec3_multifly((color){N.x + 1, N.y + 1, N.z + 1}, 0.5));
	}

	t_vec3	unit_direction = unit_vector(r.dir);
	double	a = 0.5 * (unit_direction.y + 1.0);
	color	lhs = vec3_multifly((color){1.0, 1.0, 1.0}, (1.0 - a));
	color	rhs = vec3_multifly((color){0.5, 0.7, 1.0}, a);

	return (vec3_add(lhs, rhs));
}
