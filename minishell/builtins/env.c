/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:35:18 by mben-abb          #+#    #+#             */
/*   Updated: 2025/02/10 23:35:20 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_env(t_env *env)
{
	t_env	*tmp;

	if (!env)
		return (1);
	tmp = env;
	while (tmp)
	{
		if (tmp->var && *tmp->var != '?')
		{
			ft_putstr_fd(tmp->var, STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
		}
		tmp = tmp->next;
	}
	return (0);
}
