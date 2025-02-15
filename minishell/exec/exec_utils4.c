/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:36:10 by mben-abb          #+#    #+#             */
/*   Updated: 2025/02/10 23:36:11 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_exit_status(int e_status)
{
	if (WIFEXITED(e_status))
		return (WEXITSTATUS(e_status));
	else if (WIFSIGNALED(e_status))
		return (128 + WTERMSIG(e_status));
	return (e_status);
}

int	ft_pipe_syscall(int fd[2], t_env *env)
{
	if (pipe(fd) == -1)
	{
		perror("Invalid file descriptor\n");
		ft_ques_dol(env, 1);
		return (-1);
	}
	return (0);
}

pid_t	ft_fork_syscall(t_env *env)
{
	pid_t	fok;

	fok = fork();
	if (fok == -1)
	{
		ft_ques_dol(env, 1);
		perror("eERROR in MInishell\n");
	}
	return (fok);
}

int	ft_pipline(int fd[2], int pipeline)
{
	if (pipeline != -1)
		close(pipeline);
	pipeline = dup(fd[0]);
	close(fd[1]);
	close(fd[0]);
	return (pipeline);
}

int	ft_hhh(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (*tmp->var == '?')
			return (ft_atoi(ft_strchr(tmp->var, '=') + 1));
		tmp = tmp->next;
	}
	return (0);
}
