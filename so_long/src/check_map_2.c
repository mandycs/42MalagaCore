/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 01:01:06 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/08 14:36:20 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_char_min_map(t_mapstats *ms)
{
	if (ms->map[ms->y][ms->x] == 'C')
		ms->c++;
	if (ms->map[ms->y][ms->x] == 'P')
		ms->p++;
	if (ms->map[ms->y][ms->x] == 'E')
		ms->e++;
}

int	check_border_map(t_mapstats *ms)
{
	ms->y = 0;
	while (ms->y < ms->y_len)
	{
		ms->x = 0;
		if (ms->y == 0 || ms->y == (ms->y_len - 1))
		{
			while (ms->map[ms->y][ms->x] == '1' && ms->x < ms->x_len)
			{
				ms->x++;
			}
			if (ms->x < (ms->x_len - 1))
				return (1);
		}
		else
		{
			if (ms->map[ms->y][0] != '1' ||
			ms->map[ms->y][ms->x_len - 2] != '1')
				return (1);
		}
		ms->y++;
	}
	return (0);
}

void	ft_fill_visited_map(t_mapstats *ms)
{
	ms->y_c = 0;
	while (ms->y_c < ms->y_len)
	{
		ms->x_c = 0;
		while(ms->x_c < (ms->x_len - 1))
		{
			ms->map_visit[ms->y_c][ms->x_c] = 0;
		}
		ms->y_c++;
	}
}

int	ft_search_map(t_mapstats *ms)
{
    if (ms->map[ms->y_p][ms->x_p] == 'E')
		return (0);
    if (ms->map_visit[ms->y_p][ms->x_p])
		return (1);
    ms->map_visit[ms->y_p][ms->x_p] = 1;
    if (move_up(ms) == 0 || move_down(ms) == 0 || move_left(ms) == 0 ||
	move_right(ms) == 0)
		return (0);
    return (1);
}
