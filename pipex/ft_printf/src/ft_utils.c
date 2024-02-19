/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:11:30 by mancorte          #+#    #+#             */
/*   Updated: 2023/05/28 16:52:06 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[i])
		ft_putchar_fd(str[i++], 1);
	return (i);
}

int	ft_printnbr(int nb)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_itoa(nb);
	len = ft_printstr(str);
	free(str);
	return (len);
}
