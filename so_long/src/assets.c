/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:42:34 by sahamzao          #+#    #+#             */
/*   Updated: 2024/09/11 14:59:34 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_backgroud(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = 70 * game->x_len;
	y = 70 * game->y_len;
	game->mlx = mlx_init(x, y, "so_long", true);
	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			game->texture = mlx_load_png("./pngs/background.png");
			if (game->texture == NULL)
				ft_invalid();
			game->img = mlx_texture_to_image(game->mlx, game->texture);
			mlx_image_to_window(game->mlx, game->img, i, j);
			mlx_delete_texture(game->texture);
			j += 70;
		}
		i += 70;
	}
}

void	ft_object(t_game *game, char *str, int y, int i)
{
	game->texture = mlx_load_png(str);
	if (game->texture == NULL)
		ft_invalid();
	game->img = mlx_texture_to_image(game->mlx, game->texture);
	mlx_image_to_window(game->mlx, game->img, y * 70, i * 70);
	mlx_delete_texture(game->texture);
}

void	ft_assets(t_game *game)
{
	t_variable	var;

	var.i = 0;
	while (game->map[var.i])
	{
		var.y = 0;
		while (game->map[var.i][var.y])
		{
			if (game->map[var.i][var.y] == '1')
				ft_object(game, "./pngs/7ayt.png", var.y, var.i);
			else if (game->map[var.i][var.y] == 'C')
				ft_object(game, "./pngs/cii.png", var.y, var.i);
			else if (game->map[var.i][var.y] == 'E')
				ft_object(game, "./pngs/exit.png", var.y, var.i);
			var.y++;
		}
		var.i++;
	}
}
