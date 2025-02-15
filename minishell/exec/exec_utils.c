/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:35:55 by mben-abb          #+#    #+#             */
/*   Updated: 2025/02/10 23:35:56 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	built_in_cmd(t_cmd *cmd, t_env *env, char *str)
{
	if (!ft_strcmp(str, "pwd"))
		ft_ques_dol(env, ft_pwd());
	else if (!ft_strcmp(str, "cd"))
		ft_ques_dol(env, ft_cd(env, cmd->args));
	else if (!ft_strcmp(str, "env"))
		ft_ques_dol(env, ft_env(env));
	else if (!ft_strcmp(str, "echo"))
		ft_ques_dol(env, ft_echo(cmd->args));
	else if (!ft_strcmp(str, "export"))
		ft_ques_dol(env, ft_export(cmd->args, env));
	else if (!ft_strcmp(str, "exit"))
		ft_exit(cmd->args);
	else if (!ft_strcmp(str, "unset"))
		ft_ques_dol(env, ft_unset(cmd->args, env));
}

void	bin_exec(t_cmd *cmd, t_env *env, char *str)
{
	built_in_cmd(cmd, env, str);
}

int	ft_check_dllar(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_find_var(char *str)
{
	char	*ptr;
	int		j;
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	ptr = malloc(i + 1);
	j = 0;
	while (j < i && str[j] && str[j] != '=')
	{
		ptr[j] = str[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	*ft_extract_var(char *line, int *i)
{
	char	*ptr;
	int		size;
	int		k;

	size = 0;
	while (line[size] && line[size] != 32 && line[size] != 39
		&& line[size] != 34)
		size++;
	ptr = malloc(size + 1);
	k = 0;
	while (k < size)
	{
		ptr[k] = line[k];
		k++;
	}
	ptr[k] = '\0';
	*i = size;
	return (ptr);
}
