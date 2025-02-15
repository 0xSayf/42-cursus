/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:36:05 by mben-abb          #+#    #+#             */
/*   Updated: 2025/02/10 23:36:06 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_input_red_help(t_cmd *cmd, t_env *env)
{
	int	fd;

	while (cmd->input->next)
	{
		if (access(cmd->input->the_input_file, F_OK))
		{
			printf("NO FILE\n");
			ft_ques_dol(env, 1);
			exit(1);
		}
		if (access(cmd->input->the_input_file, R_OK))
			ft_close_env_2(env);
		fd = open(cmd->input->the_input_file, O_RDONLY, 0777);
		if (fd < 0)
		{
			ft_close_env(fd, env);
			return (-1);
		}
		cmd->input = cmd->input->next;
		close(fd);
	}
	return (0);
}

void	ft_openix(t_red *cmd, t_env *env)
{
	if (cmd->typix == REDERECTION_OUTPUT)
	{
		open(cmd->red_out, O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (access(cmd->red_out, R_OK))
		{
			printf("permisions denied\n");
			ft_ques_dol(env, 1);
			exit(1);
		}
	}
	else if (cmd->typix == APPEND_REDIRECT)
	{
		open(cmd->red_append, O_CREAT | O_RDWR | O_APPEND, 0777);
		if (access(cmd->red_append, R_OK))
		{
			printf("permisions denied\n");
			ft_ques_dol(env, 1);
			exit(1);
		}
	}
}

int	handling_redir(t_cmd *cmd, t_env *env, char *str)
{
	t_red	*red;

	if (cmd->input)
	{
		ft_input_red_help(cmd, env);
		if (in_redir(cmd, env, str) == -1)
		{
			ft_ques_dol(env, 1);
			return (-1);
		}
	}
	if (cmd->redirection != NULL)
	{
		red = cmd->redirection;
		while (red->next)
		{
			ft_openix(red, env);
			red = red->next;
		}
		if (cmd->redirection->typix == REDERECTION_OUTPUT)
			out_redir(cmd, env, str);
		else if (cmd->redirection->typix == APPEND_REDIRECT)
			app_redir(cmd, env, str);
	}
	return (0);
}

void	ft_file_herd_unl(t_cmd *cmd)
{
	t_cmd	*tmp;

	if (!cmd)
		return ;
	tmp = cmd;
	while (tmp)
	{
		unlink(tmp->file_hd);
		tmp = tmp->next;
	}
}
