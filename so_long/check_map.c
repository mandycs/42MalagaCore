/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:23:22 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/06 02:21:01 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char **map, int length_map)
{
	t_mapstats	ms;

	ms.x = 0;
	ms.y = 0;
	ms.c = 0;
	ms.p = 0;
	ms.e = 0;
	if (check_len_map(map) == 0)
		return (0);
	while (map[ms.y])
	{
		while (map[ms.y][ms.x])
		{
			if (check_char_map(map, &ms) == 0)
				return (0);
			check_char_min_map(map, &ms);
			ms.x++;
		}
		if (ms.e != 1 || ms.p != 1 || ms.c < 1)
			return (0);
		ms.x = 0;
		ms.y++;
	}
	return (1);
}

int	check_char_map(char **map, t_mapstats *ms)
{
	if (map[ms->y][ms->x] != '0' &&
		map[ms->y][ms->x] != '1' &&
		map[ms->y][ms->x] != 'C' &&
		map[ms->y][ms->x] != 'E' &&
		map[ms->y][ms->x] != 'P')
		return (0);
}

int	map_len_x(char **map, int y)
{
	int	x;

	while (map[y][x])
		x++;
	return (x);
}

int	map_len_y(char **map)
{
	int	y;

	while (map[y])
		y++;
	return (y);
}

int	check_len_map(char **map)
{
	t_mapstats	ms;

	ms.y = 1;
	ms.x_len = map_len_x(map, 0);
	ms.y_len = map_len_y(map);
	if (ms.y_len == ms.x_len || ms.y_len > 2 || ms.x_len > 4)
		return (0);
	while (ms.y < ms.y_len)
	{
		ms.x = map_len_x(map, ms.y);
		if (ms.x < ms.x_len)
			return (0);
		ms.y++;
	}
	if (check_border_map(map, map_len_x, map_len_y) == 0)
		return (0);
	return (1);
}
