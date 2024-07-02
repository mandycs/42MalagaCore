/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:50:44 by mancorte          #+#    #+#             */
/*   Updated: 2024/07/02 18:13:28 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c < 0)
		c = c * -1;
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_split_size(char **str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

int	ft_pos(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

t_stack	*ft_get_lower(t_stack *stack_a)
{
	t_stack	*tmp;
	t_stack	*lower;

	tmp = stack_a;
	lower = tmp;
	while (tmp)
	{
		if (tmp->content < lower->content)
			lower = tmp;
		tmp = tmp->next;
	}
	return (lower);
}
