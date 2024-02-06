/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:23:56 by mancorte          #+#    #+#             */
/*   Updated: 2023/11/07 22:46:01 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_join_and_free(char *s1, char *s2);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*create_line(char *stack);
char	*update_stack(char *stack);
#endif