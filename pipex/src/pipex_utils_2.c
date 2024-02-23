/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:21:46 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/23 11:50:43 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_free_arrays(t_pipex *px, char *flag)
{
	px->j = 0;
	if (ft_strcmp(flag, "cmds") == 0)
	{
		while (px->j < px->len_p)
		{
			free(px->cmds[px->j]);
			px->j++;
		}
		free(px->cmds);
	}
	else if (ft_strcmp(flag, "cmds_cpy") == 0)
	{
		while (px->j < px->len_p)
		{
			free(px->cmds_cpy[px->j]);
			px->j++;
		}
		free(px->cmds_cpy);
	}
	else if (ft_strcmp(flag, "strs"))
	{
		while (px->j < px->n_str)
		{
			free(px->strs[px->j]);
			px->j++;
		}
		free(px->strs);
	}
}

void	ft_frees(t_pipex *px)
{
	ft_free_arrays(px, "cmds");
	ft_free_arrays(px, "cmds_cpy");
	ft_free_arrays(px, "strs");
}