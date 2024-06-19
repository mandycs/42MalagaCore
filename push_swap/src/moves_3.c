/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:10:52 by mancorte          #+#    #+#             */
/*   Updated: 2024/06/19 18:27:48 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_rb(t_stack *stack_b, int flag)
{
	int		tmp;
	t_stack	*first;

	if (!stack_b || !stack_b->next)
		return (stack_b);
	first = stack_b;
	stack_b = stack_b->next;
	while (stack_b->next)
	{
		tmp = stack_b->content;
		stack_b->content = stack_b->next->content;
		stack_b->next->content = tmp;
		stack_b = stack_b->next;
	}
	tmp = first->content;
	first->content = stack_b->content;
	stack_b->content = tmp;
	if (flag)
		write(1, "rb\n", 3);
	ft_set_pos(&first);
	return (first);
}
