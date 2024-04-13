/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 01:02:00 by mancorte          #+#    #+#             */
/*   Updated: 2024/04/13 22:15:22 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_move_up(t_push_swap *ps)
{
	if (ps->cheap_n->cos_a == 0 && ps->cheap_n->cos_b == 0)
		ft_push_a(ps);
	else if (ps->cheap_n->cos_a < 0 && ps->cheap_n->cos_b < 0)
	{
		ft_reverse_rotate_a(ps);
		ft_reverse_rotate_b(ps);
	}
	else if (ps->cheap_n->cos_a > 0 && ps->cheap_n->cos_b > 0)
	{
		ft_rotate_a(ps);
		ft_rotate_b(ps);
	}
	else if (ps->cheap_n->cos_a < 0)
		ft_reverse_rotate_a(ps);
	else if (ps->cheap_n->cos_a > 0)
		ft_rotate_a(ps);
	else if (ps->cheap_n->cos_b < 0)
		ft_reverse_rotate_b(ps);
	else if (ps->cheap_n->cos_b > 0)
		ft_rotate_b(ps);
}

void	ft_calc_sizes(t_push_swap *ps)
{
	t_node	*current;

	ps->stack_a->size = 0;
	current = ps->stack_a->head;
	while (current != NULL)
	{
		ps->stack_a->size++;
		current = current->next;
	}
	current = ps->stack_b->head;
	ps->stack_b->size = 0;
	while (current != NULL)
	{
		ps->stack_b->size++;
		current = current->next;
	}
}

void	ft_sort_a(t_push_swap *ps)
{
	t_node	*lower;

	ft_calc_pos(ps->stack_a);
	ft_calc_sizes(ps);
	lower = ft_get_lower(ps->stack_a);
	if (lower->act_pos > ps->stack_a->size / 2)
	{
		while (!ft_is_sort(ps->stack_a))
			ft_reverse_rotate_a(ps);
	}
	else
	{
		while (!ft_is_sort(ps->stack_a))
			ft_rotate_a(ps);
	}
}

t_node	*ft_get_lower(t_stack *stack)
{
	t_node	*tmp;
	t_node	*lower;

	tmp = stack->head;
	lower = tmp;
	if (!tmp)
		return (NULL);
	while (tmp)
	{
		if (tmp->value < lower->value)
			lower = tmp;
		tmp = tmp->next;
	}
	return (lower);
}

int	ft_is_sort(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
