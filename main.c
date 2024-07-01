#include <stdio.h>


double	ft_atod(char *str)
{
	long	int_part;
	double	frac_part;
	int		sign;
	double	pow;
	int		i;

	int_part = 0;
	frac_part = 0;
	sign = 1;
	pow = 1;
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
	if (str[i] == '.' || str[i] == ',')
		i++;
	while(str[i])
	{
		pow /= 10;
		frac_part = frac_part + (str[i] - 48) * pow;
		i++;
	}
	return ((int_part + frac_part) * sign);
}

int main()
{
	printf("%f\n", ft_atod("12,25"));
}

