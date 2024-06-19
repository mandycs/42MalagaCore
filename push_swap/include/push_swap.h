/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:50:44 by mancorte          #+#    #+#             */
/*   Updated: 2024/06/19 18:25:35 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* @------------------------------------------------------------------------@ */
/* |                            Define Section                              | */
/* @------------------------------------------------------------------------@ */

/* @------------------------------------------------------------------------@ */
/* |                            Include Section                             | */
/* @------------------------------------------------------------------------@ */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* @------------------------------------------------------------------------@ */
/* |                            Typedef Section                             | */
/* @------------------------------------------------------------------------@ */
typedef struct s_stack	t_stack;
typedef struct s_gen	t_gen;

/* @------------------------------------------------------------------------@ */
/* |                             Enum Section                               | */
/* @------------------------------------------------------------------------@ */

/* @------------------------------------------------------------------------@ */
/* |                            Struct Section                              | */
/* @------------------------------------------------------------------------@ */
struct					s_stack
{
	long int			content;
	int					act_pos;
	int					tar_pos;
	int					cos_a;
	int					cos_b;
	struct s_stack		*next;
};

struct					s_gen
{
	t_stack				*stack_a;
	t_stack				*stack_b;
	t_stack				*lower;
	int					sizea;
	int					sizeb;
};
/* @------------------------------------------------------------------------@ */
/* |                           Function Section                             | */
/* @------------------------------------------------------------------------@ */

int						ft_isdigit(int c);
char					**ft_split(const char *s, char c);
int						ft_atoi(const char *c);
int						ft_check_arg(char **argv);
int						ft_check_chars(char **argv);
t_stack					*ft_init_a(int size, char **nbs, t_stack *stack_a);
int						ft_split_size(char **str);
t_stack					*ft_init_a2(char **nbs, t_stack *stack_a);
t_stack					*ft_clean(t_stack *first, char **numbers);
t_stack					*ft_clean_stack(t_stack *stack);
char					**ft_free_str(char **str);
void					ft_set_pos(t_stack **stack);
int						ft_is_sorted(t_stack *stack);
t_stack					*ft_sort_three(t_stack *stack_a);
int						ft_error(t_stack *stack);
int						ft_max_int(t_stack *stack);
int						ft_parse(t_stack *stack);
int						ft_get_size(t_stack *stack);
t_gen					ft_set_targ(t_gen gen);
int						ft_get_pos(t_stack *stack_a, int content, int targ,
							int max);
t_gen					ft_calc_cost(t_gen gen);
t_stack					*ft_get_lower(t_stack *stack_a);
t_stack					*ft_cheap(t_stack *stack_b);
t_gen					ft_move_up(t_gen gen, t_stack *cheap);
t_gen					ft_sort_2(t_gen gen);
int						ft_pos(int n);
t_gen					ft_pb(t_gen gen);
t_gen					ft_pa(t_gen gen);
t_gen					ft_rrr(t_gen gen);
t_gen					ft_rr(t_gen gen);
t_stack					*ft_rra(t_stack *stack_a, int flag);
t_stack					*ft_ra(t_stack *stack_a, int flag);
t_stack					*ft_rb(t_stack *stack_b, int flag);
t_stack					*ft_rrb(t_stack *stack_b, int flag);
t_stack					*ft_sa(t_stack *stack_a, int flag);
t_gen					ft_sort(t_gen gen);
t_gen					ft_fatality(t_gen gen);

#endif
