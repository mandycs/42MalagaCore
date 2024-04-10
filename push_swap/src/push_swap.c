/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:04:36 by mancorte          #+#    #+#             */
/*   Updated: 2024/03/20 00:42:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	t_push_swap	*ps = malloc(sizeof(t_push_swap));
	printf("Estoy aqui\n");
	ps->stack_a = NULL;
	ps->stack_b = NULL;
	if (argc < 2)
		return (1);
	if (argc == 2)
		ft_prepare_stack_2(ps, argv);
	else
		if (ft_prepare_stack(ps, argc, argv) == 1)
			return (1);
	return (0);
}

t_stack *ft_init_stack(void)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->size = 0;
	return (stack);
}

int	ft_prepare_stack(t_push_swap *ps, int argc, char **argv)
{
	ps->i_args = 1;
	while (ps->i_args < argc)
	{
		if (ft_isdigit(argv[ps->i_args]))
		{
			ft_push(ps->stack_b, ft_atoi(argv[ps->i_args]));
			ps->i_args++;
		}
		else
			return (1);
	}
	return (0);
}
