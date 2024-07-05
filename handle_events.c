/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 01:45:11 by agaladi           #+#    #+#             */
/*   Updated: 2024/07/05 02:22:23 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
	mlx_clear_window(fractol->mlx_connection, fractol->mlx_window);
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	exit(EXIT_SUCCESS);
}

int	key_handler(int key_symbol, t_fractol *fractol)
{
	if (key_symbol == 126)
		fractol->y_shift -= 0.5 * fractol->zoom_factor;
	if (key_symbol == 125)
		fractol->y_shift += 0.5 * fractol->zoom_factor;
	if (key_symbol == 124)
		fractol->x_shift -= 0.5 * fractol->zoom_factor;
	if (key_symbol == 123)
		fractol->x_shift += 0.5 * fractol->zoom_factor;
	if (key_symbol == 53)
		close_handler(fractol);
	if (key_symbol == 69)
		fractol->iterations_nbr += 10;
	if (key_symbol == 78)
		fractol->iterations_nbr -= 10;
	if (key_symbol == 49)
	{
		if (fractol->julia_tracker == 1)
			fractol->julia_tracker = 0;
		else
			fractol->julia_tracker = 1;
	}
	fractol_render(fractol);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractol *fractol)
{
	if (button == 4)
		fractol->zoom_factor *= 0.95;
	if (button == 5)
		fractol->zoom_factor *= 1.05;
	(1 && (x = y), (y = x));
	fractol_render(fractol);
	return (0);
}

int	julia_tracker(int x, int y, t_fractol *fractol)
{
	if (ft_strcmp(fractol->name, "julia") && fractol->julia_tracker == 1)
	{
		fractol->julia_val.real = (adjust(x, -2, 2, WIDTH)
				* fractol->zoom_factor)
			+ fractol->x_shift;
		fractol->julia_val.imaginary = (adjust(y, 2, -2, HEIGHT)
				* fractol->zoom_factor)
			+ fractol->y_shift;
		fractol_render(fractol);
	}
	return (0);
}
