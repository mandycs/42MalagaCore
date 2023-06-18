/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:55:24 by mancorte          #+#    #+#             */
/*   Updated: 2023/06/18 00:21:00 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_puthex(unsigned int nb, char format)
{
	if (nb >= 16)
	{
		ft_puthex(nb / 16, format);
		ft_puthex(nb % 16, format);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd(nb + '0', 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((nb - 10 + 'a'), 1);
			else if (format == 'X')
				ft_putchar_fd((nb - 10 + 'A'), 1);
		}
	}
}

int	ft_numlenhex(unsigned int nb)
{
	int	pl;

	pl = 0;
	while (nb != 0)
	{
		pl++;
		nb = nb / 16;
	}
	return (pl);
}

int	ft_printhex(unsigned int nb, char format)
{
	if (nb == 0)
		return (write(1, "0", 1));
	else
		ft_puthex(nb, format);
	return (ft_numlenhex(nb));
}
