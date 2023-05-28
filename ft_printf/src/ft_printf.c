/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:36:16 by mancorte          #+#    #+#             */
/*   Updated: 2023/05/28 18:11:26 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_cases(va_list args, const char format)
{
	int	pl;

	pl = 0;
	if (format == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		pl += 1;
	}
	else if (format == 's')
		pl += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		pl += ft_printptr(va_arg(args, unsigned long long));
	else if (format == 'i' || format == 'd')
		pl += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		pl += ft_printunbr(va_arg(args, unsigned int));
	else if (format == 'x')
		pl += ft_printhex(va_arg(args, unsigned long long));
	else if (format == '%')
	{
		ft_putchar_fd('%', 1);
		pl += 1;
	}
	return (pl);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		pl;
	int		i;

	va_start(args, str);
	pl = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			pl += ft_cases(args, str[i + 1]);
			i++;
		}
		else
			pl += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (pl);
}
