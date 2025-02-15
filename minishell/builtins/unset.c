/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:35:45 by mben-abb          #+#    #+#             */
/*   Updated: 2025/02/10 23:35:46 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_frfree(char *str, char *ptr, t_env *ctr)
{
	free(str);
	free(ptr);
	free(ctr);
}

char	*tom(t_env **tmp, t_env **last, char *str)
{
	*last = *tmp;
	*tmp = (*tmp)->next;
	str = chch((*tmp)->var);
	return (str);
}

t_env	*ft_go_delixo(t_env **env, char *line, char *str)
{
	t_env	*tmp;
	t_env	*last;

	if (!env || !*env)
		return (NULL);
	tmp = *env;
	str = chch(tmp->var);
	if (!ft_strcmp(str, line))
	{
		*env = tmp->next;
		ft_frfree(str, tmp->var, tmp);
		return (*env);
	}
	while (tmp && tmp->next)
	{
		str = tom(&tmp, &last, str);
		if (!ft_strcmp(line, str))
		{
			last->next = tmp->next;
			ft_frfree(str, tmp->var, tmp);
			return (*env);
		}
		free(str);
	}
	return (*env);
}

int	ft_check_expix(char *line)
{
	int	i;

	i = 0;
	if (!ft_isalpha(line[i]) && line[i] != '_' && line[i] != '=')
		return (0);
	while (line[i])
	{
		if (line[i] == '=')
			return (0);
		if (!ft_isalnum(line[i]) && !ft_isalnum(line[i]) && line[i] != '_'
			&& line[i] != '=')
			return (0);
		i++;
	}
	return (1);
}

int	ft_unset(char **args, t_env *env)
{
	int		i;
	char	*str;

	if (!args || !env)
		return (1);
	i = 1;
	while (args[i])
	{
		if (!ft_check_expix(args[i]))
			printf("ERROR : the variable to unset should be valid\n");
		if (finder(env, args[i]) == 1)
			env = ft_go_delixo(&env, args[i], str);
		i++;
	}
	return (0);
}
