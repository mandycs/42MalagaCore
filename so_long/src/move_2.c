/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:15:40 by mancorte          #+#    #+#             */
/*   Updated: 2024/03/06 21:22:18 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void ft_check_collectible(t_mapstats *ms)
{
	if (ms->map[ms->pos_y][ms->pos_x] == 'C')
	{
		ms->c_count++;
		ms->map[ms->pos_y][ms->pos_x] = '0';
	}
}

void ft_print_exit(t_mapstats *ms)
{
		if (ms->map[ms->pos_y][ms->pos_x] != 'E')
			mlx_image_to_window(ms->mlx, ms->floor, ms->pos_x * 64, ms->pos_y * 64);
		if(ms->map[ms->pos_y][ms->pos_x] == 'E')
		{
			mlx_image_to_window(ms->mlx, ms->floor, ms->pos_x * 64, ms->pos_y * 64);
			mlx_image_to_window(ms->mlx, ms->exit, ms->pos_x * 64, ms->pos_y * 64);
		}
}