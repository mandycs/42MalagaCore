/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:55:24 by mancorte          #+#    #+#             */
/*   Updated: 2023/05/29 20:43:31 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printhex(unsigned long long nb, char format)
{
	int	pl;

	pl = 0;
	if (nb == 0)
		return (write(1, '0', 1));
	else 
	{
		pl = ft_numlenhex(nb);
		ft_printhex(nb, format);
	}
	return (pl);
}

void	ft_printhex(unsigned long long nb, char format)
{
	if (nb >= 16)
	{
		ft_tohex(nb / 16);
		ft_tohex(nb % 16);
	}
	else if (nb >= 9)
		ft_putchar_fd(nb + 48, 1);
	else
	{
		if (format == 'x')
			ft_putchar_fd((nb - 10 + 'a'), 1);
		else if (format == 'X')
			ft_putchar_fd((nb - 10 + 'A'), 1);
	}
}

int	ft_numlenhex(unsigned long long nb)
{
	
}