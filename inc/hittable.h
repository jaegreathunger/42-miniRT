#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"
#include "hit_record.h"

typedef struct s_hittable
{
	point3	center;
	double	radius;
}	t_hittable;

typedef struct s_hittable_list
{
	t_hittable	**objects;
	int			size;
}	t_hittable_list;

t_hittable		*hittable_init(double x, double y, double z, double radius);
t_hittable_list *hittable_list_init(void);
void			hittable_list_add(t_hittable_list *list, t_hittable *object);

bool			hit(t_hittable h, t_ray r, double ray_tmin, double ray_tmax, t_hit_record *rec);
bool			hittable_list_hit(t_hittable_list *list, t_ray r, double ray_tmin, double ray_tmax, t_hit_record *rec);

#endif
