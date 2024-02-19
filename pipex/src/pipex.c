/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:56:59 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/20 00:08:54 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int main(int argc, char **argv, char **envp)
{
    t_pipex pipex;
	pipex.i = 0;
    if (argc != 5)
    {
        printf("Error: Wrong number of arguments\n");
        return (1);
    }
    pipex.fd = open(argv[1], O_RDONLY);
    pipex.fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (pipex.fd == -1 || pipex.fd2 == -1)
    {
        printf("Error: File not found\n");
        return (1);
    }
	
    while (envp[pipex.i] != NULL)
	{
		if (ft_strstr(envp[pipex.i], "PATH") != 0)
			pipex.path = ft_strstr(envp[pipex.i], "PATH");
		pipex.i++;
	}
    return (0);
}