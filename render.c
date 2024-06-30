#include "fractol.h"

// mandalbrot -> z = z^2 + c | z(0,0)| c(actual_pont)
void	handle_coordinates(t_fractol *fractol, int x, int y)
{
	t_point	z;
	t_point	c;

	z.real = 0.0;
	z.imaginary = 0.0;

	c.real = adjust(x, -2, +2, 0, WIDTH);
	c.imaginary = adjust(y, +2, -2, 0, HEIGHT);
	// if hypotenuse > 2 the point has escaped
}

void	fractol_render(t_fractol *fractol)
{
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_coordinates(fractol, x, y);
			x++;
		}
		y++;
	}
}