#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <fcntl.h>

#define ERROR_MSG	"INPUT ERROR!\n"
#define WIDTH	800
#define HEIGHT	800

// Basic Colors
#define BLACK	0x000000
#define WHITE	0xFFFFFF
#define RED		0xFF0000
#define GREEN	0x00FF00
#define BLUE	0x0000FF
#define YELLOW	0xFFFF00

// Psychedelic Colors
#define COLOR_PSY1    0xFF00FF  // Magenta
#define COLOR_PSY2    0x00FFFF  // Cyan
#define COLOR_PSY3    0xFFFF00  // Yellow
#define COLOR_PSY4    0xFF69B4  // Hot Pink
#define COLOR_PSY5    0x8A2BE2  // Blue Violet
#define COLOR_PSY6    0x7FFF00  // Chartreuse
#define COLOR_PSY7    0xFF4500  // Orange Red
#define COLOR_PSY8    0xDA70D6  // Orchid
#define COLOR_PSY9    0x00FF7F  // Spring Green
#define COLOR_PSY10   0xADFF2F  // Green Yellow

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
	double		escape_value;
	int			iterations_nbr; // image quality vs rendering speed
	double		x_shift;
	double		y_shift;
	double		zoom_factor;
	t_point		julia_val;
}				t_fractol;

int		ft_strcmp(char *str1, char *str2);
void	putstr_fd(char *str, int fd);
void	fractol_init(t_fractol *fractol);
void	fractol_render(t_fractol *fractol);
double	adjust(double num, double new_min, double new_max, double old_min, double old_max);
t_point	square_point(t_point p);
t_point	sum_points(t_point p1, t_point p2);
double	hypotnus(t_point p);
int		key_handler(int key_symbol, t_fractol *fractol);
int		close_handler(t_fractol *fractol);
int		mouse_handler(int button, int x, int y,t_fractol *fractol);
double	ft_atod(char *str);

#endif
