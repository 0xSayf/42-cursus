/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:35:33 by mben-abb          #+#    #+#             */
/*   Updated: 2025/02/10 23:35:34 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_export_prime(char **arg, t_env *env, t_env *tmp, int i)
{
	if (!ft_check_exp(arg[i]))
	{
		printf("ERROR : the variable to export should be valid\n");
		return (-1);
	}
	else if (!ft_hrhr(arg[i]))
		printf("");
	else if (!finder(env, arg[i]))
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ft_creat_env(arg[i]);
		tmp = tmp->next;
	}
	else if (finder(env, arg[i]) && !find(env, arg[i]))
	{
		ft_go_del(&env, arg[i]);
		tmp = env;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ft_creat_env(arg[i]);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_export(char **arg, t_env *env)
{
	t_env	*tmp;
	int		i;
	int		c;
	int		flg;

	if (!arg || !env)
		return (1);
	i = 1;
	flg = 0;
	tmp = env;
	if (!arg[1])
		return (ft_env(env));
	while (arg[i])
	{
		c = ft_export_prime(arg, env, tmp, i);
		if (c == -1)
			flg = 1;
		i++;
	}
	if (flg)
		return (1);
	return (0);
}

void	ft_export_primez(char **arg, t_env *env, t_env *tmp, int i)
{
	if (!finder(env, arg[i]))
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ft_creat_env(arg[i]);
		tmp = tmp->next;
	}
	else if (finder(env, arg[i]) && !find(env, arg[i]))
	{
		ft_go_del(&env, arg[i]);
		tmp = env;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ft_creat_env(arg[i]);
		tmp = tmp->next;
	}
}

int	ft_exportix(char **arg, t_env *env)
{
	char	*str;
	t_env	*tmp;
	int		i;

	if (!arg || !env)
		return (1);
	tmp = env;
	ft_export_primez(arg, env, tmp, 0);
	return (0);
}
