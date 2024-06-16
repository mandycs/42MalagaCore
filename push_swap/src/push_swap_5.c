/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:40:19 by mancorte          #+#    #+#             */
/*   Updated: 2024/06/16 22:18:21 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_checkargs(int argc, char **argv)
{
	t_push_swap	*ps;

	if (argc == 2)
	{
		ps = init_structs();
		if (ft_prepare_stack_2(ps, argv) == 1)
		{
			free_push_swap(ps);
			exit(1);
		}
	}
	if (argc >= 4)
	{
		ps = init_structs();
		if (ft_prepare_stack(ps, argc, argv) == 1)
		{
			free_push_swap(ps);
			exit(1);
		}
	}
}

t_push_swap	*init_structs(void)
{
	t_push_swap	*ps;

	ps = malloc(sizeof(t_push_swap));
	if (!ps)
		exit(1);
	ps->stack_a = ft_create_stack();
	ps->stack_b = ft_create_stack();
	if (!ps->stack_a || !ps->stack_b)
	{
		free(ps->stack_a);
		free(ps->stack_b);
		free(ps);
		write(1, "Error\n", 6);
		exit(1);
	}
	return (ps);
}

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
void	ft_calcs(t_push_swap *ps)
{
	ft_sort_three(ps->stack_a, ps);
	ft_calc(ps);
	ft_sort_a(ps);
	free_push_swap(ps);
}
