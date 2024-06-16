/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:04:36 by mancorte          #+#    #+#             */
/*   Updated: 2024/06/16 22:11:39 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		exit(1);
	ft_checkargs(argc, argv);
	return (0);
}

int	ft_prepare_stack(t_push_swap *ps, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_isdigit(argv[i]) == 0)
			i++;
		else
			return (1);
	}
	i = argc - 1;
	while (i >= 1)
	{
		ft_push(ps->stack_a, ft_atoi(argv[i]));
		i--;
	}
	if (ft_check_doubles(ps) == 1)
		return (1);
	ft_calc_sizes(ps);
	if (ps->stack_a->size > 3)
		ft_prepare_stack_a(ps);
	else
		ft_sort_three(ps->stack_a, ps);
	return (0);
}

void	ft_sort_three(t_stack *stack_a, t_push_swap *ps)
{
	int	top;
	int	middle;
	int	bottom;

	top = stack_a->head->value;
	middle = stack_a->head->next->value;
	bottom = stack_a->head->next->next->value;
	if (top > middle && middle < bottom && top < bottom)
		ft_swap_a(ps);
	else if (top < middle && middle > bottom && top > bottom)
		ft_reverse_rotate_a(ps);
	else if (top > middle && middle > bottom)
	{
		ft_swap_a(ps);
		ft_reverse_rotate_a(ps);
	}
	else if (top > middle && middle < bottom && top > bottom)
		ft_rotate_a(ps);
	else if (top < middle && middle > bottom && top < bottom)
	{
		ft_reverse_rotate_a(ps);
		ft_swap_a(ps);
	}
}

void	print_stack_a(t_stack *stack_a)
{
	t_node	*current;

	current = stack_a->head;
	while (current != NULL)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}
