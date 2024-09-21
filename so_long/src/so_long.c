/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:32:34 by sahamzao          #+#    #+#             */
/*   Updated: 2024/09/11 14:59:05 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_replace(char *str)
{
	int			fd;
	static char	*ptr;
	char		*tet;
	char		*tet1;
	char		**arr;

	fd = open(str, O_RDWR, 0777);
	if (fd < 0 || !str)
		ft_invalid();
	tet1 = get_next_line(fd);
	if (tet1 == NULL)
		ft_invalid();
	while (tet1 != NULL)
	{
		tet = ft_strdup(tet1);
		free(tet1);
		ptr = ft_strcat(ptr, tet);
		free(tet);
		tet1 = get_next_line(fd);
	}
	arr = ft_split(ptr, '\n');
	close(fd);
	return (arr);
}

void	ft_flood_fill(char **str, int i, int j)
{
	int	rows;
	int	cols;

	rows = 0;
	while (str[rows])
	{
		cols = 0;
		while (str[rows][cols])
			cols++;
		rows++;
	}
	if (i < 0 || i > cols || j < 0 || j > rows)
		return ;
	if (str[j][i] == '1' || str[j][i] == 't')
		return ;
	if (str[j][i] != '0' && str[j][i] != 'P' && str[j][i] != 'C'
		&& str[j][i] != 'E')
		return ;
	str[j][i] = 't';
	ft_flood_fill(str, i + 1, j);
	ft_flood_fill(str, i - 1, j);
	ft_flood_fill(str, i, j + 1);
	ft_flood_fill(str, i, j - 1);
	return ;
}

void	ft_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*yy;

	yy = param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		ft_freee(yy->map);
		mlx_close_window(yy->mlx);
	}
	else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action)
		ft_up(yy);
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action)
		ft_down(yy);
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action)
		ft_left(yy);
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action)
		ft_right(yy);
}

void	ft_init_game(t_game *game)
{
	get_len(game);
	ft_backgroud(game);
	ft_assets(game);
	game->player_img = get_player(game);
	mlx_key_hook(game->mlx, ft_keyhook, game);
}
