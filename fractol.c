/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 01:33:02 by agaladi           #+#    #+#             */
/*   Updated: 2024/07/05 00:44:41 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	isdig(char c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_isdouble(char *d_str)
{
	int		i;
	int		dup;

	i = 0;
	dup = 0;
	if (ft_strlen(d_str) == 0)
		return (0);
	while (d_str[i])
	{
		if (d_str[i] != '.' && !isdig(d_str[i])
			&& d_str[i] != '+' && d_str[i] != '-')
			return (0);
		if ((d_str[i] == '-' || d_str[i] == '+')
			&& (isdig(d_str[i - 1]) || !isdig(d_str[i + 1])))
			return (0);
		if (d_str[i] == '.' && !isdig(d_str[i - 1]) && !isdig(d_str[i + 1])
			&& (d_str[i - 1] == '+' || d_str[i - 1] == '-'))
			return (0);
		if (d_str[i] == '.')
			dup++;
		i++;
	}
	if (dup > 1)
		return (0);
	return (1);
}

static int is_valid(int argc, char *argv[])
{
	if (argc == 2 && ft_strcmp(argv[1], "mandelbrot"))
		return (1);
	if (argc == 4 && ft_strcmp(argv[1], "julia") && ft_isdouble(argv[2]) && ft_isdouble(argv[3]))
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fractol	fractol;

	if (is_valid(argc, argv))
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
