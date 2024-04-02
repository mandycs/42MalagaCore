/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:41:59 by marvin            #+#    #+#             */
/*   Updated: 2024/03/19 13:41:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void ft_swap_a(t_stack *stack_a)
{
	t_node *first;
	t_node *second;

	if (stack_a->size < 2)
		return ;
	first = stack_a->head;
	second = first->next;
	stack_a->head = second;
	first->next = second->next;
	second->next = first;
}

void ft_swap_b(t_stack *stack_b)
{
	t_node *first;
	t_node *second;

	if (stack_b->size < 2)
		return ;
	first = stack_b->head;
	second = first->next;
	stack_b->head = second;
	first->next = second->next;
	second->next = first;
}

void ft_swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap_a(stack_a);
	ft_swap_b(stack_b);
}

void ft_push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node *first;

	if (stack_b->size == 0)
		return ;
	first = stack_b->head;
	stack_b->head = first->next;
	first->next = stack_a->head;
	stack_a->head = first;
	stack_a->size++;
	stack_b->size--;
}

void ft_push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node *first;

	if (stack_a->size == 0)
		return ;
	first = stack_a->head;
	stack_a->head = first->next;
	first->next = stack_b->head;
	stack_b->head = first;
	stack_b->size++;
	stack_a->size--;
}