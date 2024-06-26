/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:29:35 by mancorte          #+#    #+#             */
/*   Updated: 2023/06/18 14:09:10 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_numlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	if (n <= 9 && n >= -9)
	{
		i++;
		return (i);
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
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
		nb = nb * 10 + (str[c++] - 48);
	if (min == 1)
		nb = nb * -1;
	return (nb);
}
