/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:53:21 by marvin            #+#    #+#             */
/*   Updated: 2024/04/10 23:45:48 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_reverse_rotate_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_reverse_rotate_a(stack_a);
	ft_reverse_rotate_b(stack_b);
	printf("rrr\n");
}

void	ft_prepare_stack_a(t_push_swap *ps)
{
	ft_push_a(ps->stack_a, ps->stack_b);
	ft_push_a(ps->stack_a, ps->stack_b);
	ft_push_a(ps->stack_a, ps->stack_b);
}

int	ft_push(t_stack *stack, int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (1);
	new->value = value;
	new->act_pos = 0;
	new->targ_pos = 0;
	new->cos_a = 0;
	new->cos_b = 0;
	new->next = stack->head;
	stack->head = new;
	stack->size++;
	return (0);
}
