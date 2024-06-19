/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:50:44 by mancorte          #+#    #+#             */
/*   Updated: 2024/06/19 18:09:40 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_arg(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
			{
				if (ft_isdigit(argv[i][j - 1]) || argv[i][j + 1] == ' '
					|| argv[i][j + 1] == '\0' || argv[i][j + 1] == '-'
					|| argv[i][j + 1] == '+')
				{
					write(1, "[ERROR] Input\n", 14);
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_chars(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				if (argv[i][j] != '-' && argv[i][j] != '+')
				{
					if (argv[i][j] != ' ')
					{
						write(1, "[ERROR] Input\n", 14);
						return (0);
					}
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_set_pos(t_stack **stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->act_pos = i;
		tmp = tmp->next;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_gen	gen;

	if (argc > 1)
	{
		gen.stack_a = NULL;
		gen.stack_b = NULL;
		if (ft_check_arg(argv) == 0 || ft_check_chars(argv) == 0)
			return (1);
		gen.stack_a = ft_init_a(argc, argv, gen.stack_a);
		ft_set_pos(&gen.stack_a);
		if (ft_error(gen.stack_a) == 0)
			return (1);
		gen.sizea = argc - 1;
		if (ft_is_sorted(gen.stack_a))
		{
			gen.stack_a = ft_clean_stack(gen.stack_a);
			return (0);
		}
		if (gen.sizea == 3)
			gen.stack_a = ft_sort_three(gen.stack_a);
		else
			gen = ft_sort(gen);
		gen.stack_a = ft_clean_stack(gen.stack_a);
		return (0);
	}
}
