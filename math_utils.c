#include "fractol.h"

// from [0,.......,799] to -> [-2,.........,+2]
double	adjust(double num, double new_min, double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * (num - old_min) / (old_max - old_min) + new_min);
}

t_point	square_point(t_point p)
{
	double	real_tmp;

	real_tmp = (p.real * p.real) - (p.imaginary * p.imaginary);
	p.imaginary = 2 * p.real * p.imaginary;
	p.real = real_tmp;
	return (p);
}

t_point	sum_points(t_point p1, t_point p2)
{
	t_point	output_point;

	output_point.real = p1.real + p2.real;
	output_point.imaginary = p1.imaginary + p2.imaginary;
	return (output_point);
}

double	hypotnus(t_point p)
{
	return ((p.real * p.real) + (p.imaginary * p.imaginary));
}
