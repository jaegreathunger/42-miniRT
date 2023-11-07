#include "../inc/hittable.h"

t_hittable		*hittable_init(double x, double y, double z, double radius)
{
	t_hittable	*hittable;

	hittable = malloc(sizeof(t_hittable));
	hittable->center = (point3){x, y, z};
	hittable->radius = radius;

	return (hittable);
}

t_hittable_list *hittable_list_init(void)
{
	t_hittable_list *list;

	list = malloc(sizeof(t_hittable_list));
	if (list)
	{
		list->objects = malloc(sizeof(t_hittable) * 50);
		list->size = 0;
	}
	return (list);
}

void	hittable_list_add(t_hittable_list *list, t_hittable *object)
{
	int	i;

	i = list->size;
	if (list)
	{
		list->objects[i] = object;
		list->size++;
	}
}

bool	hit(t_hittable h, t_ray r, t_interval ray_t, t_hit_record *rec)
{
	t_vec3	oc = vec3_sub(r.orig, h.center);
	double	a = vec3_len_squared(r.dir);
	double	half_b = vec3_dot(oc, r.dir);
	double	c = vec3_len_squared(oc) - h.radius * h.radius;

	double	discriminant = half_b * half_b - a * c;
	if (discriminant < 0) return false;
	double	sqrtd = sqrt(discriminant);

	double	root = (-half_b - sqrtd) / a;
	if (!surrounds(ray_t, root))
	{
		root = (-half_b + sqrtd) / a;
		if (!surrounds(ray_t, root))
			return false;
	}

	rec->t = root;
	rec->p = at(r, rec->t);
	t_vec3	outward_normal = vec3_divide(vec3_sub(rec->p, h.center), h.radius);
	set_face_normal(rec, r, outward_normal);

	return (true);
}

bool	hittable_list_hit(t_hittable_list *list, t_ray r, t_interval ray_t, t_hit_record *rec)
{
	t_hit_record	*temp_rec;
	bool			hit_anything;
	double			closest_so_far;
	int				i;

	temp_rec = rec_init();
	hit_anything = false;
	closest_so_far = ray_t.max;
	i = 0;
	while (i < list->size)
	{
		if (hit(*list->objects[i], r, (t_interval){ray_t.min, closest_so_far}, temp_rec))
		{
			hit_anything = true;
			closest_so_far = temp_rec->t;
			*rec = *temp_rec;
		}
		i++;
	}

	return (hit_anything);
}

