/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:13:17 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/10 21:19:00 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_mapstats	ms;

	if (argc != 2)
		return (1);
	printf("He entrado en main\n");
	if (ft_validate_map(&ms, argv[1]) == 1)
		return (1);
	return (0);
}

int	ft_validate_map(t_mapstats *ms, char *argv)
{
	printf("He entrado en validate_map\n");
	if (ft_read_map(ms, argv) == -1)
		return (1);
	printf("He leido el mapa \n");
	if (ft_check_map(ms) == 1)
		return (1);
	printf("He chequeado el mapa \n");
	if (ft_search_map(ms) == 1)
		return (1);
	printf("He buscado el mapa \n");
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
	{
		printf("He salido de read_map mal\n");
		return (-1);
	}
	printf("He salido de read_map bien\n");
	return (0);
}

int	ft_save_map(t_mapstats *ms)
{
	ms->line = get_next_line(ms->fd);
	if (ms->line == NULL)
	{
		free(ms->line);
		return (-1);
	}
	while (ms->line != NULL)
	{
		ms->line = get_next_line(ms->fd);
		ms->map[ms->y] = malloc(ft_strlen(ms->line) + 1);
		if (ms->map[ms->y] == NULL)
		{
			ms->i = 0;
			while (ms->i < ms->y)
			{
				free(ms->map[ms->i]);
				ms->i++;
			}
			free(ms->map);
			return (-1);
		}
		ft_memcpy(ms->map[ms->y], ms->line, ft_strlen(ms->line) + 1);
		free(ms->line);
		ms->y++;
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
