/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:37:00 by sahamzao          #+#    #+#             */
/*   Updated: 2024/09/04 14:18:48 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include "../../mlx/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game
{
	int				x_len;
	int				y_len;
	char			**map;
	int				coin;
	int				bit;
	int				player;
	int				exit;
	int				x_player;
	int				y_player;
	int				i;
	int				move;
	int				j;
	mlx_image_t		*player_img;
	mlx_image_t		*img;
	mlx_texture_t	*texture;
	mlx_t			*mlx;
}					t_game;

typedef struct so_long
{
	int				i;
	int				y;
	int				size;
}					t_variable;

void				get_len(t_game *game);
void				ft_backgroud(t_game *game);
void				ft_assets(t_game *game);
void				ft_error(char **str);
int					ft_dotber(char *str);
void				ft_up(t_game *game);
void				ft_init_game(t_game *game);
void				ft_keyhook(mlx_key_data_t keydata, void *param);
void				ft_right(t_game *game);
char				*get_next_line(int fd);
void				*ft_cpy(char *string, char *string1, int n);
int					ft_newline_check(char *string);
int					ft_sstrlen(char *string);
void				allocation_manager(int fd, char **save);
char				*ft_strcat(char *string1, char *string2);
void				ft_left(t_game *game);
void				ft_down(t_game *game);
void				*get_player(t_game *game);
void				ft_requirement(t_game *game, char **arr);
void				ft_flood_fill(char **str, int i, int j);
void				ft_check_ber(char *str, char *ber);
char				**ft_replace(char *str);
void				map_checking(char *str, t_game *game);
char				**ft_copy(char **str);
void				ft_lsaa9(char **str, char **ptr, int line);
void				ft_freee(char **str);
void				ft_chek(t_game *game);
void				ft_vovo(t_game *game);
void				ft_lsaa9(char **str, char **ptr, int line);
void				ft_help(t_game *game);
char				**ft_split(char const *s, char c);
char				*ft_strdup(char *s1);
void				ft_putnbr(int nb);
void				ft_gogo(t_game *game);
void				ft_invalid(void);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_inv(void);

#endif