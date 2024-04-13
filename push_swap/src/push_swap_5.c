/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:40:19 by mancorte          #+#    #+#             */
/*   Updated: 2024/04/13 22:15:33 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	find_closest_above(t_stack *stack_a, int num, int maxint,
		t_push_swap *ps)
{
	ps->current = stack_a->head;
	ps->pos = 0;
	ps->closestpos = -1;
	while (ps->current)
	{
		if (ps->current->value > num && ps->current->value < maxint)
		{
			maxint = ps->current->value;
			ps->closestpos = ps->pos;
		}
		ps->current = ps->current->next;
		ps->pos++;
	}
}

void	find_min_value(t_stack *stack_a, int maxint, t_push_swap *ps)
{
	ps->current = stack_a->head;
	ps->pos = 0;
	while (ps->current)
	{
		if (ps->current->value < maxint)
		{
			maxint = ps->current->value;
			ps->closestpos = ps->pos;
		}
		ps->current = ps->current->next;
		ps->pos++;
	}
}
