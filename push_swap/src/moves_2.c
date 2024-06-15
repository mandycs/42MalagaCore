/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:50:05 by marvin            #+#    #+#             */
/*   Updated: 2024/06/15 21:49:36 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rotate_a(t_push_swap *ps)
{
	t_node	*first;
	t_node	*last;

	if (ps->stack_a->size < 2)
		return ;
	first = ps->stack_a->head;
	last = ps->stack_a->head;
	while (last->next)
		last = last->next;
	ps->stack_a->head = first->next;
	last->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	ft_rotate_b(t_push_swap *ps)
{
	t_node	*first;
	t_node	*last;

	if (ps->stack_b->size < 2)
		return ;
	first = ps->stack_b->head;
	last = ps->stack_b->head;
	while (last->next)
		last = last->next;
	ps->stack_b->head = first->next;
	last->next = first;
	first->next = NULL;
	write(1, "rb\n", 3);
}

void	ft_rotate_rr(t_push_swap *ps)
{
	ft_rotate_a(ps);
	ft_rotate_b(ps);
	ft_calc_sizes(ps);
	write(1, "rr\n", 3);
}

void	ft_reverse_rotate_a(t_push_swap *ps)
{
	t_node	*first;
	t_node	*last;
	t_node	*before_last;

	if (ps->stack_a->size < 2)
		return ;
	first = ps->stack_a->head;
	last = ps->stack_a->head;
	before_last = ps->stack_a->head;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	ps->stack_a->head = last;
	before_last->next = NULL;
	last->next = first;
	write(1, "rra\n", 4);
}

void	ft_reverse_rotate_b(t_push_swap *ps)
{
	t_node	*first;
	t_node	*last;
	t_node	*before_last;

	if (ps->stack_b->size < 2)
		return ;
	first = ps->stack_b->head;
	last = ps->stack_b->head;
	before_last = ps->stack_b->head;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	ps->stack_b->head = last;
	before_last->next = NULL;
	last->next = first;
	write(1, "rrb\n", 4);
}
