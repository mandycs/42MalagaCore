/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:23:08 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/21 00:15:02 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_unumlen(unsigned int n)
{
	unsigned int	i;

	i = 0;

	if (n <= 9)
	{
		i++;
		return (i);
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char			*str;
	unsigned int	nb;
	unsigned int	i;

	i = 0;
	nb = n;
	str = (char *)malloc(sizeof(char) * (ft_unumlen(n) + 1));
	if (!str)
		return (NULL);
	while (nb > 9)
	{
		str[i++] = nb % 10 + 48;
		nb = nb / 10;
	}
	if (nb <= 9)
		str[i++] = nb + 48;
	str[i] = '\0';
	str = ft_invert(str);
	return (str);
}

int	ft_printunbr(unsigned int nb)
{
	int		pl;
	char	*s;

	pl = 0;
	s = ft_uitoa(nb);
	pl = ft_printstr(s);
	free(s);
	return (pl);
}
