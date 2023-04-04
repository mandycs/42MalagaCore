#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;

	i = 0;
	j = 0;
	n_len = ft_strlen(needle);
	while (i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j])
			j++;
		if (j == len)
			return (haystack[i]);
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	int		diff;

	i = 0;
	diff = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		diff = (s1[i] - s2[i]);
		if (diff != 0)
			return (diff);
		i++;
	}
	return (diff);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	diff = 0;
	while (i < n && s1 && s2)
	{
		diff = (s1[i] - s2[i]);
		if (diff != 0)
			return (diff);
		i++;
	}
	return (diff);
}

int	ft_strnrcmp(const char *s1, const char *s2, size_t n)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	int		diff;

	diff = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	while (len1 >= 0 && len2 >= 0 && i < n)
	{
		diff = (s1[len1] - s2[len2]);
		if (diff != 0)
			;
		return (diff);
		len1--;
		len2--;
		i++;
	}
	return (diff);
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
