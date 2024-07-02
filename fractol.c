/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 01:33:02 by agaladi           #+#    #+#             */
/*   Updated: 2024/07/02 01:34:06 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_fractol	fractol;

	if ((argc == 2 && ft_strcmp(argv[1], "mandalbrot"))
		|| (argc == 4 && ft_strcmp(argv[1], "julia")))
	{
		fractol.name = argv[1];
		if (argc == 4)
		{
			fractol.julia_val.real = ft_atod(argv[2]);
			fractol.julia_val.imaginary = ft_atod(argv[3]);
		}
		fractol_init(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.mlx_connection);
	}
	else
	{
		putstr_fd(ERROR_MSG, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}
