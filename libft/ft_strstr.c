/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:15:17 by mancorte          #+#    #+#             */
/*   Updated: 2023/04/22 23:15:21 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
