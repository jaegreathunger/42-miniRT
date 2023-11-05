#include "../inc/hit_record.h"

t_hit_record	*rec_init(void)
{
	t_hit_record	*rec;

	rec = malloc(sizeof(t_hit_record));
	rec->p = (point3){0, 0, 0};
	rec->t = 0;
	rec->normal = (t_vec3){0, 0, 0};
	rec->front_face = false;

	return (rec);
}

void	set_face_normal(t_hit_record *rec, t_ray r, t_vec3 outward_normal)
{
	rec->front_face = vec3_dot(r.dir, outward_normal) < 0;
	rec->normal = rec->front_face ? outward_normal : vec3_multifly(outward_normal, -1.0);
}
