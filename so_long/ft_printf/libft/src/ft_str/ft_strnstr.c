/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:14:17 by mancorte          #+#    #+#             */
/*   Updated: 2023/05/04 02:25:25 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	p;
	size_t	p2;

	p = 0;
	p2 = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (p < len && haystack[p] != '\0')
	{
		p2 = 0;
		while ((p + p2) < len && p2 < ft_strlen(needle)
			&& haystack[p + p2] == needle[p2])
			p2++;
		if (p2 == ft_strlen(needle))
			return ((char *)haystack + p);
		p++;
	}
	return (NULL);
}
