/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:13:17 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/12 22:08:17 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_mapstats	ms;

	if (argc != 2)
		return (1);
	if (ft_validate_map(&ms, argv[1]) == 1)
		return (1);
	ft_create_window(&ms);
	
	return (0);
}

int	ft_validate_map(t_mapstats *ms, char *argv)
{
	if (ft_read_map(ms, argv) == -1)
		return (1);
	if (ft_check_map(ms) == 1)
		return (1);
	ft_allocate_visited_map(ms);
	ft_fill_visited_map(ms);
	if (ft_search_map(ms) == 1)
		return (1);
	return (0);
}

int	ft_read_map(t_mapstats *ms, char *argv)
{
	ms->y = 0;
	ms->map = malloc(sizeof(char *) * 100);
	if (ms->map == NULL)
		return (-1);
	ms->fd = open(argv, O_RDONLY);
	if (ms->fd < 0)
	{
		free(ms->map);
		return (-1);
	}
	if (ft_save_map(ms) == -1)
		return (-1);
	return (0);
}

int	ft_save_map(t_mapstats *ms)
{
	ms->line = get_next_line(ms->fd);
	while (ms->line != NULL)
	{
		ms->map[ms->y] = malloc(ft_strlen(ms->line) + 1);
		if (ms->map[ms->y] == NULL)
		{
			while (ms->i < ms->y)
			{
				free(ms->map[ms->i]);
				ms->i++;
			}
			free(ms->map);
			free(ms->line);
			return (-1);
		}
		ft_memcpy(ms->map[ms->y], ms->line, ft_strlen(ms->line) + 1);
		free (ms->line);
		ms->y++;
		ms->line = get_next_line(ms->fd);
	}
	return (0);
}

// ms->y = 0;
// while (ms->map[ms->y] != NULL)
// {
// 	printf("%s", ms->map[ms->y]);
// 	free(ms->map[ms->y]);
// 	ms->y++;
// }
// return (0);
