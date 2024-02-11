/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:59:23 by marvin            #+#    #+#             */
/*   Updated: 2024/02/10 15:25:52 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_mapstats *ms)
{
	if (ms->y_p > 0 && ms->map[ms->y_p - 1][ms->x_p] != '1' &&
	!ms->map_visit[ms->y_p - 1][ms->x_p])
	{
		ms->y_p--;
		if (ft_search_map(ms) == 0)
			return (0);
		ms->y_p++;
	}
	return (1);
}

int	move_down(t_mapstats *ms)
	{
	if (ms->y_p < ms->y_len - 1 && ms->map[ms->y_p + 1][ms->x_p] != '1' &&
	!ms->map_visit[ms->y_p + 1][ms->x_p])
	{
		ms->y_p++;
		if (ft_search_map(ms) == 0)
			return (0);
		ms->y_p--;
	}
	return (1);
}

int	move_left(t_mapstats *ms)
{
	if (ms->x_p > 0 && ms->map[ms->y_p][ms->x_p - 1] != '1' &&
	!ms->map_visit[ms->y_p][ms->x_p - 1])
	{
		ms->x_p--;
		if (ft_search_map(ms) == 0)
			return (0);
		ms->x_p++;
	}
	return (1);
}

int	move_right(t_mapstats *ms)
{
	if (ms->x_p < ms->x_len - 2 && ms->map[ms->y_p][ms->x_p + 1] != '1' &&
	!ms->map_visit[ms->y_p][ms->x_p + 1])
	{
		ms->x_p++;
		if (ft_search_map(ms) == 0)
			return (0);
		ms->x_p--;
	}
	return (1);
}
