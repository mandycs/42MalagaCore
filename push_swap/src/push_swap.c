/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:04:36 by mancorte          #+#    #+#             */
/*   Updated: 2024/04/10 23:35:36 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	*ps;

	ps = malloc(sizeof(t_push_swap));
	ps->stack_a = ft_create_stack();
	ps->stack_b = ft_create_stack();
	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		if (ft_prepare_stack_2(ps, argv) == 1)
			return (1);
	}
	else
	{
		if (ft_prepare_stack(ps, argc, argv) == 1)
			return (1);
	}
	print_stack_a(ps->stack_a);
	ft_sort_three(ps->stack_a);
	print_stack_a(ps->stack_a);
	return (0);
}

t_stack	*ft_init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->size = 0;
	return (stack);
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
	i = 0;
	while (i < argc)
	{
		ft_push(ps->stack_b, ft_atoi(argv[i]));
		i++;
	}
	if (ft_check_doubles(ps) == 1)
		return (1);
	if (ps->stack_b->size >= 3)
		ft_prepare_stack_a(ps);
	else
		return (1);
	return (0);
}

void	ft_sort_three(t_stack *stack_a)
{
	int top = stack_a->head->value;
	int middle = stack_a->head->next->value;
	int bottom = stack_a->head->next->next->value;

	if (top > middle && middle < bottom && top < bottom)
		ft_swap_a(stack_a);
	else if (top < middle && middle > bottom && top > bottom)
		ft_reverse_rotate_a(stack_a);
	else if (top > middle && middle > bottom)
	{
		ft_swap_a(stack_a);
		ft_reverse_rotate_a(stack_a);
	}
	else if (top > middle && middle < bottom && top > bottom)
		ft_rotate_a(stack_a);
	else if (top < middle && middle > bottom && top < bottom)
	{	
		ft_reverse_rotate_a(stack_a);
		ft_swap_a(stack_a);
	}
}

void print_stack_a(t_stack * stack_a)
{
	t_node *current = stack_a->head;

	while (current != NULL)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}
