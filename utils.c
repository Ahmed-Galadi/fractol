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
