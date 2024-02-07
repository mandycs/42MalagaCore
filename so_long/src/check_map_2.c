/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 01:01:06 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/06 20:16:00 by mancorte         ###   ########.fr       */
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
			while (ms->map[ms->y][ms->x] == '1')
				ms->x++;
			if (ms->x < (ms->x_len - 1))
			{
				printf("Error: Map not closed\n");
				return (1);
			}
		}
		if (ms->y != 0 && ms->y != (ms->y_len - 1))
			if (ms->map[ms->y][0] != '1' ||
			ms->map[ms->y][ms->x_len - 2] != '1')
			{
				printf("Error: Map not closed in the mid rows\n");
				return (1);
			}
		ms->y++;
	}
	return (0);
}
