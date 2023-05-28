/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:31:28 by mancorte          #+#    #+#             */
/*   Updated: 2023/05/28 18:07:51 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(char const *str, ...);
int		ft_cases(va_list args, const char format);
int		ft_printstr(char *str);
int		ft_printptr(unsigned long long pt);
char	*ft_uitoa(unsigned int n);
int		ft_printunbr(unsigned int nb);
int		ft_unumlen(unsigned int n);
int		ft_printptr(unsigned long long pt);
int		ft_printnbr(int nb);
int		ft_printhex(unsigned long long pt);
#endif