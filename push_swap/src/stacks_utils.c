/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:15:08 by mancorte          #+#    #+#             */
/*   Updated: 2024/06/19 21:10:20 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_init_a(int size, char **nbs, t_stack *stack_a)
{
	int	i;
	t_stack *first;

	i = 1;
	if (size == 2)
		return (ft_init_a2(ft_split(nbs[1], ' '), stack_a));
	first = malloc(sizeof(t_stack));
	first->content = ft_atoi(nbs[1]);
	first->act_pos = 0;
	first->next = malloc(sizeof(t_stack));
	stack_a = first->next;
	i++;
	while( i < size - 1)
	{
		stack_a->content = ft_atoi(nbs[i]);
		stack_a->next = malloc(sizeof(t_stack));
		stack_a = stack_a->next;
		i++;
	}
	stack_a->content = ft_atoi(nbs[i]);
	stack_a->next = NULL;
	return (first);
}

t_stack	*ft_init_a2(char **nbs, t_stack *stack_a)
{
	int	i;
	int	size;
	t_stack *first;

	i = 0;
	size = ft_split_size(nbs);
	first = malloc(sizeof(t_stack));
	first->content = ft_atoi(nbs[i]);
	first->act_pos = 0;
	first->next = malloc(sizeof(t_stack));
	stack_a = first->next;
	if (size == 1)
		return (ft_clean(first, nbs	));
	while(i < size - 1)
	{
		stack_a->content = ft_atoi(nbs[i]);
		stack_a->next = malloc(sizeof(t_stack));
		stack_a = stack_a->next;
		i++;
	}
	stack_a->content = ft_atoi(nbs[i]);
	stack_a->next = NULL;
	ft_free_str(nbs);
	return (first);
}

int	ft_get_size(t_stack *stack)
{
	int	cnt;

	cnt = 0;
	while (stack)
	{
		cnt++;
		stack = stack->next;
	}
	return (cnt);
}

t_gen	ft_move_up(t_gen gen, t_stack *cheap)
{
	if (cheap->cos_a == 0 && cheap->cos_b == 0)
		gen = ft_pa(gen);
	else if (cheap->cos_a < 0 && cheap->cos_b < 0)
		gen = ft_rrr(gen);
	else if (cheap->cos_a > 0 && cheap->cos_b > 0)
		gen = ft_rr(gen);
	else if (cheap->cos_a < 0)
		gen.stack_a = ft_rra(gen.stack_a, 1);
	else if (cheap->cos_a > 0)
		gen.stack_a = ft_ra(gen.stack_a, 1);
	else if (cheap->cos_b < 0)
		gen.stack_b = ft_rrb(gen.stack_b, 1);
	else if (cheap->cos_b > 0)
		gen.stack_b = ft_rb(gen.stack_b, 1);
	return (gen);
}