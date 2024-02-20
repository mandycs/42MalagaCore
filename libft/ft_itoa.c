/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 23:39:16 by mancorte          #+#    #+#             */
/*   Updated: 2023/06/18 13:55:59 by mancorte         ###   ########.fr       */
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

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		i;

	i = 0;
	nb = n;
	str = (char *)malloc(sizeof(char) * (ft_numlen(n) + 1));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		nb = nb * -1;
	}
	while (nb > 9)
	{
		str[i++] = nb % 10 + 48;
		nb = nb / 10;
	}
	if (nb >= 0 && nb <= 9)
		str[i++] = nb + 48;
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	str = ft_invert(str);
	return (str);
}
