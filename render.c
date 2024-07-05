/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 01:58:02 by agaladi           #+#    #+#             */
/*   Updated: 2024/07/05 02:26:16 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_pixel(t_img *img, int x, int y, int color)
{
	int		offset;

	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	julia_mandel(t_fractol *fractol, t_point *z, t_point *c)
{
	if (ft_strcmp(fractol->name, "julia"))
	{
		c->real = fractol->julia_val.real;
		c->imaginary = fractol->julia_val.imaginary;
	}
	else
	{
		c->real = z->real;
		c->imaginary = z->imaginary;
	}
}

static void	handle_coordinates(t_fractol *fractol, int x, int y)
{
	t_point	z;
	t_point	c;
	int		i;
	int		color;

	i = 0;
	z.real = (adjust(x, -2, +2, WIDTH)
			* fractol->zoom_factor) + fractol->x_shift;
	z.imaginary = (adjust(y, +2, -2, HEIGHT)
			* fractol->zoom_factor) + fractol->y_shift;
	julia_mandel(fractol, &z, &c);
	while (i < fractol->iterations_nbr)
	{
		z = sum_points(square_point(z), c);
		if (hypotnus(z) > fractol->escape_value)
		{
			color = adjust(i, BLUE, COLOR_PSY2, fractol->iterations_nbr);
			put_pixel(&fractol->img, x, y, color);
			return ;
		}
		i++;
	}
	put_pixel(&fractol->img, x, y, WHITE);
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
