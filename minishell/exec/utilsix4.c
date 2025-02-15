/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsix4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:36:59 by mben-abb          #+#    #+#             */
/*   Updated: 2025/02/10 23:37:00 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_envsize(t_env *env)
{
	int	i;

	i = 0;
	if (!env)
		return (0);
	while (env != NULL)
	{
		i++;
		env = env->next;
	}
	return (i);
}

char	**env_to_tab(t_env *env)
{
	t_env	*tmp;
	char	**str;
	int		i;

	i = 0;
	tmp = env;
	str = malloc((ft_envsize(env) + 1) * sizeof(char *));
	while (tmp)
	{
		str[i] = ft_strdup(tmp->var);
		i++;
		tmp = tmp->next;
	}
	str[i] = NULL;
	return (str);
}

void	ft_0_pipex(t_cmd *cmd, t_env *env, char *str)
{
	str = ft_check_builtins(cmd->cmd);
	if (ft_strchr(cmd->cmd, '/'))
	{
		if (!access(cmd->cmd, F_OK))
			execve(cmd->cmd, cmd->args, env_to_tab(env));
	}
	else if (str)
		bin_exec(cmd, env, str);
	else
		execve(cmd->path, cmd->args, env_to_tab(env));
}

void	signal_handlver(int k)
{
	(void)k;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
}

void	ft_check_helper_2(t_cmd *cmd, t_env *env, char *str)
{
	int	fd;
	int	fd1;

	fd = dup(1);
	fd1 = dup(0);
	handling_redir(cmd, env, str);
	bin_exec(cmd, env, str);
	dup2(fd, 1);
	dup2(fd1, 0);
}
