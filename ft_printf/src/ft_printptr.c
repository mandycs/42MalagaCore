/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucortes <jucortes@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:22:31 by jucortes          #+#    #+#             */
/*   Updated: 2023/06/18 00:32:53 by jucortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_putptr(uintptr_t nb)
{
	if (nb >= 16)
	{
		ft_putptr(nb / 16);
		ft_putptr(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
			ft_putchar_fd((nb - 10 + 'a'), 1);
	}
}

int	ft_ptrlen(unsigned long long nb)
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

int	ft_printptr(unsigned long long ptr)
{
	int	pl;

	pl = 0;
	if (ptr == 0)
	{
		pl += write(1, "(nil)", 5);
		return (pl);
	}
	pl += write(1, "0x", 2);
	ft_putptr(ptr);
	pl += ft_ptrlen(ptr);
	return (pl);
}
