/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:41:43 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/12 22:32:06 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_iniciate(t_mapstats *ms)
{
	ms->mlx = mlx_init(ms->x_len * 64, ms->y_len * 64, "Legend of Mandy", false);
	if (!ms->mlx)
	{
		printf("Error\n");
		exit(1);
	}
}

int ft_create_window(t_mapstats *ms)
{

	ft_iniciate(ms);
	
	mlx_loop(ms->mlx);
	return (0);
}
