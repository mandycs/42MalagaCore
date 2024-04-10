/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:32:30 by marvin            #+#    #+#             */
/*   Updated: 2024/03/19 00:32:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_atoi(char *str)
{
	int		c;
	long	nb;
	int		min;

	c = 0;
	nb = 0;
	min = 0;
	while (str[c] == 32 || (str[c] >= 9 && str[c] <= 13))
		c++;
	if (str[c] == '-')
	{
		min = 1;
		c++;
	}
	else if (str[c] == '+')
		c++;
	while (str[c] >= '0' && str[c] <= '9')
	{
		nb = nb * 10 + (str[c] - 48);
		c++;
	}
	if (min == 1)
		nb = nb * -1;
	return (nb);
}

int	ft_isdigit(char *str)
{
	int c;

	c = 0;
	if (str[c] == '-' || str[c] == '+')
		c++;
	while (str[c])
	{
		if (str[c] < '0' || str[c] > '9')
			return (0);
		c++;
	}
	return (1);
}

char	**ft_split(char *s, char c, t_push_swap *ps)
{
	char	**strs;

	if (!s)
		return (NULL);
	ps->n_str = ft_count_words(s, c);
	strs = (char **)malloc((sizeof(char *) * (ps->n_str + 1)));
	if (!strs)
		return (NULL);
	ft_fill_array(strs, s, c);
	strs[ps->n_str] = NULL;
	return (strs);
}

int	ft_count_words(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_fill_array(char **strs, char *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		j = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (j >= ft_strlen(s))
		{
			strs[k] = NULL;
			k++;
		}
		else
			strs[k++] = ft_substr(s, j, i - j);
	}
	return (strs);
}
