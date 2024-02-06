/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 01:01:06 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/06 22:07:34 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_char_min_map(char **map, t_mapstats *ms)
{
	if (map[ms->y][ms->x] == 'C')
		ms->c++;
	if (map[ms->y][ms->x] == 'P')
		ms->p++;
	if (map[ms->y][ms->x] == 'E')
		ms->e++;
}

int	check_border_map(char **map, int map_len_x, int map_len_y)
{
	t_mapstats	ms;

	ms.y = 0;
	ms.x_len = map_len_x;
	ms.y_len = map_len_y;
	while (ms.y < map_len_y)
	{
		ms.x = 0;
		if (ms.y == 0 || ms.y == (ms.y_len - 1))
		{
			while (map[ms.y][ms.x] == 1)
				ms.x++;
			if (ms.x < (ms.x_len - 1))
				return (1);
		}
		if (ms.y != 0 || ms.y != (ms.y_len - 1))
			if (map[ms.y][0] != 1 || map[ms.y][ms.x_len - 1] != 1)
				return (1);
		ms.y++;
	}
	return (0);
}
