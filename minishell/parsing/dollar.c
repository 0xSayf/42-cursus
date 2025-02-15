/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:45:23 by sahamzao          #+#    #+#             */
/*   Updated: 2025/02/10 23:19:51 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_variable(char *str)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i])
	{
		ptr = malloc(i + 1);
		while (j < i)
		{
			ptr[j] = str[j];
			j++;
		}
		ptr[j] = '\0';
		return (ptr);
	}
	return (NULL);
}

char	*ft_search(char *string, t_env *env)
{
	int		status;
	t_env	*tmp;
	char	*str;

	tmp = env;
	while (tmp)
	{
		str = ft_variable(tmp->var);
		status = ft_strncmp(string, str, ft_strlen(str));
		if (!status)
		{
			if (!ft_strchr("\"' \0", string[ft_strlen(str)]))
				status = 500;
		}
		free(str);
		if (!status)
			return (ft_strchr(tmp->var, '='));
		tmp = tmp->next;
	}
	return (NULL);
}

char	*ft_save(char *ttt)
{
	char	*str;
	int		i;

	i = 0;
	if (!ttt)
		return (NULL);
	while (ttt[i] != '$')
		i++;
	str = malloc(i + 1);
	i = 0;
	while (ttt[i] != '$')
	{
		str[i] = ttt[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_dollar_help(t_token *tmp, t_env *env, char *save, char *sss)
{
	char	*ptr;
	char	*ttt;

	ptr = tmp->string;
	ttt = ft_strchr(ptr, '$');
	sss = ttt;
	if (ttt && ttt[1] && ttt[1] != ' ')
	{
		ttt = ft_search(&ttt[1], env);
		save = ft_save(ptr);
		if (ttt)
		{
			free(tmp->string);
			tmp->string = malloc(ft_strlen(ttt + 1) + ft_strlen(save) + 1);
			ttt = ft_strjoin(save, ttt + 1);
			ft_memcpy(tmp->string, ttt, ft_strlen(ttt));
			tmp->string[ft_strlen(ttt)] = '\0';
			free(save);
			free(ttt);
			tmp->string = ft_go_join(tmp, sss);
		}
		else
			tmp->string = tmp_string(tmp);
	}
}

t_token	*ft_expand_dollar(t_token *token, t_env *env)
{
	t_token	*tmp;
	char	*save;
	char	*sss;

	if (!token || !env)
		return (NULL);
	tmp = token;
	while (tmp)
	{
		if (tmp->string && tmp->typ_e != DELIM && tmp->qt == false)
			ft_dollar_help(tmp, env, save, sss);
		tmp = tmp->next;
	}
	return (token);
}
