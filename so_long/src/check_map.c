/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:23:22 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/08 14:50:24 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_mapstats *ms)
{
	ms->x = 0;
	ms->y = 0;
	ms->c = 0;
	ms->p = 0;
	ms->e = 0;
	if (check_len_map(ms) == 1)
		return (1);
	while (ms->y < ms->y_len)
	{
		while (ms->map[ms->y][ms->x] != '\0' && ms->map[ms->y][ms->x] != '\n')
		{
			if (check_char_map(ms) == 1)
				return (1);
			check_char_min_map(ms);
			ms->x++;
		}
		ms->x = 0;
		ms->y++;
	}
	if (ms->e != 1 || ms->p != 1 || ms->c < 1)
		return (1);
	return (0);
}

int	check_char_map(t_mapstats *ms)
{
	if (ms->map[ms->y][ms->x] != '0' &&
		ms->map[ms->y][ms->x] != '1' &&
		ms->map[ms->y][ms->x] != 'C' &&
		ms->map[ms->y][ms->x] != 'E' &&
		ms->map[ms->y][ms->x] != 'P')
	{
		return (1);
	}
	if (ms->map[ms->y][ms->x] == 'P')
	{
		ms->x_init = ms->x;
		ms->y_init = ms->y;
		ms->x_p = ms->x;
		ms->y_p = ms->y;
	}
	if (ms->map[ms->y][ms->x] == 'E')
	{
		ms->x_exit = ms->x;
		ms->y_exit = ms->y;
	}
	return (0);
}

int	map_len_x(t_mapstats *ms, int y)
{
	ms->x = 0;
	while (ms->map[y][ms->x])
		ms->x++;
	return (ms->x);
}

int	map_len_y(t_mapstats *ms)
{
	int	y;

	y = 0;
	while (ms->map[y])
		y++;
	return (y);
}

int	check_len_map(t_mapstats *ms)
{
	ms->y = 1;
	ms->x_len = map_len_x(ms, 0);
	ms->y_len = map_len_y(ms);
	if (ms->y_len == ms->x_len || ms->y_len < 2 || ms->x_len < 4)
	{
		printf("Error: Map size rectangle\n");
		return (1);
	}
	while (ms->y < ms->y_len)
	{
		ms->x = map_len_x(ms, 0);
		if (ms->x < map_len_x(ms, ms->y - 1))
		{
			printf("Error: Map size different row length\n");
			return (1);
		}
		ms->y++;
	}
	if (check_border_map(ms) == 1)
		return (1);
	ms->y = 0;
	ms->x = 0;
	return (0);
}
