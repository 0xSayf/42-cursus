/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:52:45 by sahamzao          #+#    #+#             */
/*   Updated: 2025/02/10 19:46:49 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_count_args(t_token *start, t_token *end)
{
	t_token	*tmp;
	int		i;

	if (!start)
		return (0);
	tmp = NULL;
	tmp = start;
	i = 0;
	while ((tmp) && (tmp->typ_e != PIPE) && (tmp->typ_e != HERDOC)
		&& (tmp->typ_e != APPEND_REDIRECT) && (tmp->typ_e != REDERECTION_INPUT)
		&& (tmp->typ_e != REDERECTION_OUTPUT))
	{
		if (tmp->typ_e != DELIM)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

t_cmd	*ft_file_hd(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	if (!cmd)
		return (NULL);
	i = 0;
	tmp = cmd;
	while (tmp)
	{
		tmp->file_hd = file_path(i);
		i++;
		tmp = tmp->next;
	}
	return (cmd);
}

t_cmd	*ft_build_nodes(t_token *token)
{
	t_token	*tmp;
	t_token	*start;
	t_token	*end;
	t_cmd	*cmd;
	t_cmd	*exec;

	cmd = NULL;
	tmp = token;
	if (!cmd)
	{
		start = token;
		end = find_pipe(token);
		cmd = creat_cmd_node(start, end);
		exec = cmd;
	}
	while (tmp && end && end->next)
	{
		start = end->next;
		tmp = end->next;
		end = find_pipe(tmp);
		exec->next = creat_cmd_node(start, end);
		exec = exec->next;
	}
	return (cmd);
}
