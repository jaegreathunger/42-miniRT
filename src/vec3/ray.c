#include "../../inc/ray.h"

point3	origin(t_ray ray)
{
	return (ray.orig);
}

t_vec3	direction(t_ray ray)
{
	return (ray.dir);
}

point3	at(t_ray ray, double t)
{
	point3	pos;
	pos = vec3_multifly(ray.dir, t);
	pos = vec3_add(ray.orig, pos);
	return (pos);
}
