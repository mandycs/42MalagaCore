/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:55:29 by mancorte          #+#    #+#             */
/*   Updated: 2024/07/02 18:11:22 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_gen	ft_rr(t_gen gen)
{
	gen.stack_a = ft_ra(gen.stack_a, 0);
	gen.stack_b = ft_rb(gen.stack_b, 0);
	write(1, "rr\n", 3);
	ft_set_pos(&gen.stack_a);
	ft_set_pos(&gen.stack_b);
	return (gen);
}

t_stack	*ft_rra(t_stack *stack_a, int flag)
{
	t_stack	*last;
	t_stack	*first;

	if (!stack_a || !stack_a->next)
		return (stack_a);
	first = stack_a;
	while (stack_a->next->next)
		stack_a = stack_a->next;
	last = stack_a->next;
	stack_a->next = NULL;
	last->next = first;
	if (flag)
		write(1, "rra\n", 4);
	ft_set_pos(&last);
	return (last);
}

t_stack	*ft_ra(t_stack *stack_a, int flag)
{
	int		tmp;
	t_stack	*first;

	if (!stack_a || !stack_a->next)
		return (stack_a);
	first = stack_a;
	stack_a = stack_a->next;
	while (stack_a->next)
	{
		tmp = stack_a->content;
		stack_a->content = stack_a->next->content;
		stack_a->next->content = tmp;
		stack_a = stack_a->next;
	}
	tmp = first->content;
	first->content = stack_a->content;
	stack_a->content = tmp;
	if (flag)
		write(1, "ra\n", 3);
	ft_set_pos(&first);
	return (first);
}

t_stack	*ft_rrb(t_stack *stack_b, int flag)
{
	t_stack	*last;
	t_stack	*first;

	if (!stack_b || !stack_b->next)
		return (stack_b);
	first = stack_b;
	while (stack_b->next->next)
		stack_b = stack_b->next;
	last = stack_b->next;
	stack_b->next = NULL;
	last->next = first;
	if (flag)
		write(1, "rrb\n", 4);
	ft_set_pos(&last);
	return (last);
}

t_gen	ft_fatality(t_gen gen)
{
	ft_set_pos(&gen.stack_a);
	gen.sizea = ft_get_size(gen.stack_a);
	gen.lower = ft_get_lower(gen.stack_a);
	if (gen.lower->act_pos > gen.sizea / 2)
	{
		while (!ft_is_sorted(gen.stack_a))
			gen.stack_a = ft_rra(gen.stack_a, 1);
	}
	else
	{
		while (!ft_is_sorted(gen.stack_a))
			gen.stack_a = ft_ra(gen.stack_a, 1);
	}
	return (gen);
}
