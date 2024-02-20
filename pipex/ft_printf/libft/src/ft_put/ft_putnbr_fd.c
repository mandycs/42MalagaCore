/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:15:50 by mancorte          #+#    #+#             */
/*   Updated: 2023/05/08 12:14:43 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_int_to_char(int nb, int fd)
{
	char	str[11];
	int		temp;
	int		i;

	temp = 0;
	i = 0;
	while (nb != 0)
	{
		temp = nb % 10;
		nb = nb / 10;
		str[i] = temp + 48;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(fd, &str[i], 1);
		i--;
	}
}

void	ft_putnbr(int nb, int fd)
{
	if (nb == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = nb * (-1);
		write(fd, "-", 1);
	}
	if (nb != 0)
		ft_int_to_char(nb, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr(n, fd);
}
