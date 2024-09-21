/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:26:12 by sahamzao          #+#    #+#             */
/*   Updated: 2024/09/11 15:00:43 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		exit(0);
	else if (ac == 2)
	{
		ft_check_ber(av[1], ".ber");
		game = malloc(sizeof(t_game));
		map_checking(av[1], game);
		ft_init_game(game);
		mlx_loop(game->mlx);
		free(game);
	}
}
