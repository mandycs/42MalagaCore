/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:41:43 by mancorte          #+#    #+#             */
/*   Updated: 2024/03/06 22:04:26 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_iniciate(t_mapstats *ms)
{
	ms->mlx = mlx_init((ms->x_len - 1) * 64, ms->y_len * 64, "Legend of Mandy",
			false);
	if (!ms->mlx)
	{
		printf("Error\n");
		exit(1);
	}
	ms->texture = mlx_load_png("sprite/floor.png");
	ms->floor = mlx_texture_to_image(ms->mlx, ms->texture);
	ms->texture = mlx_load_png("sprite/wall.png");
	ms->wall = mlx_texture_to_image(ms->mlx, ms->texture);
	ms->texture = mlx_load_png("sprite/collectible.png");
	ms->collectible = mlx_texture_to_image(ms->mlx, ms->texture);
	ms->texture = mlx_load_png("sprite/character.png");
	ms->player = mlx_texture_to_image(ms->mlx, ms->texture);
	ms->texture = mlx_load_png("sprite/exit.png");
	ms->exit = mlx_texture_to_image(ms->mlx, ms->texture);
	ft_print_map(ms);
}

int	ft_create_window(t_mapstats *ms)
{
	ft_iniciate(ms);
	ms->c_count = 0;
	ms->s_count = 0;
	mlx_key_hook(ms->mlx, ft_move, ms);
	mlx_loop(ms->mlx);
	return (0);
}

void	ft_print_map(t_mapstats *ms)
{
	ms->i = 0;
	while (ms->i < ms->y_len)
	{
		ms->j = 0;
		while (ms->j < ms->x_len)
		{
			mlx_image_to_window(ms->mlx, ms->floor, ms->j * 64, ms->i * 64);
			if (ms->map[ms->i][ms->j] == '1')
				mlx_image_to_window(ms->mlx, ms->wall, ms->j * 64, ms->i * 64);
			else if (ms->map[ms->i][ms->j] == 'C')
				mlx_image_to_window(ms->mlx, ms->collectible, ms->j * 64, ms->i
					* 64);
			else if (ms->map[ms->i][ms->j] == 'E')
				mlx_image_to_window(ms->mlx, ms->exit, ms->j * 64, ms->i * 64);
			else if (ms->map[ms->i][ms->j] == 'P')
			{
				mlx_image_to_window(ms->mlx, ms->player, ms->j * 64, ms->i
					* 64);
				ms->pos_x = ms->j;
				ms->pos_y = ms->i;
			}
			ms->j++;
		}
		ms->i++;
	}
}
