/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:37:06 by mancorte          #+#    #+#             */
/*   Updated: 2023/04/22 23:55:09 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_double(double x, double y)
{
	double	nb;

	nb = 1;
	while (y > 0)
	{
		nb = nb * x;
		y--;
	}
	return (nb);
}
