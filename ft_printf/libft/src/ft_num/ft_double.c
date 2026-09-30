/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucortes <jucortes@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:37:06 by jucortes          #+#    #+#             */
/*   Updated: 2023/04/22 23:55:09 by jucortes         ###   ########.fr       */
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
