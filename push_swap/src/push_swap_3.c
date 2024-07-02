/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:58:01 by mancorte          #+#    #+#             */
/*   Updated: 2024/07/02 18:12:58 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_cheap(t_stack *stack_b)
{
	t_stack	*tmp;
	t_stack	*cheap;

	tmp = stack_b;
	cheap = tmp;
	while (tmp)
	{
		if (ft_pos(tmp->cos_a) + ft_pos(tmp->cos_b) < ft_pos(cheap->cos_a)
			+ ft_pos(cheap->cos_b))
			cheap = tmp;
		tmp = tmp->next;
	}
	return (cheap);
}

t_gen	ft_calc_cost(t_gen gen)
{
	t_stack	*tmp;

	tmp = gen.stack_b;
	while (tmp)
	{
		tmp->cos_b = tmp->act_pos;
		if (tmp->act_pos > ft_get_size(gen.stack_b) / 2)
			tmp->cos_b = ft_get_size(gen.stack_b) - tmp->act_pos * -1;
		tmp->cos_a = tmp->tar_pos;
		if (tmp->tar_pos > ft_get_size(gen.stack_a) / 2)
			tmp->cos_a = ft_get_size(gen.stack_a) - tmp->tar_pos * -1;
		tmp = tmp->next;
	}
	return (gen);
}

int	ft_get_pos(t_stack *stack_a, int content, int targ, int max)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		if (content < tmp->content && tmp->content < max)
		{
			max = tmp->content;
			targ = tmp->act_pos;
		}
		tmp = tmp->next;
	}
	if (max != 2147483647)
		return (targ);
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->content < max)
		{
			max = tmp->content;
			targ = tmp->act_pos;
		}
		tmp = tmp->next;
	}
	return (targ);
}

t_gen	ft_set_targ(t_gen gen)
{
	t_stack	*tmp;
	int		targ;

	targ = 0;
	tmp = gen.stack_b;
	while (tmp)
	{
		if (tmp->content == 2147483647)
			targ = gen.sizea;
		else
			targ = ft_get_pos(gen.stack_a, tmp->content, targ, 2147483647);
		tmp->tar_pos = targ;
		tmp = tmp->next;
	}
	return (gen);
}

t_gen	ft_sort(t_gen gen)
{
	ft_set_pos(&gen.stack_a);
	gen.sizea = ft_get_size(gen.stack_a);
	while (ft_get_size(gen.stack_a) > 3)
		gen = ft_pb(gen);
	if (ft_get_size(gen.stack_a) == 2)
		return (ft_sort_2(gen));
	else
		gen.stack_a = ft_sort_three(gen.stack_a);
	while (gen.stack_b)
	{
		gen = ft_set_targ(gen);
		gen = ft_calc_cost(gen);
		gen = ft_move_up(gen, ft_cheap(gen.stack_b));
	}
	gen = ft_fatality(gen);
	return (gen);
}
