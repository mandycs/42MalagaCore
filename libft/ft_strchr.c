/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:52:31 by mancorte          #+#    #+#             */
/*   Updated: 2023/04/23 01:37:10 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*s1;

	s1 = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			*s1 = s[i];
			return (s1);
		}
		i++;
	}
	if (s[i] == c)
	{
		*s1 = s[i];
		return (s1);
	}
	return (NULL);
}
