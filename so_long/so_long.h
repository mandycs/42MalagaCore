/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:57:02 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/06 01:54:05 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_mapstats
{
	int	x;
	int	y;
	int	c;
	int	p;
	int	e;
	int	x_len;
	int	y_len;
}		t_mapstats;

int		check_map(char **map, int length_map);
int		check_char_map(char **map, t_mapstats *ms);
void	check_char_min_map(char **map, t_mapstats *ms);
int		check_border_map(char **map, int map_len_x, int map_len_y);
int		map_len_x(char **map, int y);
int		map_len_y(char **map);
int		check_len_map(char **map);

#endif