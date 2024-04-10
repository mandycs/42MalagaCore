/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:04:49 by mancorte          #+#    #+#             */
/*   Updated: 2024/04/10 19:17:41 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
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
	char			**split;
	int				n_str;
}					t_push_swap;

int					main(int argc, char **argv);
t_stack				*ft_init_stack(void);
int					ft_prepare_stack(t_push_swap *ps, int argc, char **argv);
int					ft_atoi(char *str);
int					ft_isdigit(char *str);
int					ft_push(t_stack *stack, int value);
void				ft_swap_a(t_stack *stack_a);
void				ft_swap_b(t_stack *stack_b);
void				ft_swap_ss(t_stack *stack_a, t_stack *stack_b);
void				ft_push_a(t_stack *stack_a, t_stack *stack_b);
void				ft_push_b(t_stack *stack_a, t_stack *stack_b);
void				ft_rotate_a(t_stack *stack_a);
void				ft_rotate_b(t_stack *stack_b);
void				ft_rotate_rr(t_stack *stack_a, t_stack *stack_b);
void				ft_reverse_rotate_a(t_stack *stack_a);
void				ft_reverse_rotate_b(t_stack *stack_b);
int					ft_prepare_stack_2(t_push_swap *ps, char **argv);
char				**ft_split(char *s, char c, t_push_swap *ps);
int					ft_count_words(char *s, char c);
char				**ft_fill_array(char **strs, char *s, char c);
size_t				ft_strlcpy(char *dst, char *src, size_t dstsize);
int					ft_check_doubles(t_push_swap *ps);
char				*ft_substr(char *s, unsigned int start, size_t len);
int					ft_strlen(char *str);
t_stack				*ft_create_stack(void);

#endif