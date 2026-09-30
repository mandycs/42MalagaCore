/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucortes <jucortes@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:11:58 by jucortes          #+#    #+#             */
/*   Updated: 2023/05/06 21:44:04 by jucortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*array;

	if (count != 0 && size > (size_t)-1 / count)
		return (NULL);
	array = (void *)malloc(size * count);
	if (!array)
		return (NULL);
	ft_bzero(array, size * count);
	return (array);
}
