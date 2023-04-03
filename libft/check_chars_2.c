#include "libft.h"

int	ft_isxdigit(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A'
			&& c <= 'F'))
		return (1);
	else
		return (0);
}

int	ft_isgraph(int c)
{
	if (c >= '!' && c <= '~')
		return (1);
	else
		return (0);
}

int	ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}