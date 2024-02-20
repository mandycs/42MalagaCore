/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:15:04 by mancorte          #+#    #+#             */
/*   Updated: 2023/05/04 00:13:10 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*char_s;
	char	*char_result;

	char_s = (char *)s;
	char_result = NULL;
	if ((char)c != '\0')
	{
		while (*char_s != '\0')
		{
			if (*char_s == (char)c)
			{
				char_result = char_s;
			}
			char_s++;
		}
	}
	if ((char)c == '\0')
		char_result = char_s + ft_strlen(char_s);
	return (char_result);
}
