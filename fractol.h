#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define ERROR_MSG "INPUT ERROR!\n"

typedef struct	s_point
{
	double	real;
	double	imaginary;
}		t_point;

int		ft_strcmp(char *str1, char *str2);
void	putstr_fd(char *str, int fd);

#endif
