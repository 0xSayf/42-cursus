/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:48:31 by sahamzao          #+#    #+#             */
/*   Updated: 2025/02/04 19:43:45 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*ft_initial_env(t_env *env, char **environment)
{
	int		i;
	t_env	*tmp;

	tmp = NULL;
	env = NULL;
	i = 0;
	if (!environment || !*environment)
		return (NULL);
	if (!env)
	{
		env = ft_creat_env(environment[0]);
		tmp = env;
		i++;
	}
	tmp = env;
	while (environment[i])
	{
		tmp->next = ft_creat_env(environment[i]);
		tmp = tmp->next;
		i++;
	}
	tmp->next = ft_creat_env("?=0");
	tmp = tmp->next;
	return (env);
}

char	atek(char *line, int *s, int *count)
{
	char	v;

	v = line[*s];
	(*count)++;
	(*s)++;
	return (v);
}

void	atek_2(int *len, int *s)
{
	(*len)++;
	(*s)++;
}
