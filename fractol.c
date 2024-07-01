#include "fractol.h"

void f()
{
	system("leaks fractol");
}
int main(int argc, char *argv[])
{
	t_fractol	fractol;
	atexit(f);
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

