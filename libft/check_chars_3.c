#include "libft.h"

int	ft_iscntrl(int c)
{
	if ((c >= 0 && c <= 31) || (c == 127))
		return (1);
	else
		return (0);
}

unsigned char	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

unsigned char	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
