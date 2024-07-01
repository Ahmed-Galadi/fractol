#include "fractol.h"

int		close_handler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
	mlx_clear_window(fractol->mlx_connection, fractol->mlx_window);
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	exit(EXIT_SUCCESS);
}

int		key_handler(int key_symbol, t_fractol *fractol)
{
	if (key_symbol == 126) // UP
		fractol->y_shift -= 0.5 * fractol->zoom_factor;
	if (key_symbol == 125) // DOWN
		fractol->y_shift += 0.5 * fractol->zoom_factor;  
	if (key_symbol == 124) // RIGHT
		fractol->x_shift -= 0.5 * fractol->zoom_factor;
	if (key_symbol == 123) // LEFT 
		fractol->x_shift += 0.5 * fractol->zoom_factor;
	if (key_symbol == 53) // ESC
		close_handler(fractol);
	if (key_symbol == 69) // +
		fractol->iterations_nbr += 10;
	if (key_symbol == 78) // -
		fractol->iterations_nbr -= 10;
	fractol_render(fractol);
	return (0);
}

int		mouse_handler(int button, int x, int y,t_fractol *fractol)
{
	if (button == 1) // zoom in
	 	fractol->zoom_factor *= 0.95;
	if (button == 2) // zoom out
		fractol->zoom_factor *= 1.05;
	(1 && (x = y), (y = x));
	fractol_render(fractol);
	return (0);
}
