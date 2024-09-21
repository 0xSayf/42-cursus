/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:47:48 by sahamzao          #+#    #+#             */
/*   Updated: 2024/09/11 14:36:25 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_len(t_game *game)
{
	int	i;

	if (game == NULL || game->map == NULL)
	{
		game->x_len = 0;
		game->y_len = 0;
		return ;
	}
	i = 0;
	while (game->map[i] != NULL)
		i++;
	game->x_len = ft_sstrlen(game->map[0]);
	game->y_len = i;
}

char	**ft_copy(char **str)
{
	t_variable	var;
	char		**ret;

	var.size = 0;
	while (str[var.size])
		var.size++;
	ret = malloc(sizeof(char *) * (var.size + 1));
	var.i = 0;
	var.y = 0;
	while (var.i < var.size)
	{
		while (str[var.i][var.y])
			var.y++;
		ret[var.i] = malloc(var.y + 1);
		if (!ret[var.i])
		{
			free(ret[var.i]);
			return (NULL);
		}
		ft_lsaa9(ret, str, var.i);
		var.i++;
	}
	ret[var.i] = NULL;
	return (ret);
}

void	ft_help(t_game *game)
{
	int	i;

	game->i = 0;
	while (game->map[0][game->i] && game != NULL)
	{
		if (game->map[0][game->i] != '1')
			ft_error(game->map);
		game->i++;
	}
	game->i = 0;
	while (game->map[game->i] != NULL && game != NULL)
	{
		if (game->map[game->i][0] != '1')
			ft_error(game->map);
		game->i++;
	}
	i = 0;
	while (game->map[game->i - 1][i] && game != NULL)
	{
		if (game->map[game->i - 1][i] != '1')
			ft_error(game->map);
		i++;
	}
}

void	ft_chek(t_game *game)
{
	int	size;

	size = ft_sstrlen(game->map[0]);
	game->i = 1;
	while (game->map[game->i] != NULL && game != NULL)
	{
		if (ft_sstrlen(game->map[game->i]) != size)
			ft_error(game->map);
		game->i++;
	}
	ft_help(game);
	game->i -= 1;
	while (game->i > 0)
	{
		if (game->map[game->i][size - 1] != '1')
			ft_error(game->map);
		game->i--;
	}
}

void	map_checking(char *str, t_game *game)
{
	char	**chek;

	game->map = ft_replace(str);
	chek = ft_copy(game->map);
	ft_requirement(game, chek);
	ft_chek(game);
	ft_vovo(game);
	ft_flood_fill(chek, game->x_player, game->y_player);
	game->i = 0;
	while (chek[game->i])
	{
		game->j = 0;
		while (chek[game->i][game->j])
		{
			if (chek[game->i][game->j] == '0' || chek[game->i][game->j] == 'C')
			{
				ft_freee(game->map);
				ft_error(chek);
			}
			game->j++;
		}
		game->i++;
	}
	ft_freee(chek);
}
