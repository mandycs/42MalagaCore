#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned long	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s) == c)
		{
			((void *)s);
			return (s);
		}
		else
			s++;
		i++;
	}
	return (0);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long	i;
	int				diff;

	i = 0;
	diff = 0;
	while (i < n)
	{
		if ((((unsigned char *)s1)[i]) - (((unsigned char *)s2)[i]) != 0)
			return (diff);
		else
			i++;
	}
	return (diff);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	if (dst == '\0' && src == '\0')
		return (0);
	while (i < len)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
