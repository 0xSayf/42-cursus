/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:35:05 by mben-abb          #+#    #+#             */
/*   Updated: 2025/02/10 23:35:09 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_cd_help(t_env *env)
{
	t_env	*tmp;
	int		status;

	if (!env)
		return (1);
	tmp = env;
	while (tmp)
	{
		if (ft_strncmp("HOME", tmp->var, 4) == 0)
			break ;
		tmp = tmp->next;
	}
	status = chdir(&tmp->var[5]);
	if (status == -1)
	{
		perror("No Working Dir");
		return (1);
	}
	return (0);
}

int	ft_cd(t_env *env, char **str)
{
	t_env	*tmp;
	int		status;

	if (!env)
		return (1);
	tmp = NULL;
	tmp = env;
	if (!str[1])
		return (ft_cd_help(tmp));
	else
	{
		status = chdir(str[1]);
		if (status == -1)
		{
			perror("No Working Dir");
			return (1);
		}
	}
	return (0);
}
