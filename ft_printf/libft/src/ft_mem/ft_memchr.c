/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucortes <jucortes@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 02:36:13 by jucortes          #+#    #+#             */
/*   Updated: 2023/05/04 02:46:05 by jucortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*char_s;
	unsigned char	a;
	size_t			i;

	i = 0;
	char_s = (unsigned char *)s;
	a = (unsigned char)c;
	while (i < n)
	{
		if (*char_s == a)
			return (char_s);
		char_s++;
		i++;
	}
	return (NULL);
}
