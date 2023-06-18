/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:09:39 by mancorte          #+#    #+#             */
/*   Updated: 2023/06/18 23:59:56 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s++)
			return (0);
	}
	return ((char *)s);
}

char	*ft_strjoin(char *stack, char *temp)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	len = ft_strlen(stack) + ft_strlen(temp);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!stack || !temp || !str)
		return (NULL);
	while (stack[i] != '\0')
	{
		str[i] = stack[i];
		i++;
	}
	while (temp[j] != '\0')
		str[i++] = temp[j++];
	str[i] = '\0';
	return (str);
}

char	*join_free(char *stack, char *temp)
{
	char	*str;

	if (!stack)
	{
		stack = malloc(1);
		stack[0] = '\0';
	}
	if (!stack)
		return (NULL);
	str = ft_strjoin(stack, temp);
	free (stack);
	return (str);
}
