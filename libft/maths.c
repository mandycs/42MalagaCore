#include "libft.h"

double	ft_sqrt(double x)
{
	double n;

	n = 1;
	if (x > 0)
	{
		while(n * n <= x)
		{
			if (n * n == x)
				return (n);
			n++;
		}
	}
	return (0);
}

double	ft_double(double x, double y)
{
	double	nb;

	nb = 1;
	while(y > 0)
	{
		nb = nb * x;
		y--;
	}
	return (nb);
}