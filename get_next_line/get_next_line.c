/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucortes <jucortes@student.42malaga.com>          +#+  +:+       +#+ */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:24:03 by jucortes          #+#    #+#             */
/*   Updated: 2026/09/28 17:00:00 by jucortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = gnl_fill(fd, &save);
	return (line);
}

char	*gnl_fill(int fd, char **save)
{
	char	*buffer;
	char	*joined;
	long	bytes;

	bytes = 1;
	while (bytes > 0 && !gnl_has_nl(*save))
	{
		buffer = gnl_read_buffer(fd, &bytes);
		if (!buffer)
		{
			free(*save);
			*save = NULL;
			return (NULL);
		}
		joined = gnl_join(*save, buffer);
		free(buffer);
		if (!joined)
			return (NULL);
		*save = joined;
	}
	return (gnl_split_line(*save, save));
}

char	*gnl_read_buffer(int fd, long *bytes)
{
	char	*buf;

	buf = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	*bytes = (long)read(fd, buf, (size_t)BUFFER_SIZE);
	if (*bytes < 0)
	{
		free(buf);
		return (NULL);
	}
	buf[*bytes] = '\0';
	return (buf);
}

char	*gnl_split_line(char *buffer, char **save)
{
	char	*line;
	int		n;

	if (!buffer || *buffer == '\0')
	{
		free(buffer);
		*save = NULL;
		return (NULL);
	}
	n = gnl_line_len(buffer);
	line = gnl_copy_n(buffer, n);
	if (!line)
	{
		free(buffer);
		*save = NULL;
		return (NULL);
	}
	if (buffer[n] == '\0')
		*save = NULL;
	else
		*save = gnl_strdup(buffer + n);
	free(buffer);
	return (line);
}

char	*gnl_copy_n(char *src, int n)
{
	char	*line;
	int		i;

	line = (char *)malloc((size_t)n + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < n)
	{
		line[i] = src[i];
		i++;
	}
	line[n] = '\0';
	return (line);
}
