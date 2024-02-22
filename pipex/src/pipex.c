/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:56:59 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/22 00:39:35 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;

	if (argc != 5)
	{
		perror("Error: Wrong number of arguments");
		exit(EXIT_FAILURE);
	}
	if (ft_open_prepare_cmds(&px, argv, envp) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	if (pipe(px.fd) == -1)
	{
		perror("Error: Pipe failed\n");
		exit(EXIT_FAILURE);
	}
	px.pid1 = fork();
	if (px.pid1 == -1)
	{
		perror("Error: Fork failed");
		exit(EXIT_FAILURE);
	}
	if (ft_fork_process(&px, argv, envp) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

int	ft_fork_process(t_pipex *px, char **argv, char **envp)
{
	if (px->pid1 == 0)
	{
		ft_execute_first_command(px, argv, envp);
	}
	else
	{
		close(px->fd[1]);
		waitpid(px->pid1, &px->status, 0);
		px->pid2 = fork();
		if (px->pid2 == -1)
		{
			perror("Error: Fork failed");
			exit(EXIT_FAILURE);
		}
		if (px->pid2 == 0)
			ft_execute_second_command(px, argv, envp);
		else
		{
			close(px->fd[0]);
			waitpid(px->pid2, &px->status, 0);
			waitpid(px->pid1, &px->status, 0);
		}
	}
	return (EXIT_SUCCESS);
}

int	ft_execute_first_command(t_pipex *px, char **argv, char **envp)
{
	close(px->fd[0]);
	if (dup2(px->fd[1], STDOUT_FILENO) == -1)
	{
		perror("Error: Dup2 failed");
		exit(EXIT_FAILURE);
	}
	close(px->fd[1]);
	px->fd_in = open(argv[1], O_RDONLY);
	if (px->fd_in == -1)
	{
		perror("Error: File not found");
		exit(EXIT_FAILURE);
	}
	if (dup2(px->fd_in, STDIN_FILENO) == -1)
	{
		perror("Error: Dup2 failed");
		exit(EXIT_FAILURE);
	}
	close(px->fd_in);
	if (execve(px->pathcmd, px->cmd1, envp) == -1)
	{
		perror("Error: Execve failed");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

int	ft_execute_second_command(t_pipex *px, char **argv, char **envp)
{
	close(px->fd[1]);
	if (dup2(px->fd[0], STDIN_FILENO) == -1)
	{
		perror("Error: Dup2 failed");
		exit(EXIT_FAILURE);
	}
	close(px->fd[0]);
	px->fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (px->fd_out == -1)
	{
		perror("Error: File not found");
		exit(EXIT_FAILURE);
	}
	if (dup2(px->fd_out, STDOUT_FILENO) == -1)
	{
		perror("Error: Dup2 failed");
		exit(EXIT_FAILURE);
	}
	close(px->fd_out);
	if (execve(px->pathcmd2, px->cmd2, envp) == -1)
	{
		perror("Error: Execve failed");
		exit(EXIT_FAILURE);
	}
	return(EXIT_SUCCESS);
}

int	ft_open_prepare_cmds(t_pipex *px, char **argv, char **envp)
{
	if (ft_open_files(px, argv) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	if (ft_find_path(px, envp) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	if (ft_prepare_cmds(px, argv) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	if (ft_join_cmds(px) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	return(EXIT_SUCCESS);
}

int	ft_open_files(t_pipex *px, char **argv)
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
int	ft_find_path(t_pipex *px, char **envp)
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

int	ft_prepare_cmds(t_pipex *px, char **argv)
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
			free(px->cmds_cpy);
				// Cambiarlo por la funcion de free bidimensioanl
			exit(EXIT_FAILURE);
		}
		px->cmds_cpy[px->i] = ft_strcpy(px->cmds_cpy[px->i], px->cmds[px->i]);
		px->i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_join_cmds(t_pipex *px)
{
	px->i = 0;
	px->i = 0;
	while (px->i < px->len_p)
	{
		px->cmds[px->i] = ft_strjoin(px->cmds[px->i], px->cmd1[0]);
		px->cmds_cpy[px->i] = ft_strjoin(px->cmds_cpy[px->i], px->cmd2[0]);
		px->i++;
	}
	while (px->i < px->len_p)
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
	printf("He salido de join_cmds\n");
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
