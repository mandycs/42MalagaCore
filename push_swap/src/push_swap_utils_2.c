/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:12:58 by marvin            #+#    #+#             */
/*   Updated: 2024/04/10 19:19:27 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (len > s_len)
		len = s_len;
	if (start >= s_len)
	{
		str = (char *)malloc(1);
		if (!str)
			return (NULL);
		str[i] = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!s || !str)
		return (NULL);
	while (i < start)
		i++;
	ft_strlcpy(str, &s[i], len + 1);
	return (str);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = -1;
	if (dstsize > 0)
	{
		while (++i < dstsize - 1 && src[i] != '\0')
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
