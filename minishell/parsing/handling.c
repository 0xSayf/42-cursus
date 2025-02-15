/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:55:51 by sahamzao          #+#    #+#             */
/*   Updated: 2025/01/26 20:24:55 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_red	*ft_check_redirection(t_cmd *cmd, t_token *token)
{
	t_red	*red;
	t_red	*help;

	if (!cmd || !token)
		return (NULL);
	red = cmd->redirection;
	while (token && token->typ_e != PIPE)
	{
		if (token->typ_e >= REDERECTION_OUTPUT
			&& token->typ_e <= APPEND_REDIRECT)
		{
			if (!red)
			{
				red = ft_cr_redir_node(token->next, token->typ_e);
				help = red;
			}
			else
			{
				help->next = ft_cr_redir_node(token->next, token->typ_e);
				help = help->next;
			}
		}
		token = token->next;
	}
	return (red);
}

void	*ft_handle_p_h_a_re(t_cmd *cmd, t_token *tmp)
{
	t_cmd	*sat;
	t_token	*yes;

	if (!cmd || !tmp)
		return (NULL);
	yes = tmp;
	sat = cmd;
	while (yes && sat)
	{
		sat->redirection = ft_check_redirection(sat, yes);
		sat = sat->next;
		yes = find_pipe(yes);
		if (yes && yes->next)
			yes = yes->next;
	}
	return (cmd);
}

t_input	*ft_check_input(t_cmd *cmd, t_token *token)
{
	t_input	*red;
	t_input	*help;

	if (!cmd || !token)
		return (NULL);
	red = cmd->input;
	while (token && token->typ_e != PIPE)
	{
		if (token->typ_e == REDERECTION_INPUT)
		{
			if (!red)
			{
				red = ft_cr_input(token->next);
				help = red;
			}
			else
			{
				help->next = ft_cr_input(token->next);
				help = help->next;
			}
		}
		token = token->next;
	}
	return (red);
}

void	*ft_handle_input(t_cmd *cmd, t_token *tmp)
{
	t_cmd	*sat;
	t_token	*yes;

	if (!cmd || !tmp)
		return (NULL);
	yes = tmp;
	sat = cmd;
	while (yes && sat)
	{
		sat->input = ft_check_input(sat, yes);
		sat = sat->next;
		yes = find_pipe(yes);
		if (yes && yes->next)
			yes = yes->next;
	}
	return (cmd);
}
