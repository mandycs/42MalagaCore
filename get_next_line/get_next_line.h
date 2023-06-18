/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:59:10 by mancorte          #+#    #+#             */
/*   Updated: 2023/06/19 00:00:18 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*join_free(char *stack, char *temp);
char	*ft_strjoin(char *stack, char *temp);
int		ft_strlen(const char *s);
char	*update_stack(char *stack);
char	*create_line(char *stack);

#endif