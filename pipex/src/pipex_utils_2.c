/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:21:46 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/27 10:20:41 by mancorte         ###   ########.fr       */
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
	else if (ft_strcmp(flag, "cmds2") == 0)
	{
		while (px->j < px->len_p)
		{
			free(px->cmds2[px->j]);
			px->j++;
		}
		free(px->cmds2);
	}
}

void	ft_free_arrays_2(t_pipex *px, char *flag)
{
	px->j = 0;
	if (ft_strcmp(flag, "strs") == 0)
	{
		while (px->j < px->n_str)
		{
			free(px->strs[px->j]);
			px->j++;
		}
		free(px->strs);
	}
	else if (ft_strcmp(flag, "cmd1") == 0)
	{
		while (px->j < px->n_str)
		{
			free(px->cmd1[px->j]);
			px->j++;
		}
		free(px->cmd1);
	}
}

void	ft_frees(t_pipex *px)
{
	ft_free_arrays(px, "cmds");
	ft_free_arrays(px, "cmds2");
	ft_free_arrays_2(px, "strs");
	ft_free_arrays_2(px, "cmd1");
}

int	ft_check_cmds(t_pipex *px)
{
	px->i = 0;
	while (px->i < px->len_p)
	{
		if (access(px->cmds[px->i], F_OK) == 0)
			break ;
		px->i++;
	}
	px->pathcmd = px->cmds[px->i];
	px->p = 0;
	while (px->p < px->len_p)
	{
		if (access(px->cmds2[px->p], F_OK) == 0)
			break ;
		px->p++;
	}
	if (px->i == px->len_p || px->p == px->len_p)
	{
		ft_frees(px);
		perror("Error: Esto es donde fallo");
		exit(EXIT_FAILURE);
	}
	px->pathcmd2 = px->cmds2[px->i];
	return (EXIT_SUCCESS);
}
