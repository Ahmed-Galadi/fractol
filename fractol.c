#include "fractol.h"


int main(int argc, char *argv[])
{
	if ((argc == 2 && ft_strcmp(argv[1], "mandalbrot"))
			|| (argc == 4 && ft_strcmp(argv[1], "julia")))
	{
			
	}
	else
	{
		putstr_fd(ERROR_MSG, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}

