/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:16:44 by mancorte          #+#    #+#             */
/*   Updated: 2023/05/31 13:01:18 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		n_str;

	if (!s)
		return (NULL);
	n_str = ft_count_words(s, c);
	strs = (char **)malloc((sizeof(char *) * (n_str + 1)));
	if (!strs)
		return (NULL);
	ft_fill_array(strs, s, c);
	strs[n_str] = NULL;
	return (strs);
}
