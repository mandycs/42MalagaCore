/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:13:17 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/06 23:41:02 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main()
{
	t_mapstats	ms;
	printf("Hola mundo");
	printf("He llegado aquí");
	ms.x = 0;
	ms.y = 0;
	// if (argc < 2)
	// 	printf("Me faltan argumentos");
	// 	return (1);

	ms.fd = open("map1.txt", O_RDONLY);
	printf("%d", ms.fd);
	if (ms.fd == -1)
		return (1);
	ms.line = get_next_line(ms.fd);
	while (ms.line != NULL)
	{
		printf("Estoy aquí");
		free (ms.line);
		ms.line = get_next_line(ms.fd);
		ft_memcpy(ms.map[ms.y], ms.line, ft_strlen(ms.line));
		ms.y++;
	}
	ms.y = 0;
	while (ms.map[ms.y] != NULL)
	{
		printf("%s", ms.map[ms.y]);
		ms.y++;
	}
	return (1);
}
