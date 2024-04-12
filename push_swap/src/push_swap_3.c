/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:32:26 by mancorte          #+#    #+#             */
/*   Updated: 2024/04/12 03:36:54 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_calc_targ_pos(t_push_swap *ps)
{
	ps->node_b = ps->stack_b->head;
	while (ps->node_b)
	{
		ps->node_a = ps->stack_a->head;
		ps->pos = 0;
		ps->pos_found = 0;
		while (ps->node_a && !ps->pos_found)
		{
			if (!ps->node_a->next || ps->node_b->value < ps->node_a->value
				|| (ps->node_b->value > ps->node_a->value
					&& ps->node_b->value < ps->node_a->next->value))
			{
				ps->node_b->targ_pos = ps->pos + (ps->node_a->next != NULL
						&& ps->node_b->value > ps->node_a->value);
				ps->pos_found = 1;
			}
			else if (ps->node_b->value < ps->node_a->value && ps->pos == 0)
				ps->node_b->targ_pos = ps->pos, ps->pos_found = 1;
			ps->pos++, ps->node_a = ps->node_a->next;
		}
		if (!ps->pos_found)
			ps->node_b->targ_pos = ps->pos;
		ps->node_b = ps->node_b->next;
	}
}

void	calculate_costs(t_push_swap *ps)
{
	t_node	*node;

	node = ps->stack_b->head;
	ps->half_b = ps->stack_b->size / 2;
	while (node != NULL)
	{
		if (node->act_pos <= ps->half_b)
			node->cos_b = node->act_pos;
		else
			node->cos_b = -(ps->stack_b->size - node->act_pos);
		node->cos_a = calculate_cos_a(node->targ_pos, ps->stack_a->size);
		node->tot_cos = ft_abs(node->cos_b) +ft_abs(node->cos_a);
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

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

t_node *find_cheapest_node(t_stack *stack) {
    if (stack == NULL || stack->head == NULL) {
        return NULL;  // Asegura que hay nodos para procesar
    }

    t_node *cheapest_node = stack->head;
    int min_cost = cheapest_node->tot_cos;
    t_node *current_node = cheapest_node->next;

    while (current_node != NULL) {
        if (current_node->tot_cos < min_cost) {
            min_cost = current_node->tot_cos;
            cheapest_node = current_node;
        }
        current_node = current_node->next;
    }

    return cheapest_node;
}
