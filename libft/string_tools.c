#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlen_2(const char **s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*s1;

	i = 0;
	*s1 = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (s[i]);
		i++;
	}
	if (s[i] == c)
		return (s[i]);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*s1;

	i = 0;
	*s1 = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			*s1 = &s[i];
		i++;
	}
	if (s[i] == c)
	{
		*s1 = &s[i];
		return (s1);
	}
	return (s1);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(needle);
	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return (haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[j + i] == needle[j])
		{
			j++;
		}
		if (j == len)
			return (haystack[i]);
		i++;
	}
	return (0);
}
