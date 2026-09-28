/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:24:01 by mancorte          #+#    #+#             */
/*   Updated: 2026/09/28 17:00:00 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strdup(const char *s)
{
	char	*line;
	int		n;

	n = gnl_strlen(s);
	line = (char *)malloc((size_t)n + 1);
	if (!line)
		return (NULL);
	n = 0;
	while (s[n] != '\0')
	{
		line[n] = s[n];
		n++;
	}
	line[n] = '\0';
	return (line);
}

char	*gnl_join(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1)
		return (gnl_strdup(s2));
	res = (char *)malloc((size_t)gnl_strlen(s1)
			+ (size_t)gnl_strlen(s2) + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	free(s1);
	j = -1;
	while (s2[++j])
		res[i + j] = s2[j];
	res[i + j] = '\0';
	return (res);
}

int	gnl_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	gnl_has_nl(char *buffer)
{
	if (buffer == NULL)
		return (0);
	while (*buffer != '\0')
	{
		if (*buffer == '\n')
			return (1);
		buffer++;
	}
	return (0);
}

int	gnl_line_len(char *buffer)
{
	int	n;

	n = 0;
	while (buffer[n] != '\0' && buffer[n] != '\n')
		n++;
	if (buffer[n] == '\n')
		n++;
	return (n);
}
