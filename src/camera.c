#include "../inc/camera.h"

void	render(t_hittable_list *world)
{
	
}

void	initialize(void)
{

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
