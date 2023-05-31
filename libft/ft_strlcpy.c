/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:05:41 by mancorte          #+#    #+#             */
/*   Updated: 2023/05/31 15:11:49 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = -1;
	if (dstsize > 0)
	{
		while (++i < dstsize - 1 && src[i] != '\0')
		{	
			dst[i] = src[i];
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
