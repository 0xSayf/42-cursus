/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_manager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:36:19 by mben-abb          #+#    #+#             */
/*   Updated: 2025/02/10 23:36:20 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_savixx(char *line)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	while (line[i] && line[i] != '$')
		i++;
	ptr = malloc(i + 1);
	j = 0;
	while (j < i && line[j] && line[j] != '$')
	{
		ptr[j] = line[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	*ft_jeej(char *str, t_vrom *vrom, t_env *tmp, int *c)
{
	t_norm	norm;

	norm.k = 0;
	norm.i = 0;
	if (str[norm.i] == '$')
		vrom->ret = hisoka(vrom->save);
	else
	{
		norm.gg = ft_extract_var(str + norm.i, &norm.k);
		while (tmp)
		{
			norm.ptr = ft_find_var(tmp->var);
			if (norm.ptr && norm.gg && !ft_strcmp(norm.ptr, norm.gg))
			{
				ft_rvrvr(&norm, vrom, tmp);
				break ;
			}
			free(norm.ptr);
			tmp = tmp->next;
		}
		if (!tmp)
			ft_norm_rvr(&norm, vrom);
	}
	*c = *c + norm.k - 1;
	return (vrom->ret);
}

char	*ret_fil(char *save, char *ret)
{
	ret = ft_strcat(ret, save);
	free(save);
	return (ret);
}

char	*hh_hh_hh(t_vrom *vrom)
{
	char	*hh;

	hh = ft_strdup(vrom->ret);
	free(vrom->ret);
	free(vrom);
	return (hh);
}

char	*ft_expand_herdoc(char *str, t_env *env)
{
	t_vrom	*vrom;
	int		i;

	i = 0;
	if (!str || !env)
		return (NULL);
	if (!ft_check_dllar(str))
		return (NULL);
	vrom = malloc(sizeof(t_vrom));
	vrom->ret = NULL;
	while (str[i])
	{
		vrom->save = ft_savixx(&str[i]);
		while (str[i] && str[i] != '$')
			i++;
		if (str[i] == '$')
			vrom->ret = ft_jeej(&str[++i], vrom, env, &i);
		else
			vrom->ret = ret_fil(vrom->save, vrom->ret);
		i++;
	}
	return (hh_hh_hh(vrom));
}
