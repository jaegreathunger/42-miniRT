#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include "ray.h"

#include <stdbool.h>

typedef t_vec3 color;

double	write_color(color pixel_color);

color	ray_color(t_ray r);

#endif
