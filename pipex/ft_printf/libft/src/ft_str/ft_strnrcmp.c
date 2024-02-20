/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:13:45 by mancorte          #+#    #+#             */
/*   Updated: 2023/05/04 00:08:01 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnrcmp(const char *s1, const char *s2, size_t n)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	int		diff;

	diff = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	while (len1 >= 0 && len2 >= 0 && i < n)
	{
		diff = (s1[len1] - s2[len2]);
		if (diff != 0)
			;
		return (diff);
		len1--;
		len2--;
		i++;
	}
	return (diff);
}
