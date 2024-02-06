/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:23:56 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/06 23:20:43 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_join_and_free(char *s1, char *s2);
size_t 	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*create_line(char *stack);
char	*update_stack(char *stack);
#endif