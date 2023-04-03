#include "libft.h"

int	ft_iscntrl(int c)
{
	if ((c >= 0 && c <= 31) || (c == 127))
		return (1);
	else
		return (0);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

int	ft_atoi(char *str)
{
	int		c;
	long	nb;
	int		min;

	c = 0;
	nb = 0;
	min = 0;
	while (str[c] == 32 || (str[c] >= 9 && str[c] <= 13))
		c++;
	if (str[c] == '-')
	{
		min = 1;
		c++;
	}
	else if (str[c] == '+')
		c++;
	while (str[c] >= '0' && str[c] <= '9')
	{
		nb = nb * 10 + (str[c] - 48);
		c++;
	}
	if (min == 1)
		nb = nb * -1;
	return (nb);
}

double	ft_atof(char *str)
{
}