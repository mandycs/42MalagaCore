/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:09:12 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/08 13:30:27 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_mapstats
{
	int		x;
	int		y;
	int		c;
	int		p;
	int		e;
	int		x_len;
	int		y_len;
	int		fd;
	int		i;
	int		status;
	char	*line;
	char	**map;
}		t_mapstats;

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_join_and_free(char *s1, char *s2);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*create_line(char *stack);
char	*update_stack(char *stack);
int		check_map(t_mapstats *ms);
int		check_char_map(t_mapstats *ms);
void	check_char_min_map(t_mapstats *ms);
int		check_border_map(t_mapstats *ms);
int		map_len_x(t_mapstats *ms, int y);
int		map_len_y(t_mapstats *ms);
int		check_len_map(t_mapstats *ms);
int		ft_read_smap(t_mapstats *ms, char *argv);
int		ft_save_map(t_mapstats *ms);


#endif