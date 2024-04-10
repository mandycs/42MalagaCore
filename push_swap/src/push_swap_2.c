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

#include "../include/push_swap.h"

int ft_prepare_stack_2(t_push_swap *ps, char **argv)
{
	int i;

	i = 0;
	if (ft_isdigit(argv[1]) == 1)
		return (1);
	ps->split = ft_split(argv[1], ' ', ps);
	while (i < ps->n_str)
	{
		ft_push(ps->stack_b, ft_atoi(ps->split[i]));
		i++;
	}
	return (0);
}

int	ft_check_doubles(t_push_swap *ps)
{
	t_node *current;
	t_node *tmp;

	current = ps->stack_b->head;
	while (current != NULL)
	{
		tmp = current->next;
		while (tmp != NULL)
		{
			if (current->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		current = current->next;
	}
	return (0);
}
