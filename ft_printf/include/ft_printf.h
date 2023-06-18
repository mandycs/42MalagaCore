/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:31:28 by mancorte          #+#    #+#             */
/*   Updated: 2023/06/18 00:43:57 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

/**
 * @brief This function print exacly the same and 
 * works as a original printf()
 * 
 * @param str -> String as a param
 * @param ...  -> concatenation of multiples params
 * @return int -> Return de len of what is print
 */
int		ft_printf(char const *str, ...);
/**
 * @brief 
 * 
 * @param args 
 * @param format 
 * @return int 
 */
int		ft_cases(va_list args, const char format);
int		ft_printstr(char *str);
int		ft_printptr(unsigned long long pt);
char	*ft_uitoa(unsigned int n);
int		ft_printunbr(unsigned int nb);
int		ft_unumlen(unsigned int n);
int		ft_printptr(unsigned long long ptr);
int		ft_printnbr(int nb);
int		ft_printhex(unsigned int pt, char format);
int		ft_numlenhex(unsigned int nb);
void	ft_puthex(unsigned int nb, char format);
int		ft_ptrlen(unsigned long long nb);
void	ft_putptr(uintptr_t nb);
#endif