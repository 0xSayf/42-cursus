/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_cmd_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:56:17 by sahamzao          #+#    #+#             */
/*   Updated: 2025/01/23 19:55:52 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_herdoc(t_herdoc **tmp)
{
	t_herdoc	*her;
	t_herdoc	*nex;

	if (!tmp)
		return ;
	her = *tmp;
	while (her)
	{
		nex = her->next;
		free(her->delimiter);
		free(her);
		her = nex;
	}
}

void	ft_free_input(t_input **tmp)
{
	t_input	*her;
	t_input	*nex;

	if (!tmp)
		return ;
	her = *tmp;
	while (her)
	{
		nex = her->next;
		free(her->the_input_file);
		free(her);
		her = nex;
	}
}

void	ft_free_redirection(t_red **red)
{
	t_red	*tmp;
	t_red	*nex;

	if (!red)
		return ;
	tmp = *red;
	while (tmp)
	{
		nex = tmp->next;
		if (tmp->red_append)
			free(tmp->red_append);
		else if (tmp->red_out)
			free(tmp->red_out);
		free(tmp);
		tmp = nex;
	}
}

void	ft_freeing_cmd_node(t_cmd **cmd)
{
	t_cmd	*tmp;
	t_cmd	*nex;

	if (!cmd)
		return ;
	tmp = *cmd;
	while (tmp)
	{
		nex = tmp->next;
		if (tmp->herdoc)
			ft_free_herdoc(&tmp->herdoc);
		if (tmp->redirection)
			ft_free_redirection(&tmp->redirection);
		if (tmp->input)
			ft_free_input(&tmp->input);
		freeing(tmp->args);
		free(tmp->file_hd);
		free(tmp->path);
		free(tmp->cmd);
		free(tmp);
		tmp = nex;
	}
}
