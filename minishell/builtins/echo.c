/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:34:57 by mben-abb          #+#    #+#             */
/*   Updated: 2025/02/10 23:35:14 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_echo(char **arg)
{
	int	dash_n;
	int	i;

	dash_n = 0;
	i = 0;
	i++;
	if (arg[i] && !ft_strcmp(arg[i], "-n"))
	{
		i++;
		dash_n = 1;
	}
	while (arg[i])
	{
		ft_putstr_fd(arg[i], STDOUT_FILENO);
		if (arg[i + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	if (!dash_n)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}
