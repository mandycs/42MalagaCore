/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:24:03 by mancorte          #+#    #+#             */
/*   Updated: 2023/11/07 22:43:45 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stack;
	char		tmp[BUFFER_SIZE + 1];
	char		*line;
	int			readbytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readbytes = 1;
	while (!ft_strchr(stack, '\n') && readbytes > 0)
	{
		readbytes = read(fd, tmp, BUFFER_SIZE);
		if (readbytes < 0)
		{
			free(stack);
			stack = NULL;
			return (NULL);
		}
		tmp[readbytes] = '\0';
		stack = ft_join_and_free(stack, tmp);
	}
	line = create_line(stack);
	stack = update_stack(stack);
	return (line);
}

char	*create_line(char *stack)
{
	char	*line;
	int		i;

	if (!stack || !*stack)
		return (NULL);
	i = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	if (stack[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stack[i] && stack[i] != '\n')
	{
		line[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_stack(char *stack)
{
	char	*aux;
	char	*p;
	int		i;

	p = ft_strchr(stack, '\n');
	if (!p)
	{
		free(stack);
		return (NULL);
	}
	p++;
	aux = malloc(sizeof(char) * (ft_strlen(p) + 1));
	if (!aux)
		return (NULL);
	i = 0;
	while (*p != '\0')
	{
		aux[i] = *p;
		i++;
		p++;
	}
	aux[i] = '\0';
	free(stack);
	return (aux);
}
