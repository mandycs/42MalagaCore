/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:56:59 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/21 20:58:29 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;

	px.i = 0;
	if (argc != 5)
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	px.fd[0] = open(argv[1], O_RDONLY);
	px.fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (px.fd[0] == -1 || px.fd[1] == -1)
	{
		printf("Error: File not found\n");
		return (1);
	}
	if (pipe(px.fd) == -1)
	{
		printf("Error: Pipe failed\n");
		return (1);
	}
	// Esto busca el path en el envp
	while (envp[px.i] != NULL)
	{
		if (ft_strstr(envp[px.i], "PATH") != 0)
		{
			px.len_p = ft_strlen(envp[px.i]);
			px.path = malloc(sizeof(char) * px.len_p);
			if (px.path == NULL)
				return (1);
			px.original_path = px.path;
			px.path = ft_strstr(envp[px.i], "PATH");
		}
		px.i++;
	}
	px.path += 5;
	px.cmds = ft_split_p(px.path, ':', &px);
	px.len_p = px.n_str;
	px.i = 0;
	free(px.original_path);
	px.cmds_cpy = malloc(sizeof(char *) * px.len_p);
	if (px.cmds_cpy == NULL)
		return (1);
	// División de los comandos por si tienen argumentos
	px.cmd1 = ft_split_p(argv[2], ' ', &px);
	px.cmd2 = ft_split_p(argv[3], ' ', &px);
	// Esto crea dos arrays con los comandos que se encuentran en el path con la barras al final
	while (px.i < px.len_p)
	{
		px.cmds[px.i] = ft_strjoin(px.cmds[px.i], "/");
		px.cmds_cpy[px.i] = malloc(sizeof(char) * ft_strlen(px.cmds[px.i]));
		if (px.cmds_cpy[px.i] == NULL)
			return (1);
		px.cmds_cpy[px.i] = ft_strcpy(px.cmds_cpy[px.i], px.cmds[px.i]);
		px.i++;
	}
	px.i = 0;
	while (px.i < px.len_p)
	{
		px.cmds[px.i] = ft_strjoin(px.cmds[px.i], px.cmd1[0]);
		px.cmds_cpy[px.i] = ft_strjoin(px.cmds_cpy[px.i], px.cmd2[0]);
		px.i++;
	}
	px.i = 0;
	// Esto busca el path del primer comando
	while (px.i < px.len_p)
	{
		if (access(px.cmds[px.i], F_OK) == 0)
			break;
		px.i++;
	}
	px.pathcmd = px.cmds[px.i];
	px.i = 0;
	while(px.i < px.len_p)
	{
		if(access(px.cmds_cpy[px.i], F_OK) == 0)
			break;
		px.i++;
	}
	px.pathcmd2 = px.cmds_cpy[px.i];
	
}
