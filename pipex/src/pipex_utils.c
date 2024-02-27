/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:07:57 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/27 22:18:42 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_open_files(t_pipex *px, char **argv)
{
	px->fd[0] = open(argv[1], O_RDONLY);
	if (px->fd[0] == -1)
	{
		perror("Error: First file not found");
		exit(EXIT_FAILURE);
	}
	px->fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (px->fd[1] == -1)
	{
		close(px->fd[0]);
		perror("Error: Second file not found");
		exit(EXIT_FAILURE);
	}
	if (pipe(px->fd) == -1)
	{
		close(px->fd[0]);
		close(px->fd[1]);
		perror("Error: Pipe failed");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

// Esto busca el path en el envp
int	ft_find_path(t_pipex *px, char **envp)
{
	px->i = 0;
	while (envp[px->i] != NULL)
	{
		if (ft_strncmp(envp[px->i], "PATH=", 5) == 0)
		{
			px->len_p = ft_strlen(envp[px->i]) + 1;
			px->path = malloc(sizeof(char) * px->len_p);
			if (px->path == NULL)
				return (EXIT_FAILURE);
			px->original_path = px->path;
			px->path = ft_strcpy(px->path, envp[px->i]);
			break ;
		}
		px->i++;
	}
	if(envp[px->i] == NULL)
		return (3);
	px->path += 5;
	px->cmds = ft_split_p(px->path, ':', px);
	free(px->original_path);
	if (px->cmds == NULL)
		exit(EXIT_FAILURE);
	px->len_p = px->n_str;
	px->i = 0;
	return (EXIT_SUCCESS);
}

int	ft_prepare_cmds(t_pipex *px, char **argv)
{
	px->cmds2 = malloc(sizeof(char *) * px->len_p);
	if (px->cmds2 == NULL)
	{
		free(px->cmds2);
		exit(EXIT_FAILURE);
	}
	px->cmd1 = ft_split_p(argv[2], ' ', px);
	while (px->i < px->len_p)
	{
		px->cmds[px->i] = ft_strjoin(px->cmds[px->i], "/");
		px->cmds2[px->i] = malloc(sizeof(char) * ft_strlen(px->cmds[px->i])
				+ 1);
		if (px->cmds2[px->i] == NULL)
			exit(EXIT_FAILURE);
		px->cmds2[px->i] = ft_strcpy(px->cmds2[px->i], px->cmds[px->i]);
		px->i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_join_cmds(t_pipex *px, char **argv)
{
	px->cmd2 = ft_split_p(argv[3], ' ', px);
	px->i = 0;
	while (px->i < px->len_p)
	{
		px->cmds[px->i] = ft_strjoin(px->cmds[px->i], px->cmd1[0]);
		px->cmds2[px->i] = ft_strjoin(px->cmds2[px->i], px->cmd2[0]);
		px->i++;
	}
	if (px->q == 0)
		ft_check_cmd1(px);
	if (px->q2 == 0)
		ft_check_cmd2(px);
	return (EXIT_SUCCESS);
}

char	**ft_split_p(char const *s, char c, t_pipex *px)
{
	if (!s)
		return (NULL);
	px->n_str = ft_count_words(s, c);
	px->strs = (char **)malloc((sizeof(char *) * (px->n_str + 1)));
	if (px->strs == NULL)
	{
		ft_free_arrays_2(px, "strs");
		return (NULL);
	}
	ft_fill_array(px->strs, s, c);
	px->strs[px->n_str] = NULL;
	return (px->strs);
}
