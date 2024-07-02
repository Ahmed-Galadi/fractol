/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 01:58:11 by agaladi           #+#    #+#             */
/*   Updated: 2024/07/02 01:58:13 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int		ft_strcmp(char *str1, char *str2)
{
	int		i;

	i = 0;
	if (!str1 || !str2)
		return (0);
	if (ft_strlen(str1) != ft_strlen(str2))
		return (0);
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
				return (0);
		i++;
	}
	return (1);
}

void	putstr_fd(char *str, int fd)
{
	if (fd < 0 || !str)
			return ;
	while (*str)
		write(fd, str++, 1);
}

static void	fract_handler(char *str, int *i, double *frac_part)
{
	double div;

	div = 1;
	if (str[*i] == '.' || str[*i] == ',')
		*i += 1;
	while(str[*i])
	{
		div /= 10;
		*frac_part = *frac_part + (str[*i] - 48) * div;
		*i += 1;
	}
}
double	ft_atod(char *str)
{
	long	int_part;
	double	frac_part;
	int		sign;
	int		i;

	int_part = 0;
	frac_part = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '.' && str[i] != ',')
	{
		int_part = (int_part * 10) + (str[i] - '0');
		i++;
	}
	fract_handler(str, &i, &frac_part);
	return ((int_part + frac_part) * sign);
}
