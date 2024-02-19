/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 23:39:16 by mancorte          #+#    #+#             */
/*   Updated: 2023/05/08 01:50:05 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
