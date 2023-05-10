/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:09:53 by mancorte          #+#    #+#             */
/*   Updated: 2023/04/22 23:09:54 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * n);
	i = 0;
	while (i < n - 1)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
