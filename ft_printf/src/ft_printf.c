/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucortes <jucortes@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:36:16 by jucortes          #+#    #+#             */
/*   Updated: 2023/06/18 00:23:12 by jucortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_isconv(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'i' || c == 'd'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

static int	ft_valid(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '\0' || !ft_isconv(s[i + 1]))
				return (0);
			i++;
		}
		i++;
	}
	return (1);
}

static int	ft_ploop(char const *s, va_list args)
{
	int	pl;
	int	i;

	pl = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			pl += ft_cases(args, s[i + 1]);
			i++;
		}
		else
			pl += write(1, &s[i], 1);
		i++;
	}
	return (pl);
}

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
	else if (format == 'x' || format == 'X')
		pl += ft_printhex(va_arg(args, unsigned int), format);
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

	if (str == NULL)
		return (write(1, "(null)", 6));
	va_start(args, str);
	if (!ft_valid(str))
	{
		va_end(args);
		return (-1);
	}
	pl = ft_ploop(str, args);
	va_end(args);
	return (pl);
}
