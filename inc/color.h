#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include "ray.h"

#include <stdbool.h>

typedef t_vec3 color;

double	hit_sphere(point3 center, double radius, t_ray r);
color	ray_color(t_ray r);

#endif
