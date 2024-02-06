/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:12:58 by mancorte          #+#    #+#             */
/*   Updated: 2023/04/22 23:54:44 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < n && s1[i] != '\0')
	{
		s1[len] = s2[i];
		len++;
		i++;
	}
	s1[len] = '\0';
	len++;
	i++;
	while (i < n)
	{
		s1[len] = '\0';
		len++;
		i++;
	}
	return (s1);
}
