/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 01:51:57 by agaladi           #+#    #+#             */
/*   Updated: 2024/07/05 02:17:12 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	allocation_error(void)
{
	putstr_fd("Error with malloc!\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	data_init(t_fractol *fractol)
{
	fractol->escape_value = 4;
	fractol->iterations_nbr = 42;
	fractol->x_shift = 0.0;
	fractol->y_shift = 0.0;
	fractol->zoom_factor = 1.0;
}

void	events_init(t_fractol *fractol)
{
	mlx_hook(fractol->mlx_window, 3, 0, key_handler, fractol);
	mlx_hook(fractol->mlx_window, 4, 0, mouse_handler, fractol);
	mlx_hook(fractol->mlx_window, 17, 0, close_handler, fractol);
	mlx_hook(fractol->mlx_window, 6, 0, julia_tracker, fractol);
}

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx_connection = mlx_init();
	if (fractol->mlx_connection == NULL)
		allocation_error();
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection,
			WIDTH, HEIGHT, fractol->name);
	if (fractol->mlx_window == NULL)
		allocation_error();
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_connection,
			WIDTH, HEIGHT);
	if (fractol->img.img_ptr == NULL)
		allocation_error();
	fractol->img.pixels_ptr = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bits_per_pixel,
			&fractol->img.line_length,
			&fractol->img.endian);
	data_init(fractol);
	events_init(fractol);
}
