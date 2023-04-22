/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:50:16 by mancorte          #+#    #+#             */
/*   Updated: 2023/04/22 22:50:16 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long	i;
	int				diff;

	i = 0;
	diff = 0;
	while (i < n)
	{
		if ((((unsigned char *)s1)[i]) - (((unsigned char *)s2)[i]) != 0)
			return (diff);
		else
			i++;
	}
	return (diff);
}
