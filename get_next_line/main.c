/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucortes <jucortes@student.42malaga.com>          +#+  +:+       +#+ */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:24:10 by jucortes          #+#    #+#             */
/*   Updated: 2026/09/28 17:00:00 by jucortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Programa de prueba. El enunciado solo pide entregar get_next_line.c,
** get_next_line_utils.c y get_next_line.h (mas los tres _bonus), y aclara
** que los programas de prueba no se entregan ni se evaluan. Se deja aqui
** comentado para que no defina un main que choque con el de la evaluacion.
**
** Para usarlo, descomenta este bloque y compila:
**   cc -Wall -Wextra -Werror -D BUFFER_SIZE=42
**       main.c get_next_line.c get_next_line_utils.c -o gnl
**
** #include "get_next_line.h"
** #include <stdio.h>
** #include <fcntl.h>
** #include <unistd.h>
** #include <stdlib.h>
**
** int	main(int argc, char **argv)
** {
** 	int		fd;
** 	char	*line;
**
** 	if (argc != 2)
** 	{
** 		printf("usage: main <file>\n");
** 		return (1);
** 	}
** 	fd = open(argv[1], O_RDONLY);
** 	if (fd < 0)
** 		return (1);
** 	line = get_next_line(fd);
** 	while (line != NULL)
** 	{
** 		printf("%s", line);
** 		free(line);
** 		line = get_next_line(fd);
** 	}
** 	close(fd);
** 	return (0);
** }
*/
