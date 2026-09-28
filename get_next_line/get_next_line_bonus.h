/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:23:56 by mancorte          #+#    #+#             */
/*   Updated: 2026/09/28 17:00:00 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define GNL_MAX_FD	512

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*gnl_fill(int fd, char **save);
char	*gnl_read_buffer(int fd, long *bytes);
char	*gnl_split_line(char *buffer, char **save);
char	*gnl_copy_n(char *src, int n);
char	*gnl_strdup(const char *s);
char	*gnl_join(char *s1, char *s2);
int		gnl_strlen(const char *s);
int		gnl_has_nl(char *buffer);
int		gnl_line_len(char *buffer);
#endif
