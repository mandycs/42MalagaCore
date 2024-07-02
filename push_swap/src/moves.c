/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:04:30 by mancorte          #+#    #+#             */
/*   Updated: 2024/07/02 18:10:58 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_gen	ft_sort_2(t_gen gen)
{
	if (gen.stack_a->content > gen.stack_a->next->content)
		gen.stack_a = ft_sa(gen.stack_a, 1);
	return (gen);
}

t_gen	ft_pb(t_gen gen)
{
	t_stack	*tmp;

	if (gen.stack_a)
	{
		if (!gen.stack_b)
		{
			gen.stack_b = gen.stack_a;
			gen.stack_a = gen.stack_a->next;
			gen.stack_b->next = NULL;
		}
		else
		{
			tmp = gen.stack_b;
			gen.stack_b = gen.stack_a;
			gen.stack_a = gen.stack_a->next;
			gen.stack_b->next = tmp;
		}
	}
	write(1, "pb\n", 3);
	ft_set_pos(&gen.stack_a);
	ft_set_pos(&gen.stack_b);
	return (gen);
}

t_stack	*ft_sa(t_stack *stack_a, int flag)
{
	int	tmp;

	if (!stack_a || !stack_a->next)
		return (stack_a);
	tmp = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = tmp;
	if (flag)
		write(1, "sa\n", 3);
	ft_set_pos(&stack_a);
	return (stack_a);
}

t_gen	ft_pa(t_gen gen)
{
	t_stack	*tmp;

	if (gen.stack_b)
	{
		if (!gen.stack_a)
		{
			gen.stack_a = gen.stack_b;
			gen.stack_b = gen.stack_b->next;
			gen.stack_a->next = NULL;
		}
		else
		{
			tmp = gen.stack_a;
			gen.stack_a = gen.stack_b;
			gen.stack_b = gen.stack_b->next;
			gen.stack_a->next = tmp;
		}
	}
	write(1, "pa\n", 3);
	ft_set_pos(&gen.stack_a);
	ft_set_pos(&gen.stack_b);
	return (gen);
}

t_gen	ft_rrr(t_gen gen)
{
	gen.stack_a = ft_rra(gen.stack_a, 0);
	gen.stack_b = ft_rrb(gen.stack_b, 0);
	write(1, "rrr\n", 4);
	ft_set_pos(&gen.stack_a);
	ft_set_pos(&gen.stack_b);
	return (gen);
}
