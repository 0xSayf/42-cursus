/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:36:15 by mben-abb          #+#    #+#             */
/*   Updated: 2025/02/10 23:36:16 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	execute_0_pipe(t_cmd *cmd, t_env *env, char *str)
{
	if (!cmd->redirection && !cmd->herdoc && !cmd->input)
		ft_0_pipex(cmd, env, str);
	else
	{
		if (handling_redir(cmd, env, str) == -1)
			return (-1);
		str = ft_check_builtins(cmd->cmd);
		if (ft_strchr(cmd->cmd, '/'))
		{
			if (!access(cmd->cmd, F_OK))
				execve(cmd->cmd, cmd->args, env_to_tab(env));
		}
		else if (str)
			bin_exec(cmd, env, str);
		else
			ft_exe0_help(cmd);
	}
	return (0);
}

void	is_the_child(t_cmd *cmd, int *pipeline, int fd[2], t_env *env)
{
	if (!ft_syntax_cmd(cmd))
	{
		printf(" command not  found\n");
		exit(1);
	}
	if (*pipeline != -1)
	{
		dup2(*pipeline, STDIN_FILENO);
		close(*pipeline);
	}
	if (cmd->next)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(fd[0]);
	}
	if (ft_strchr(cmd->cmd, '/'))
	{
		if (!access(cmd->cmd, F_OK))
			execve(cmd->cmd, cmd->args, env_to_tab(env));
	}
	else
		ft_bull_sht2(env, cmd);
}

void	ft_exec_0_pipe(t_cmd *cmd, t_env *env)
{
	char	*str;
	pid_t	fok;
	int		syn;

	str = ft_check_builtins(cmd->cmd);
	if (str)
	{
		ft_check_helper_2(cmd, env, str);
		return ;
	}
	syn = ft_syntax_cmd(cmd);
	if (!str && (!syn || syn == 2 || syn == 5))
	{
		ft_small_x(syn, env, cmd);
		return ;
	}
	signal(SIGINT, signal_handlver);
	fok = fork();
	ft_fork_helpix(fok, env, cmd, str);
}

void	ft_handle_multp_pipes(t_cmd *tmp, t_env *env)
{
	int		pipeline;
	pid_t	fok;
	char	*cc;
	int		fd[2];

	pipeline = -1;
	while (tmp)
	{
		if (ft_pipe_syscall(fd, env) == -1)
			return ;
		signal(SIGINT, signal_handlver);
		fok = ft_fork_syscall(env);
		if (fok == -1)
			return ;
		if (!fok)
			is_the_child(tmp, &pipeline, fd, env);
		else
			pipeline = ft_pipline(fd, pipeline);
		if (!(tmp->next))
			ft_waiit_hh(fok, env);
		tmp = tmp->next;
	}
	while (wait(NULL) > 0)
		;
}

void	ft_go_execute(t_cmd *cmd, t_env *env)
{
	t_cmd	*hh;
	t_cmd	*rep;
	t_cmd	*tmp;
	t_red	*red;

	if (!cmd)
		return ;
	hh = cmd;
	cmd = hd_handler(hh, env);
	red = cmd->redirection;
	while (red)
	{
		if (ft_openixoo_c(red, env) == -1)
			return ;
		red = red->next;
	}
	tmp = cmd;
	if (!tmp->pipe)
		ft_exec_0_pipe(tmp, env);
	else
		ft_handle_multp_pipes(tmp, env);
	ft_file_herd_unl(cmd);
}
