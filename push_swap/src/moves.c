/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:41:59 by marvin            #+#    #+#             */
/*   Updated: 2024/06/15 18:29:10 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap_a(t_push_swap *ps)
{
	t_node	*first;
	t_node	*second;

	if (ps->stack_a->size < 2)
		return ;
	first = ps->stack_a->head;
	second = first->next;
	ps->stack_a->head = second;
	first->next = second->next;
	second->next = first;
	printf("sa\n");
}

void	ft_swap_b(t_push_swap *ps)
{
	t_node	*first;
	t_node	*second;

	if (ps->stack_b->size < 2)
		return ;
	first = ps->stack_b->head;
	second = first->next;
	ps->stack_b->head = second;
	first->next = second->next;
	second->next = first;
	write(1, "sb\n", 3);
}

void	ft_swap_ss(t_push_swap *ps)
{
	ft_swap_a(ps);
	ft_swap_b(ps);
	ft_calc_sizes(ps);
	write(1,"ss\n", 3);
}

void	ft_push_a(t_push_swap *ps)
{
	t_node	*first;

	if (ps->stack_b->size == 0)
		return ;
	first = ps->stack_b->head;
	ps->stack_b->head = first->next;
	first->next = ps->stack_a->head;
	ps->stack_a->head = first;
	ft_calc_sizes(ps);
	write(1,"pa\n",3);
}

void	ft_push_b(t_push_swap *ps)
{
	t_node	*first;

	if (ps->stack_a->size == 0)
		return ;
	first = ps->stack_a->head;
	ps->stack_a->head = first->next;
	first->next = ps->stack_b->head;
	ps->stack_b->head = first;
	ft_calc_sizes(ps);
	write(1,"pb\n",3);
}
