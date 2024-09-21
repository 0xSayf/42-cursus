/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:07:57 by sahamzao          #+#    #+#             */
/*   Updated: 2024/09/11 14:58:52 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char **str)
{
	int	i;

	i = 0;
	ft_freee(str);
	write(2, "invalide map !~!~!\n", ft_sstrlen("invalide map !~!~!\n"));
	exit(0);
}

void	ft_freee(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_check_ber(char *str, char *ber)
{
	int	i;
	int	j;

	if (ft_sstrlen(str) == 1)
		ft_inv();
	i = ft_dotber(str);
	if (ft_sstrlen(&str[i]) != 4)
		ft_inv();
	j = 0;
	while (ber[j])
	{
		if (ber[j] != str[i])
			ft_inv();
		j++;
		i++;
	}
}

void	intial_varibles(t_game *game)
{
	game->coin = 0;
	game->bit = 0;
	game->exit = 0;
	game->player = 0;
	game->move = 0;
}

void	ft_requirement(t_game *game, char **arr)
{
	int	i;
	int	j;

	i = 0;
	intial_varibles(game);
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'C')
				game->coin++;
			else if (arr[i][j] == 'P')
				game->player++;
			else if (arr[i][j] == 'E')
				game->exit++;
			j++;
		}
		i++;
	}
	if (game->coin <= 0 || game->player != 1 || game->exit != 1)
	{
		ft_freee(game->map);
		ft_error(arr);
	}
}
