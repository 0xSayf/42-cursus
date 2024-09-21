/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:56:13 by sahamzao          #+#    #+#             */
/*   Updated: 2024/09/11 14:58:45 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_vovo(t_game *game)
{
	game->i = 0;
	while (game->map[game->i] != NULL && game != NULL)
	{
		game->j = 0;
		while (game->map[game->i][game->j])
		{
			if (game->map[game->i][game->j] == 'P')
			{
				game->x_player = game->j;
				game->y_player = game->i;
				break ;
			}
			game->j++;
		}
		game->i++;
	}
}

void	ft_lsaa9(char **str, char **ptr, int line)
{
	int	i;

	i = 0;
	while (ptr[line][i])
	{
		str[line][i] = ptr[line][i];
		i++;
	}
	str[line][i] = '\0';
}

void	ft_putnbr(int nb)
{
	char	n;

	if (nb < 10)
	{
		n = nb + '0';
		write(1, &n, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	ft_gogo(t_game *game)
{
	game->texture = mlx_load_png("./pngs/background.png");
	if (game->texture == NULL)
		ft_error(game->map);
	game->img = mlx_texture_to_image(game->mlx, game->texture);
}

void	ft_invalid(void)
{
	write(2, "invalid file !! \n", ft_sstrlen("invalid file !! \n"));
	exit(0);
}
