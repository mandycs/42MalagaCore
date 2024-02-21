/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:11:23 by mancorte          #+#    #+#             */
/*   Updated: 2024/02/21 17:00:03 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../ft_printf/include/ft_printf.h"
# include "../ft_printf/include/libft.h"

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>


typedef struct s_pipex
{
    int     fd;
    int		fd2;
    int		i;
	char	*path;
	char   **cmds;
	int		len_p;
}   t_pipex;


#endif