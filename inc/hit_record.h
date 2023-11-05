#ifndef HIT_RECORD_H
# define HIT_RECORD_H

#include "vec3.h"
#include "ray.h"

typedef struct s_hit_record
{
	point3	p;
	t_vec3	normal;
	double	t;
	bool	front_face;
}	t_hit_record;

t_hit_record	*rec_init(void);
void			set_face_normal(t_hit_record *rec, t_ray r, t_vec3 outward_normal);

#endif
