/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:11:23 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/21 19:41:28 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../ft_printf/include/ft_printf.h"
# include "../ft_printf/include/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		fd[2];
	int		i;
	char	*path;
	char	**cmds;
	int		len_p;
	char	*original_path;
	char	**cmds_cpy;
	int		n_str;
	char	**cmd1;
	char	**cmd2;
	char	*pathcmd;
	char	*pathcmd2;
}			t_pipex;


#endif