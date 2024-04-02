/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:32:30 by marvin            #+#    #+#             */
/*   Updated: 2024/03/19 00:32:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int		c;
	long	nb;
	int		min;

	c = 0;
	nb = 0;
	min = 0;
	while (str[c] == 32 || (str[c] >= 9 && str[c] <= 13))
		c++;
	if (str[c] == '-')
	{
		min = 1;
		c++;
	}
	else if (str[c] == '+')
		c++;
	while (str[c] >= '0' && str[c] <= '9')
	{
		nb = nb * 10 + (str[c] - 48);
		c++;
	}
	if (min == 1)
		nb = nb * -1;
	return (nb);
}

int	ft_isdigit(char *str)
{
	int c;

	c = 0;
	if (str[c] == '-' || str[c] == '+')
		c++;
	while (str[c])
	{
		if (str[c] < '0' || str[c] > '9')
			return (0);
		c++;
	}
	return (1);
}

int	ft_push(t_stack *stack, int value)
{
	t_node *new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (1);
	new->value = value;
	new->next = stack->head;
	stack->head = new;
	stack->size++;
	return (0);
}