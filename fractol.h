#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define ERROR_MSG "INPUT ERROR!\n"
#define WIDTH 800
#define HEIGHT 800

// complex point
typedef struct	s_point
{
	double		real;
	double		imaginary;	
}				t_point;
// MLX image
typedef struct	s_img
{
	void		*img_ptr;
	char		*pixels_ptr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;
// MLX settings
typedef struct	s_fractol
{
	char		*name;
	void		*mlx_connection; // mlx_init()
	void		*mlx_window;	// mlx_new_window()
	t_img		img;
}				t_fractol;

int		ft_strcmp(char *str1, char *str2);
void	putstr_fd(char *str, int fd);
void	fractol_init(t_fractol *fractol);
void	fractol_render(t_fractol *fractol);
double	adjust(double num, double new_min, double new_max, double old_min, double old_max);
t_point	square_point(t_point p);
t_point	sum_points(t_point p1, t_point p2);
#endif
