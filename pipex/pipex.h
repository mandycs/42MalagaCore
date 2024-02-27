/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:11:23 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/26 16:51:22 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../ft_printf/include/ft_printf.h"
# include "../ft_printf/include/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		fd[2];
	int		i;
	char	*path;
	char	**cmds;
	int		len_p;
	char	*original_path;
	char	**cmds2;
	int		n_str;
	char	**cmd1;
	char	**cmd2;
	char	*pathcmd;
	char	*pathcmd2;
	pid_t	pid1;
	pid_t	pid2;
	int		fd_in;
	int		fd_out;
	int		status;
	int		j;
	int		k;
	char	**strs;
	char	*path_env;
	int		p;
}			t_pipex;

char		**ft_split_p(char const *s, char c, t_pipex *pipex);
int			main(int argc, char **argv, char **envp);
int			ft_open_prepare_cmds(t_pipex *px, char **argv, char **envp);
int			ft_open_files(t_pipex *px, char **argv);
int			ft_find_path(t_pipex *px, char **envp);
int			ft_prepare_cmds(t_pipex *px, char **argv);
int			ft_join_cmds(t_pipex *px, char **argv);
int			ft_execute_first_command(t_pipex *px, char **argv, char **envp);
int			ft_fork_process(t_pipex *px, char **argv, char **envp);
int			ft_execute_second_command(t_pipex *px, char **argv, char **envp);
void		ft_free_arrays(t_pipex *px, char *flag);
void		ft_frees(t_pipex *px);
int			ft_check_cmds(t_pipex *px);
void		ft_free_arrays_2(t_pipex *px, char *flag);

#endif