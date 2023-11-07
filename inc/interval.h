#ifndef INTERVAL_H
# define INTERVAL_H

#include <stdbool.h>

typedef struct s_interval
{
	double min;
	double max;
}	t_interval;

bool	contains(t_interval interval, double x);
bool	surrounds(t_interval interval, double x);

#endif
