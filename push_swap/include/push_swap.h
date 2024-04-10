/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:04:49 by mancorte          #+#    #+#             */
/*   Updated: 2024/03/19 13:52:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_node
{
    int				value;
    struct s_node	*next;
}				t_node;

typedef struct s_stack
{
    t_node	*head;
    int		size;
}				t_stack;

typedef struct s_push_swap
{
    int        i_args;
    t_stack    *stack_a;
    t_stack    *stack_b;
	char		**split;
	int			n_str;
}				t_push_swap;


int main(int argc, char **argv);
t_stack *ft_init_stack(void);
int		ft_prepare_stack(t_push_swap *ps, int argc, char **argv);
int		ft_atoi(char *str);
int		ft_isdigit(char *str);
int		ft_push(t_stack *stack, int value);
void	ft_swap_a(t_stack *stack_a);
void	ft_swap_b(t_stack *stack_b);
void	ft_swap_ss(t_stack *stack_a, t_stack *stack_b);
void	ft_push_a(t_stack *stack_a, t_stack *stack_b);
void	ft_push_b(t_stack *stack_a, t_stack *stack_b);
void	ft_rotate_a(t_stack *stack_a);
void	ft_rotate_b(t_stack *stack_b);
void	ft_rotate_rr(t_stack *stack_a, t_stack *stack_b);
void	ft_reverse_rotate_a(t_stack *stack_a);
void	ft_reverse_rotate_b(t_stack *stack_b);
int 	ft_prepare_stack_2(t_push_swap *ps, char **argv);
char	**ft_split(char const *s, char c, t_push_swap *ps);
int		ft_count_words(char const *s, char c);
int		ft_strlen(char *str);
char	**ft_fill_array(char **strs, char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int	ft_check_doubles(t_push_swap *ps);


#endif