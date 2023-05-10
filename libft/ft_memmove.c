/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:52:45 by mancorte          #+#    #+#             */
/*   Updated: 2023/05/03 19:13:03 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;
	char	*char_src;
	char	*char_dest;

	char_src = (char *)src;
	char_dest = (char *)dest;
	i = 0;
	if ((char)dest == '\0' && (char)src == '\0')
		return (dest);
	if (dest > src)
	{
		while (len--)
		{
			char_dest[len] = char_src[len];
		}
	}
	else
	{
		while (i < len)
		{
			char_dest[i] = char_src[i];
			i++;
		}
	}
	return (dest);
}
