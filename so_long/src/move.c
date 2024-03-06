/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:09:59 by mancorte          #+#    #+#             */
/*   Updated: 2024/03/06 21:26:22 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_move(mlx_key_data_t keydata, void *param)
{
	t_mapstats	*ms;

	ms = (t_mapstats *)param;
	ms->keycode = keydata.key;
	if (keydata.action == MLX_PRESS)
	{
		printf("Keycode = %d\n", ms->keycode);
		if (ms->keycode == MLX_KEY_ESCAPE)
			mlx_close_window(ms->mlx);
		else if (ms->keycode == MLX_KEY_W)
			ft_move_up(ms);
		else if (ms->keycode == MLX_KEY_A)
			ft_move_left(ms);
		else if (ms->keycode == MLX_KEY_S)
			ft_move_down(ms);
		else if (ms->keycode == MLX_KEY_D)
			ft_move_right(ms);
	}
}

void	ft_move_up(t_mapstats *ms)
{
	if (ms->map[ms->pos_y - 1][ms->pos_x] != '1')
	{
		ft_print_exit(ms);
		ms->pos_y--;
		mlx_image_to_window(ms->mlx, ms->player, ms->pos_x * 64, ms->pos_y
				* 64);
		ft_check_collectible(ms);
		if (ms->map[ms->pos_y][ms->pos_x] == 'E')
		{
			if (ms->c_count < ms->c)
			{
				mlx_image_to_window(ms->mlx, ms->exit, ms->pos_x * 64, ms->pos_y
						* 64);
				mlx_image_to_window(ms->mlx, ms->player, ms->pos_x * 64,
						ms->pos_y * 64);
			}
			else if (ms->c_count == ms->c)
				mlx_close_window(ms->mlx);
		}
	}
}
void	ft_move_left(t_mapstats *ms)
{
	if (ms->map[ms->pos_y][ms->pos_x - 1] != '1')
	{
		ft_print_exit(ms);
		ms->pos_x--;
		mlx_image_to_window(ms->mlx, ms->player, ms->pos_x * 64, ms->pos_y
				* 64);
		ft_check_collectible(ms);
		if (ms->map[ms->pos_y][ms->pos_x] == 'E')
		{
			if (ms->c_count < ms->c)
			{
				mlx_image_to_window(ms->mlx, ms->exit, ms->pos_x * 64, ms->pos_y
						* 64);
				mlx_image_to_window(ms->mlx, ms->player, ms->pos_x * 64,
						ms->pos_y * 64);
			}
			else if (ms->c_count == ms->c)
				mlx_close_window(ms->mlx);
		}
	}
}

void	ft_move_down(t_mapstats *ms)
{
	if (ms->map[ms->pos_y + 1][ms->pos_x] != '1')
	{
		ft_print_exit(ms);
		ms->pos_y++;
		mlx_image_to_window(ms->mlx, ms->player, ms->pos_x * 64, ms->pos_y * 64);
		ft_check_collectible(ms);
		if (ms->map[ms->pos_y][ms->pos_x] == 'E')
		{
			if (ms->c_count < ms->c)
			{
				mlx_image_to_window(ms->mlx, ms->exit, ms->pos_x * 64, ms->pos_y
						* 64);
				mlx_image_to_window(ms->mlx, ms->player, ms->pos_x * 64, ms->pos_y
						* 64);
			}
			else if (ms->c_count == ms->c)
				mlx_close_window(ms->mlx);
		}
	}
}

void	ft_move_right(t_mapstats *ms)
{
	if (ms->map[ms->pos_y][ms->pos_x + 1] != '1')
	{
		ft_print_exit(ms);
		ms->pos_x++;
		mlx_image_to_window(ms->mlx, ms->player, ms->pos_x * 64, ms->pos_y
				* 64);
		ft_check_collectible(ms);
		if (ms->map[ms->pos_y][ms->pos_x] == 'E')
		{
			if (ms->c_count < ms->c)
			{
				mlx_image_to_window(ms->mlx, ms->exit, ms->pos_x * 64, ms->pos_y
						* 64);
				mlx_image_to_window(ms->mlx, ms->player, ms->pos_x * 64,
						ms->pos_y * 64);
			}
			else if (ms->c_count == ms->c)
				mlx_close_window(ms->mlx);
		}
	}
}
