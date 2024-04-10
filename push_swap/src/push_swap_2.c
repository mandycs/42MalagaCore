/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:50:47 by marvin            #+#    #+#             */
/*   Updated: 2024/04/10 20:02:03 by mancorte         ###   ########.fr       */
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
	i = 0;
	while (i < ps->n_str)
	{
		ft_push(ps->stack_b, ft_atoi(ps->split[i]));
		i++;
	}
	return (0);
}

int	ft_check_doubles(t_push_swap *ps)
{
	t_node	*current;
	t_node	*tmp;

	current = ps->stack_b->head;
	while (current != NULL)
	{
		tmp = current->next;
		while (tmp != NULL)
		{
			if (current->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		current = current->next;
	}
	return (0);
}

t_stack	*ft_create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->head = NULL;
	stack->size = 0;
	return (stack);
}
