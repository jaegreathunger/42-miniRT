/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:20:09 by jaeshin           #+#    #+#             */
/*   Updated: 2023/11/05 23:01:10 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
#define VEC3_H

#include "../lib/libft/includes/libft.h"
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef t_vec3 point3;

t_vec3	vec3_add(t_vec3 v, t_vec3 u);
t_vec3	vec3_sub(t_vec3 v, t_vec3 u);
t_vec3	vec3_multifly(t_vec3 v, double t);
t_vec3	vec3_divide(t_vec3 v, double t);

double	vec3_len_squared(t_vec3 v);
double	vec3_len(t_vec3 v);

double	vec3_normalize(t_vec3 v);
t_vec3	vec3_normalized(void);

double	vec3_dot(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_cross(t_vec3 v1, t_vec3 v2);

t_vec3	unit_vector(t_vec3 v);

#endif
