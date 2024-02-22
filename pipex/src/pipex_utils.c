/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:07:57 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/22 00:31:15 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int ft_open_files(t_pipex *px, char **argv)
{
	px->fd[0] = open(argv[1], O_RDONLY);
	px->fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (px->fd[0] == -1 || px->fd[1] == -1)
	{
		perror("Error: File not found");
		exit(EXIT_FAILURE);
	}
	if (pipe(px->fd) == -1)
	{
		perror("Error: Pipe failed");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

	// Esto busca el path en el envp
int ft_find_path(t_pipex *px, char **envp)
{
	px->i = 0;
	while (envp[px->i] != NULL)
	{
		if (ft_strstr(envp[px->i], "PATH") != 0)
		{
			px->len_p = ft_strlen(envp[px->i]);
			px->path = malloc(sizeof(char) * px->len_p);
			if (px->path == NULL)
			{
				free(px->path);
				exit(EXIT_FAILURE);
			}
			px->original_path = px->path;
			px->path = ft_strstr(envp[px->i], "PATH");
		}
		px->i++;
	}
	px->path += 5;
	px->cmds = ft_split_p(px->path, ':', px);
	px->len_p = px->n_str;
	px->i = 0;
	free(px->original_path);
	return (EXIT_SUCCESS);
}

int ft_prepare_cmds(t_pipex *px, char **argv)
{
	px->cmds_cpy = malloc(sizeof(char *) * px->len_p);
	if (px->cmds_cpy == NULL)
	{
		exit(EXIT_FAILURE);
		free(px->cmds_cpy);
	}
	px->cmd1 = ft_split_p(argv[2], ' ', px);
	px->cmd2 = ft_split_p(argv[3], ' ', px);
	while (px->i < px->len_p)
	{
		px->cmds[px->i] = ft_strjoin(px->cmds[px->i], "/");
		px->cmds_cpy[px->i] = malloc(sizeof(char) * ft_strlen(px->cmds[px->i]));
		if (px->cmds_cpy[px->i] == NULL)
		{
			free(px->cmds_cpy);//Cambiarlo por la funcion de free bidimensioanl
			exit(EXIT_FAILURE);
		}
		px->cmds_cpy[px->i] = ft_strcpy(px->cmds_cpy[px->i], px->cmds[px->i]);
		px->i++;
	}
}
int ft_join_cmds(t_pipex *px)
{
	px-> = 0;
	px->i = 0;
	while (px->i < px->len_p)
	{
		px->cmds[px->i] = ft_strjoin(px->cmds[px->i], px->cmd1[0]);
		px->cmds_cpy[px->i] = ft_strjoin(px->cmds_cpy[px->i], px->cmd2[0]);
		px->i++;
	}
	while (px-> < px->len_p)
	{
		if (access(px->cmds[px->i], F_OK) == 0)
			break ;
		px->i++;
	}
	px->pathcmd = px->cmds[px->i];
	px->i = 0;
	while (px->i < px->len_p)
	{
		if (access(px->cmds_cpy[px->i], F_OK) == 0)
			break ;
		px->i++;
	}
	px->pathcmd2 = px->cmds_cpy[px->i];
	return (EXIT_SUCCESS);
}

char	**ft_split_p(char const *s, char c, t_pipex *pipex)
{
	char	**strs;

	if (!s)
		return (NULL);
	pipex->n_str = ft_count_words(s, c);
	strs = (char **)malloc((sizeof(char *) * (pipex->n_str + 1)));
	if (!strs)
		return (NULL);
	ft_fill_array(strs, s, c);
	strs[pipex->n_str] = NULL;
	return (strs);
}
