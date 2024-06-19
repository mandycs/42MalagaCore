/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:21:03 by mancorte          #+#    #+#             */
/*   Updated: 2024/06/19 16:33:52 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_arr_num(const char *s, char c)
{
	int	cnt;
	int	arr_num;

	cnt = 0;
	arr_num = 0;
	while (s[cnt] != '\0')
	{
		if (s[cnt] != c)
		{
			while (s[cnt] && s[cnt] != c)
				cnt++;
			arr_num++;
		}
		else
			cnt++;
	}
	return (arr_num);
}

static char	*get_arr(const char *s, char c)
{
	char	*arr;
	int		cnt;

	cnt = 0;
	while (s[cnt] != '\0' && s[cnt] != c)
		cnt++;
	arr = malloc((cnt + 1) * sizeof(char));
	if (!arr)
		return (0);
	cnt = 0;
	while (s[cnt] && s[cnt] != c)
	{
		arr[cnt] = s[cnt];
		cnt++;
	}
	arr[cnt] = '\0';
	return (arr);
}

static char	**free_mem(char **str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
	{
		free(str[cnt]);
		cnt++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		cnt;
	int		num_arr;
	char	**arrr;

	num_arr = get_arr_num(s, c);
	arrr = malloc((num_arr + 1) * sizeof(char *));
	if (!arrr)
		return (0);
	cnt = 0;
	while (*s && cnt < num_arr)
	{
		while (*s && *s == c)
			s++;
		arrr[cnt] = get_arr(s, c);
		if (!arrr[cnt])
		{
			arrr = free_mem(arrr);
			return (0);
		}
		cnt++;
		while (*s != c && *s)
			s++;
	}
	arrr[cnt] = 0;
	return (arrr);
}

int	ft_atoi(const char *c)
{
	int	num;
	int	cnt;
	int	sign;

	sign = 1;
	num = 0;
	cnt = 0;
	while ((c[cnt] >= 9 && c[cnt] <= 13) || c[cnt] == 32)
		cnt++;
	if (c[cnt] == '-' || c[cnt] == '+')
	{
		if (c[cnt] == '-')
			sign = -1;
		cnt++;
	}
	while ((c[cnt] >= '0' && c[cnt] <= '9') && c[cnt] != '\0')
	{
		num = num * 10 + (c[cnt] - 48);
		cnt++;
	}
	return (num * sign);
}
