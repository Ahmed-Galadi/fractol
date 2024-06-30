#include "fractol.h"

static void	put_pixel(t_img *img, int x, int y, int color)
{
	int		offset;

	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

// mandalbrot -> z = z^2 + c | z(0,0)| c(actual_pont)
static void	handle_coordinates(t_fractol *fractol, int x, int y)
{
	t_point	z;
	t_point	c;
	int		i;
	int		color;

	i = 0;
	z.real = 0.0;
	z.imaginary = 0.0;
	// pixel coordinates for x and y to fit in mandalbrot range
	c.real = adjust(x, -2, +2, 0, WIDTH);
	c.imaginary = adjust(y, +2, -2, 0, HEIGHT);
	// itereations until the point escape
	while (i < fractol->iterations_nbr)
	{
		// z = z^2 + c
		z = sum_points(square_point(z), c);
		// if hypotenuse > 2 the point has escaped
		if (hypotnus(z) > fractol->escape_value)
		{
			color = adjust(i, YELLOW, BLUE, 0, fractol->iterations_nbr);
			put_pixel(&fractol->img, x, y, color);
			return ;
		}
		i++;
	}
	put_pixel(&fractol->img, x, y, RED);
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
	mlx_put_image_to_window(fractol->mlx_connection,
							fractol->mlx_window,
							fractol->img.img_ptr,
							0, 0);
}
