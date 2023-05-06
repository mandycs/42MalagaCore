/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:14:17 by mancorte          #+#    #+#             */
/*   Updated: 2023/04/23 01:34:43 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;
	char	*s1;

	s1 = NULL;
	i = 0;
	j = 0;
	n_len = ft_strlen(needle);
	while (i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j])
			j++;
		if (j == len)
		{	
			*s1 = haystack[i];
			return (s1);
		}
	}
	return (0);
}
