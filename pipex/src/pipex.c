/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:56:59 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/23 11:43:09 by mancorte         ###   ########.fr       */
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
	ft_frees(px);
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
		perror("Error: Execve failed in first command\n");
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
	return (EXIT_SUCCESS);
}

int	ft_open_prepare_cmds(t_pipex *px, char **argv, char **envp)
{
	if (ft_open_files(px, argv) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	if (ft_find_path(px, envp) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	if (ft_prepare_cmds(px, argv) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	if (ft_join_cmds(px, argv) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
