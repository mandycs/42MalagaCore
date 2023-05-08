/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:52:31 by mancorte          #+#    #+#             */
/*   Updated: 2023/05/07 20:35:22 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, unsigned int c)
{
	char	*str;
	char	b;

	str = (char *)s;
	b = (char)c;
	while (*str != '\0')
	{
		if (*str == b)
			return (str);
		str++;
	}
	if (b == '\0')
		return (str);
	return (NULL);
}