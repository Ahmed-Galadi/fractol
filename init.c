#include "fractol.h"

static void	 allocation_error(void)
{
	putstr_fd("Error with malloc!\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	data_init(t_fractol *fractol)
{
	fractol->escape_value = 4;
	fractol->iterations_nbr = 42;
}

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx_connection = mlx_init();
	if (fractol->mlx_connection == NULL)
		allocation_error();
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection,
										WIDTH,
										HEIGHT,
										fractol->name);
	if (fractol->mlx_window == NULL)
	{
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
		free(fractol->mlx_connection);
		allocation_error();
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_connection, WIDTH, HEIGHT);
	if (fractol->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
		mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
		free(fractol->mlx_connection);
		free(fractol->img.img_ptr);
		allocation_error();
	}
	fractol->img.pixels_ptr = mlx_get_data_addr(fractol->img.img_ptr,
												&fractol->img.bits_per_pixel,
												&fractol->img.line_length,
												&fractol->img.endian);
	data_init(fractol);
}
