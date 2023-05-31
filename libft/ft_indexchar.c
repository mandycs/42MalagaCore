/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:28:00 by mancorte          #+#    #+#             */
/*   Updated: 2023/05/31 13:10:27 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_indexchar(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i++] != '\0')
	{
		if (s[i] == c)
			return (i);
	}
	return (0);
}
