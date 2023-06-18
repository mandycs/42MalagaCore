/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:40:23 by mancorte          #+#    #+#             */
/*   Updated: 2023/06/19 00:16:01 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*create_line(char *stack)
{
	char	*line;
	int		i;

	i = 0;
	if (stack || !*stack)
		return (NULL);
	while (stack[i] != '\n' && stack[i] != '\0')
		i++;
	if (stack[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
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
	char	*new_stack;
	char	*temp;
	int		i;

	i = 0;
	temp = (ft_strchr(stack, '\n'));
	if (!temp)
	{
		free(stack);
		return (NULL);
	}
	temp++;
	new_stack = malloc(sizeof(char) * (ft_strlen(temp) + 1));
	if (!new_stack)
		return (NULL);
	while (*temp != '\0')
	{
		new_stack[i++] = *temp;
		temp++;
	}
	new_stack[i] = '\0';
	free(stack);
	return (new_stack);
}

char	*get_next_line(int fd)
{
	static char	*stack = NULL;
	char		tmp[BUFFER_SIZE + 1];
	char		*line;
	size_t		readbytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readbytes = 1;
	while ((!ft_strchr(stack, '\n')) && readbytes > 0)
	{
		readbytes = read(fd, tmp, BUFFER_SIZE);
		if (readbytes < 0)
		{
			free(stack);
			return (NULL);
		}
		tmp[readbytes] = '\0';
		stack = join_free(stack, tmp);
	}
	line = create_line(stack);
	stack = update_stack(stack);
	return (line);
}
