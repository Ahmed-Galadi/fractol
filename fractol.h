/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 01:36:44 by agaladi           #+#    #+#             */
/*   Updated: 2024/07/05 00:26:10 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

# define ERROR_MSG	"INPUT ERROR!\n"
# define WIDTH	800
# define HEIGHT	800

// colors
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define BLUE 0x0000FF
# define COLOR_PSY2 0x00FFFF // Cyan
// complex point
typedef struct s_point
{
	double		real;
	double		imaginary;	
}				t_point;
// MLX image
typedef struct s_img
{
	void		*img_ptr;
	char		*pixels_ptr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;
// MLX settings
typedef struct s_fractol
{
	char		*name;
	void		*mlx_connection; // mlx_init()
	void		*mlx_window;	// mlx_new_window()
	t_img		img;
	double		escape_value;
	int			iterations_nbr; // image quality vs rendering speed
	double		x_shift;
	double		y_shift;
	double		zoom_factor;
	t_point		julia_val;
	int			julia_tracker;
}				t_fractol;

int		ft_strcmp(char *str1, char *str2);
void	putstr_fd(char *str, int fd);
void	fractol_init(t_fractol *fractol);
void	fractol_render(t_fractol *fractol);
double	adjust(double num, double new_min, double new_max, double old_max);
t_point	square_point(t_point p);
t_point	sum_points(t_point p1, t_point p2);
double	hypotnus(t_point p);
int		key_handler(int key_symbol, t_fractol *fractol);
int		close_handler(t_fractol *fractol);
int		mouse_handler(int button, int x, int y, t_fractol *fractol);
double	ft_atod(char *str);
int		julia_tracker(int x, int y, t_fractol *fractol);
int		ft_strlen(char *str);

#endif
