/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsix3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:36:51 by mben-abb          #+#    #+#             */
/*   Updated: 2025/02/10 23:36:52 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_norm_rvr(t_norm *norm, t_vrom *vrom)
{
	free(norm->gg);
	vrom->save = ft_strcat(vrom->save, " ");
	vrom->ret = ft_strcat(vrom->ret, vrom->save);
	free(vrom->save);
}

void	ft_rvrvr(t_norm *norm, t_vrom *vrom, t_env *tmp)
{
	vrom->save = ft_strcat(vrom->save, ft_strchr(tmp->var, '=') + 1);
	vrom->ret = ft_strcat(vrom->ret, vrom->save);
	free(vrom->save);
	free(norm->ptr);
	free(norm->gg);
}

int	ft_check_exp(char *line)
{
	int	i;

	i = 0;
	if (!ft_isalpha(line[i]) && line[i] != '_')
		return (0);
	while (line[i])
	{
		if (line[i] == '=')
			return (1);
		if (!ft_isalnum(line[i]) && !ft_isalnum(line[i]) && line[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	ft_hrhr(char *line)
{
	int	flg;
	int	i;

	flg = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '=')
			flg = 1;
		i++;
	}
	if (!flg)
		return (0);
	return (1);
}
