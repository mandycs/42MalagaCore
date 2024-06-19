/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:35:44 by mancorte          #+#    #+#             */
/*   Updated: 2024/06/19 20:40:09 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_clean(t_stack *stack, char **nums)
{
	free(stack->next);
	stack->next = NULL;
	free(stack);
	stack = NULL;
	ft_free_str(nums);
	return (stack);
}

t_stack	*ft_clean_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	return (NULL);
}

char	**ft_free_str(char **str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
	{
		free(str[cnt]);
		cnt++;
	}
	free(str);
	return (NULL);
}
