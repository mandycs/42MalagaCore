/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:57:02 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/06 23:16:11 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"
# include "ft_printf.h"

typedef struct s_mapstats
{
	int	x;
	int	y;
	int	c;
	int	p;
	int	e;
	int	x_len;
	int	y_len;
	int	fd;
	char *line;
	char **map;
}		t_mapstats;

int		check_map(char **map);
int		check_char_map(char **map, t_mapstats *ms);
void	check_char_min_map(char **map, t_mapstats *ms);
int		check_border_map(char **map, int map_len_x, int map_len_y);
int		map_len_x(char **map, int y);
int		map_len_y(char **map);
int		check_len_map(char **map);

#endif