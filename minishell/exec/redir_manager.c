/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:36:27 by mben-abb          #+#    #+#             */
/*   Updated: 2025/02/10 23:36:28 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_hd_handler_helper(t_cmd *cmd)
{
	t_herdoc	*tmp;

	if (!cmd->input)
		cmd->input = ft_input(cmd->file_hd);
	else if (cmd->input)
	{
		tmp = cmd->herdoc;
		while (tmp->next)
			tmp = tmp->next;
		if (tmp->last == true)
		{
			while (cmd->input->next)
				cmd->input = cmd->input->next;
			cmd->input->next = ft_input(cmd->file_hd);
		}
	}
}

int	ft_cond_help(char *str, t_herdoc **tmp)
{
	if (!(*tmp)->next)
	{
		free(str);
		return (-1);
	}
	else
		(*tmp) = (*tmp)->next;
	return (0);
}

void	ft_put_helper_hd(t_herdoc *tmp, char *str, int fd, t_env *env)
{
	char	*ret;

	if (tmp->qt == false)
	{
		ret = ft_expand_herdoc(str, env);
		if (!ret)
			ft_putstr_fd(str, fd);
		else
		{
			ft_putstr_fd(ret, fd);
			free(ret);
		}
	}
	else
		ft_putstr_fd(str, fd);
	ft_putstr_fd("\n", fd);
}

int	ft_infinite_loop(t_herdoc **tmp, int fd, t_env *env)
{
	char	*line_readed;

	line_readed = readline("HERDOC>  ");
	if (!ft_strcmp((*tmp)->delimiter, line_readed))
	{
		if (ft_cond_help(line_readed, tmp) == -1)
			return (-1);
	}
	else if (ft_strcmp((*tmp)->delimiter, line_readed) && !(*tmp)->next)
		ft_put_helper_hd(*tmp, line_readed, fd, env);
	free(line_readed);
	return (0);
}

t_cmd	*hd_handler(t_cmd *cmd, t_env *env)
{
	t_herdoc	*tmp;
	t_cmd		*hh;
	t_input		*input;
	int			fd;

	hh = cmd;
	while (cmd)
	{
		tmp = cmd->herdoc;
		while (tmp)
		{
			fd = open(cmd->file_hd, O_CREAT | O_RDWR | O_APPEND, 0777);
			while (1)
			{
				if (ft_infinite_loop(&tmp, fd, env) == -1)
					break ;
			}
			tmp = tmp->next;
			close(fd);
		}
		if (cmd->herdoc)
			ft_hd_handler_helper(cmd);
		cmd = cmd->next;
	}
	return (hh);
}
