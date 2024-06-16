/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:04:49 by mancorte          #+#    #+#             */
/*   Updated: 2024/06/16 09:47:28 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				act_pos;
	int				targ_pos;
	int				cos_a;
	int				cos_b;
	int				tot_cos;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	int				size;
}					t_stack;

typedef struct s_push_swap
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_node			*node_b;
	t_node			*node_a;
	t_node			*cheap_n;
	t_node			*current;
	char			**split;
	int				n_str;
	int				pos;
	int				pos_found;
	int				half_b;
	int				closestmax;
	int				closestpos;
}					t_push_swap;

int					main(int argc, char **argv);
t_stack				*ft_init_stack(void);
int					ft_prepare_stack(t_push_swap *ps, int argc, char **argv);
int					ft_atoi(char *str);
int					ft_isdigit(char *str);
int					ft_push(t_stack *stack, int value);
void				ft_swap_a(t_push_swap *ps);
void				ft_swap_b(t_push_swap *ps);
void				ft_swap_ss(t_push_swap *ps);
void				ft_push_a(t_push_swap *ps);
void				ft_push_b(t_push_swap *ps);
void				ft_rotate_a(t_push_swap *ps);
void				ft_rotate_b(t_push_swap *ps);
void				ft_rotate_rr(t_push_swap *ps);
void				ft_reverse_rotate_a(t_push_swap *ps);
void				ft_reverse_rotate_b(t_push_swap *ps);
int					ft_prepare_stack_2(t_push_swap *ps, char **argv);
char				**ft_split(char *s, char c, t_push_swap *ps);
int					ft_count_words(char *s, char c);
char				**ft_fill_array(char **strs, char *s, char c);
size_t				ft_strlcpy(char *dst, char *src, size_t dstsize);
int					ft_check_doubles(t_push_swap *ps);
char				*ft_substr(char *s, unsigned int start, size_t len);
int					ft_strlen(char *str);
t_stack				*ft_create_stack(void);
void				ft_prepare_stack_a(t_push_swap *ps);
void				ft_sort_three(t_stack *stack_a, t_push_swap *ps);
void				print_stack_a(t_stack *stack_a);
void				ft_calc(t_push_swap *ps);
void				ft_calc_pos(t_stack *stack);
void				ft_calc_targ_pos(t_push_swap *ps);
void				calculate_costs(t_push_swap *ps);
int					calculate_cos_a(int targ_pos, int total);
t_node				*find_cheapest_node(t_stack *stack);
void				ft_calc_sizes(t_push_swap *ps);
void				ft_move_up(t_push_swap *ps);
t_node				*ft_get_lower(t_stack *stack);
int					ft_is_sort(t_stack *stack);
void				ft_sort_a(t_push_swap *ps);
void				ft_get_pos(t_stack *stack_a, int num, int maxint,
						t_push_swap *ps);
void				find_closest_above(t_stack *stack_a, int num, int maxint,
						t_push_swap *ps);
void				find_min_value(t_stack *stack_a, int maxint,
						t_push_swap *ps);
void				ft_free_stack(t_stack *stack);
void				free_stacks(t_push_swap *ps);
void				free_split(char **split);
void				free_push_swap(t_push_swap *ps);

#endif