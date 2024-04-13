/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:32:26 by mancorte          #+#    #+#             */
/*   Updated: 2024/04/13 22:15:54 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_calc_targ_pos(t_push_swap *ps)
{
	t_node	*node_b;
	int		maxint;

	node_b = ps->stack_b->head;
	maxint = 2147483647;
	while (node_b)
	{
		ft_get_pos(ps->stack_a, node_b->value, maxint, ps);
		node_b->targ_pos = ps->closestpos;
		node_b = node_b->next;
	}
}

void	calculate_costs(t_push_swap *ps)
{
	t_node	*node;

	node = ps->stack_b->head;
	while (node != NULL)
	{
		node->cos_b = node->act_pos;
		if (node->act_pos > ps->stack_b->size / 2)
			node->cos_b = (ps->stack_b->size - node->act_pos) * -1;
		node->cos_a = node->targ_pos;
		if (node->targ_pos > ps->stack_a->size / 2)
			node->cos_a = (ps->stack_a->size - node->targ_pos) * -1;
		node = node->next;
	}
}

int	calculate_cos_a(int targ_pos, int total)
{
	int	forward;
	int	backward;

	forward = targ_pos;
	backward = total - targ_pos;
	if (forward < backward)
		return (forward);
	else
		return (backward);
}

t_node	*find_cheapest_node(t_stack *stack)
{
	t_node	*cheapest_node;
	int		min_cost;
	t_node	*current_node;

	if (stack == NULL || stack->head == NULL)
		return (NULL);
	cheapest_node = stack->head;
	min_cost = cheapest_node->tot_cos;
	current_node = cheapest_node->next;
	while (current_node != NULL)
	{
		if (current_node->tot_cos < min_cost)
		{
			min_cost = current_node->tot_cos;
			cheapest_node = current_node;
		}
		current_node = current_node->next;
	}
	return (cheapest_node);
}

void	ft_get_pos(t_stack *stack_a, int num, int maxint, t_push_swap *ps)
{
	find_closest_above(stack_a, num, maxint, ps);
	if (ps->closestpos == -1)
		find_min_value(stack_a, maxint, ps);
}
