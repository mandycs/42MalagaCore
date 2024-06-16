/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 09:38:44 by mancorte          #+#    #+#             */
/*   Updated: 2024/06/16 09:54:33 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;
	int		i;

	i = 0;
	current = stack->head;
	while (i < stack->size)
	{
		tmp = current->next;
		free(current);
		current = tmp;
		i++;
	}
	free(stack);
}

void free_stacks(t_push_swap *ps)
{
    if (ps)
    {
        if (ps->stack_a)
            ft_free_stack(ps->stack_a);
        if (ps->stack_b)
            ft_free_stack(ps->stack_b);
    }
}
void free_split(char **split)
{
    if (split)
    {
        char **ptr = split;
        while (*ptr)
        {
            free(*ptr);
            ptr++;
        }
        free(split);
    }
}

void free_push_swap(t_push_swap *ps)
{
    if (ps)
    {
        free_stacks(ps);
		free_split(ps->split);
        free(ps);
    }
}
