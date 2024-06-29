#include "fractol.h"

int main()
{
	t_point	z;
	t_point	c;
	double	real_tmp;
	
	z.real = 0;
	z.imaginary = 0;

	c.real = 0.25;
	c.imaginary = 0.4;

	for (int i = 0; i < 42; ++i)
	{
		// Z = Z^2 + C
		// finding 'Z^2' value;
		real_tmp = (z.real * z.real) - (z.imaginary * z.imaginary);
		z.imaginary = 2 * z.real * z.imaginary;
		z.real = real_tmp;
		// adding 'C' value
		z.real += c.real;
		z.imaginary += c.imaginary;
		printf("iteration n -> %d | real: %f | imaginary: %f|\n", i, z.real, z.imaginary);	
	}
}

