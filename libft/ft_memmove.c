/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:52:45 by mancorte          #+#    #+#             */
/*   Updated: 2023/05/31 13:30:09 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*char_src;
	char	*char_dest;

	char_src = (char *)src;
	char_dest = (char *)dest;
	if (dest == NULL && src == NULL)
		return (dest);
	if (dest > src)
	{
		while (len--)
			char_dest[len] = char_src[len];
	}
	else
	{
		while (len--)
			*char_dest++ = *char_src++;
	}
	return (dest);
}
