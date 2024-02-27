/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 00:09:19 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/28 00:18:31 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_check_cmds(t_pipex *px, char **argv)
{
	px->q = 0;
	px->q2 = 0;
	if (ft_strchr(argv[2], '/') != 0)
	{
		px->cmd1 = ft_split_p(argv[2], ' ', px);
		if (access(px->cmd1[0], F_OK) == -1)
		{
			perror("Error: Command 1 not found");
			return (EXIT_FAILURE);
		}
		px->q = 1;
	}
	if (ft_strchr(argv[3], '/') != 0)
	{
		px->cmd2 = ft_split_p(argv[3], ' ', px);
		if (access(px->cmd2[0], F_OK) == 0)
		{
			perror("Error: Command 2 not found");
			return (EXIT_FAILURE);
		}
		px->q2 = 1;
	}
	return (EXIT_SUCCESS);
}