/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:50:05 by marvin            #+#    #+#             */
/*   Updated: 2024/03/19 13:50:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rotate_a(t_stack *stack_a)
{
	t_node *first;
	t_node *last;

	if (stack_a->size < 2)
		return ;
	first = stack_a->head;
	last = stack_a->head;
	while (last->next)
		last = last->next;
	stack_a->head = first->next;
	last->next = first;
	first->next = NULL;
}

void	ft_rotate_b(t_stack *stack_b)
{
	t_node *first;
	t_node *last;

	if (stack_b->size < 2)
		return ;
	first = stack_b->head;
	last = stack_b->head;
	while (last->next)
		last = last->next;
	stack_b->head = first->next;
	last->next = first;
	first->next = NULL;
}

void	ft_rotate_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate_a(stack_a);
	ft_rotate_b(stack_b);
}

void	ft_reverse_rotate_a(t_stack *stack_a)
{
	t_node *first;
	t_node *last;
	t_node *before_last;

	if (stack_a->size < 2)
		return ;
	first = stack_a->head;
	last = stack_a->head;
	before_last = stack_a->head;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	stack_a->head = last;
	before_last->next = NULL;
	last->next = first;
}

void	ft_reverse_rotate_b(t_stack *stack_b)
{
	t_node *first;
	t_node *last;
	t_node *before_last;

	if (stack_b->size < 2)
		return ;
	first = stack_b->head;
	last = stack_b->head;
	before_last = stack_b->head;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	stack_b->head = last;
	before_last->next = NULL;
	last->next = first;
}
