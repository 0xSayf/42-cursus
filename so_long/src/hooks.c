/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:52:52 by sahamzao          #+#    #+#             */
/*   Updated: 2024/09/07 20:29:26 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_up(t_game *game)
{
	if (game->map[(game->y_player) - 1][game->x_player] != '1')
	{
		if (game->map[(game->y_player) - 1][game->x_player] == 'C')
		{
			game->map[(game->y_player) - 1][game->x_player] = '0';
			ft_gogo(game);
			mlx_image_to_window(game->mlx, game->img, (game->x_player) * 70, 70
				* (game->y_player - 1));
			mlx_delete_texture(game->texture);
			mlx_delete_image(game->mlx, game->player_img);
			game->player_img = get_player(game);
			game->bit++;
		}
		else if (game->map[(game->y_player) - 1][game->x_player] == 'E'
			&& game->bit == game->coin)
		{
			game->player_img->instances->x += 70;
			ft_freee(game->map);
			mlx_close_window(game->mlx);
		}
		game->y_player--;
		game->player_img->instances->y -= 70;
		ft_putnbr(game->move++);
		write(1, "\n", 1);
	}
}

void	ft_down(t_game *game)
{
	if (game->map[(game->y_player) + 1][game->x_player] != '1')
	{
		if (game->map[(game->y_player) + 1][game->x_player] == 'C')
		{
			game->map[(game->y_player) + 1][game->x_player] = '0';
			ft_gogo(game);
			mlx_image_to_window(game->mlx, game->img, (game->x_player) * 70, 70
				* (game->y_player + 1));
			mlx_delete_texture(game->texture);
			mlx_delete_image(game->mlx, game->player_img);
			game->player_img = get_player(game);
			game->bit++;
		}
		else if (game->map[(game->y_player) + 1][game->x_player] == 'E'
			&& game->bit == game->coin)
		{
			game->player_img->instances->x += 70;
			ft_freee(game->map);
			mlx_close_window(game->mlx);
		}
		game->player_img->instances->y += 70;
		game->y_player++;
		ft_putnbr(game->move++);
		write(1, "\n", 1);
	}
}

void	ft_right(t_game *game)
{
	if (game->map[game->y_player][(game->x_player) + 1] != '1')
	{
		if (game->map[(game->y_player)][game->x_player + 1] == 'C')
		{
			game->map[(game->y_player)][game->x_player + 1] = '0';
			ft_gogo(game);
			mlx_image_to_window(game->mlx, game->img, (game->x_player + 1) * 70,
				70 * (game->y_player));
			mlx_delete_texture(game->texture);
			mlx_delete_image(game->mlx, game->player_img);
			game->player_img = get_player(game);
			game->bit++;
		}
		else if (game->map[(game->y_player)][game->x_player + 1] == 'E'
			&& game->bit == game->coin)
		{
			game->player_img->instances->x += 70;
			ft_freee(game->map);
			mlx_close_window(game->mlx);
		}
		game->player_img->instances->x += 70;
		game->x_player++;
		ft_putnbr(game->move++);
		write(1, "\n", 1);
	}
}

void	ft_left(t_game *game)
{
	if (game->map[game->y_player][(game->x_player) - 1] != '1')
	{
		if (game->map[(game->y_player)][game->x_player - 1] == 'C')
		{
			game->map[(game->y_player)][game->x_player - 1] = '0';
			ft_gogo(game);
			mlx_image_to_window(game->mlx, game->img, (game->x_player - 1) * 70,
				70 * (game->y_player));
			mlx_delete_texture(game->texture);
			mlx_delete_image(game->mlx, game->player_img);
			game->player_img = get_player(game);
			game->bit++;
		}
		else if (game->map[(game->y_player)][game->x_player - 1] == 'E'
			&& game->bit == game->coin)
		{
			game->player_img->instances->x -= 70;
			ft_freee(game->map);
			mlx_close_window(game->mlx);
		}
		game->player_img->instances->x -= 70;
		game->x_player--;
		ft_putnbr(game->move++);
		write(1, "\n", 1);
	}
}

void	*get_player(t_game *game)
{
	game->texture = mlx_load_png("./pngs/charactere.png");
	if (game->texture == NULL)
		ft_error(game->map);
	game->img = mlx_texture_to_image(game->mlx, game->texture);
	mlx_image_to_window(game->mlx, game->img, game->x_player * 70,
		game->y_player * 70);
	mlx_delete_texture(game->texture);
	return (game->img);
}
