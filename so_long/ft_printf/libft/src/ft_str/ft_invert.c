/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:09:55 by mancorte          #+#    #+#             */
/*   Updated: 2023/05/08 01:16:43 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_invert(char *s1)
{
	size_t	i;
	size_t	j;
	char	temp;

	i = 0;
	j = (ft_strlen(s1) - 1);
	temp = '0';
	while (i < (ft_strlen(s1)) / 2)
	{
		temp = s1[i];
		s1[i] = s1[j];
		s1[j] = temp;
		i++;
		j--;
	}
	return (s1);
}
