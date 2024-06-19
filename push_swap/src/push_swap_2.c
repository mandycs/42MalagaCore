/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:44:32 by mancorte          #+#    #+#             */
/*   Updated: 2024/06/19 16:56:50 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_parse(t_stack *stack)
{
	t_stack	*tmp;
	t_stack *tmp2;
	int		i;
	
	tmp = stack;
	i = 0;
	while(tmp)
	{
		tmp2 = stack;
		if (tmp->content == 0 || tmp->content == -0 || tmp->content == +0)
			i++;
		while (tmp2)
		{
			if (tmp->content == tmp2->content && tmp2->act_pos != tmp->act_pos)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	if (i > 1)
		return (0);
	return (1);
}

int	ft_max_int(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->content > 2147483647 || tmp->content < -2147483648)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_error(t_stack *stack)
{
	if (ft_parse(stack) == 0)
	{
		write(1, "[ERROR] Input\n", 14);
		stack = ft_clean_stack(stack);
		return (0);
	}
	if (ft_max_int(stack) == 0)
	{
		write(1, "[ERROR] Input\n", 14);
		stack = ft_clean_stack(stack);
		return (0);
	}
	return (1);
}

int	ft_is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->next && tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_stack	*ft_sort_three(t_stack *stack_a)
{
	int	n;
	int	m;
	int	l;

	n = stack_a->content;
	m = stack_a->next->content;
	l = stack_a->next->next->content;
	if (n > m && m < l && n < l)
		stack_a = ft_sa(stack_a, 1);
	else if (n < m && m > l && n > l)
		stack_a = ft_rra(stack_a, 1);
	else if (n > m && m > l)
	{
		stack_a = ft_sa(stack_a, 1);
		stack_a = ft_rra(stack_a, 1);
	}
	else if (n > m && m < l && n > l)
		stack_a = ft_ra(stack_a, 1);
	else if (n < m && m > l && n < l)
	{
		stack_a = ft_rra(stack_a, 1);
		stack_a = ft_sa(stack_a, 1);
	}
	return (stack_a);
}
