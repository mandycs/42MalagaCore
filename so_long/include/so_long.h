/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:09:12 by mancorte          #+#    #+#             */
/*   Updated: 2024/03/06 21:22:42 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_mapstats
{
	int				x;
	int				y;
	int				c;
	int				c_count;
	int				p;
	int				e;
	int				x_len;
	int				y_len;
	int				fd;
	int				i;
	int				j;
	int				x_c;
	int				y_c;
	int				x_p;
	int				y_p;
	int				status;
	char			*line;
	char			**map;
	int				**map_visit;
	int				x_init;
	int				y_init;
	int				x_exit;
	int				y_exit;
	int				pos_x;
	int				pos_y;
	int				keycode;
	mlx_t			*mlx;
	mlx_image_t		*floor;
	mlx_image_t		*wall;
	mlx_image_t		*collectible;
	mlx_image_t		*exit;
	mlx_image_t		*player;
	mlx_texture_t	*texture;

}					t_mapstats;

void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*get_next_line(int fd);
char				*ft_strchr(const char *s, int c);
char				*ft_join_and_free(char *s1, char *s2);
int					ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*create_line(char *stack);
char				*update_stack(char *stack);
int					ft_check_map(t_mapstats *ms);
int					check_char_map(t_mapstats *ms);
void				check_char_min_map(t_mapstats *ms);
int					check_border_map(t_mapstats *ms);
int					map_len_x(t_mapstats *ms, int y);
int					map_len_y(t_mapstats *ms);
int					check_len_map(t_mapstats *ms);
int					ft_read_map(t_mapstats *ms, char *argv);
int					ft_save_map(t_mapstats *ms);
int					ft_search_map(t_mapstats *ms);
void				ft_fill_visited_map(t_mapstats *ms);
int					move_right(t_mapstats *ms);
int					move_left(t_mapstats *ms);
int					move_up(t_mapstats *ms);
int					move_down(t_mapstats *ms);
int					ft_validate_map(t_mapstats *ms, char *argv);
void				ft_allocate_visited_map(t_mapstats *ms);
void				ft_iniciate(t_mapstats *ms);
int					ft_create_window(t_mapstats *ms);
void				ft_print_map(t_mapstats *ms);
void				ft_move(mlx_key_data_t keydata, void *param);
void				ft_move_down(t_mapstats *ms);
void				ft_move_up(t_mapstats *ms);
void				ft_move_left(t_mapstats *ms);
void				ft_move_right(t_mapstats *ms);
void				ft_check_collectible(t_mapstats *ms);
void				ft_print_exit(t_mapstats *ms);
#endif