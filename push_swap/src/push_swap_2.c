/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:50:47 by marvin            #+#    #+#             */
/*   Updated: 2024/04/02 23:50:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_prepare_stack_2(t_push_swap *ps, int argc, char **argv)
{
	int i;

	i = 0;
	while (i < argc)
	{
		if (ft_isdigit(argv[1][i]) == 0)
			i++;
		else
			return (1);
	}

	return (0);
}
