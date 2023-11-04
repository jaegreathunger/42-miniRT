#ifndef RAY_H
#define RAY_H

#include "vec3.h"

typedef struct s_ray
{
	point3	orig;
	t_vec3	dir;
}	t_ray;

point3	origin(t_ray ray);

t_vec3	direction(t_ray ray);

point3	at(t_ray ray, double t);

#endif
