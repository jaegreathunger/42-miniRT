#include "../inc/interval.h"

bool	contains(t_interval interval, double x)
{
	return (interval.min <= x && x <= interval.max);
}

bool	surrounds(t_interval interval, double x)
{
	return (interval.min < x && x < interval.max);
}
