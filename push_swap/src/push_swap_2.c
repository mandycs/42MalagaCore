/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:50:47 by marvin            #+#    #+#             */
/*   Updated: 2024/06/16 22:19:54 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_prepare_stack_2(t_push_swap *ps, char **argv)
{
	int	i;

	i = 0;
	ps->split = ft_split(argv[1], ' ', ps);
	while (i < ps->n_str)
	{
		if (ft_isdigit(ps->split[i]) == 1)
			return (1);
		i++;
	}
	i = ps->n_str - 1;
	while (i >= 0)
	{
		ft_push(ps->stack_a, ft_atoi(ps->split[i]));
		i--;
	}
	if (ft_check_doubles(ps) == 1)
	{
		free_push_swap(ps);
		return (1);
	}
	if (ps->stack_a->size > 3)
		ft_prepare_stack_a(ps);
	else
		ft_sort_three(ps->stack_a, ps);
	return (0);
}

int	ft_check_doubles(t_push_swap *ps)
{
	t_node	*current;
	t_node	*tmp;
	int		i;

	i = 0;
	current = ps->stack_a->head;
	while (i < ps->stack_a->size)
	{
		tmp = current->next;
		while (tmp != NULL)
		{
			if (current->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		current = current->next;
		i++;
	}
	return (0);
}

t_stack	*ft_create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->size = 0;
	return (stack);
}

void	ft_calc_pos(t_stack *stack)
{
	t_node	*current;
	int		pos;

	current = stack->head;
	pos = 0;
	while (current != NULL)
	{
		current->act_pos = pos;
		pos++;
		current = current->next;
	}
}

void	ft_calc(t_push_swap *ps)
{
	ft_calc_pos(ps->stack_a);
	ft_calc_pos(ps->stack_b);
	ft_calc_sizes(ps);
	while (ps->stack_b->size > 0)
	{
		ft_calc_targ_pos(ps);
		calculate_costs(ps);
		ps->cheap_n = find_cheapest_node(ps->stack_b);
		ft_move_up(ps);
		ft_calc_pos(ps->stack_a);
		ft_calc_pos(ps->stack_b);
		ft_calc_sizes(ps);
	}
	ft_sort_a(ps);
}
