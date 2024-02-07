/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:13:17 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/06 20:28:16 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mapstats	ms;

	ms.status = 0;
	if (argc != 2)
		return (1);
	ms.status = ft_read_save_map(&ms, argv[1]);
	printf("status map_save: %d\n", ms.status);
	if (ms.status == -1)
		return (1);
	ms.status = check_map(&ms);
	printf("status check_map: %d\n", ms.status);
	if (ms.status == 1)
		return (1);
	return (0);
}

int	ft_read_save_map(t_mapstats *ms, char *argv)
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
	while ((ms->line = get_next_line(fd)) != NULL)
	{
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

//	ms->y = 0;
//	while (ms->map[ms->y] != NULL)
//	{
//		printf("%s", ms->map[ms->y]);
//		free(ms->map[ms->y]); 
//		ms->y++;
//	}